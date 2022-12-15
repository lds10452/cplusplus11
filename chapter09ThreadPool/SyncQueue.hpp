#pragma once
#include "test.h"
#include <list>
#include <mutex>
#include <thread>
#include <condition_variable>

template<class T>
class SyncQueue
{
	unsigned int m_nMaxSize;
	bool m_bStop;
	list<T> m_queue;
	mutex m_Mutex;
	condition_variable m_NotFull;
	condition_variable m_NotEmpty;
public:
	SyncQueue(int maxSize):m_nMaxSize(maxSize),m_bStop(false){}
	template<typename F>
	void Add(F&& x)
	{
		unique_lock<mutex> locker(m_Mutex);
		m_NotFull.wait(locker, [this] {return m_bStop || NotFull(); });//同为false阻塞休眠
		if (m_bStop)
			return;
		m_queue.push_back(forward<F>(x));
		m_NotEmpty.notify_one();
	}
	void Put(const T& x)
	{
		Add(x);
	}
	void Put(T&& x)
	{
		Add(forward<T>(x));
	}
	void Take(list<T>& list)
	{
		unique_lock<mutex> locker(m_Mutex);
		m_NotEmpty.wait(locker, [this] {return m_bStop || NotEmpty(); });
		if (m_bStop)
			return;
		list = move(m_queue);//作为右值传入，转移队列任务控制权
		m_NotFull.notify_one();
	}
	void Take(T& t)
	{
		unique_lock<mutex> locker(m_Mutex);
		m_NotEmpty.wait(locker, [this] {return m_bStop || NotEmpty(); });
		if (m_bStop)
			return;
		t = m_queue.front();
		m_queue.pop_front();
		m_NotFull.notify_one();
	}
	bool NotFull()const
	{
		bool full = m_queue.size() >= m_nMaxSize;
		if (full)
			cout << "缓冲区已经满了。。。" << endl;
		return !full;
	}
	bool NotEmpty()
	{
		bool empty = m_queue.empty();
		if (empty)
			cout << "缓冲区空了" << endl;
		return !empty;
	}
	void Stop()
	{
		{
			unique_lock<mutex> locker(m_Mutex);
			m_bStop = true;
		}
		m_NotEmpty.notify_all();
		m_NotFull.notify_all();
	}
	bool Empty(){}
	bool Full(){}
	size_t Size(){}
	int Count(){}
};