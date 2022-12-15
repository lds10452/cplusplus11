#pragma once
#include "test.h"
#include "SyncQueue.hpp"
#include <functional>
#include <list>

const int maxTaskCount = 100;//设置任务上限，避免无休止添加任务
class ThreadPool
{
	using Task = function<void()>;
	SyncQueue<Task> m_queue;
	bool m_bRun;
	list<shared_ptr<thread>> m_listThread;
	once_flag m_flag;
public:
	ThreadPool(int num = thread::hardware_concurrency()) :m_queue(maxTaskCount)//创建cpu核数的线程达到最优的效率
	{
		Start(num);
	}
	~ThreadPool()
	{
		Stop();
	}
	void AddTask(const Task& task)
	{
		m_queue.Put(task);
	}
	void AddTask(Task&& task)
	{
		m_queue.Put(forward<Task>(task));
	}
	void Start(int num)
	{
		m_bRun = true;
		for (int i = 0; i < num; i++)
		{
			m_listThread.push_back(
				make_shared<thread>(&ThreadPool::RunThread, this));
		}
	}
	void RunThread()
	{
		while (m_bRun)
		{
			list<Task> list;
			m_queue.Take(list);
			for (auto& task : list)
			{
				if (!m_bRun)
					return;
				cout << "异步线程ID:" << this_thread::get_id() << endl;
				task();
			}
		}
	}
	void Stop()
	{
		call_once(m_flag, [this] {StopThread(); });
	}
	void StopThread()
	{
		m_queue.Stop();
		m_bRun = false;
		for (auto thread : m_listThread)
		{
			if (thread)
				thread->join();
		}
		m_listThread.clear();
	}
};
