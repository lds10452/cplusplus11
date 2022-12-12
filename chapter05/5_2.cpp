#include "test.h"
#include <thread>
#include <mutex>
mutex g_lock;
void mutexLock()
{
	g_lock.lock();
	cout << "entered thread " << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "leaving thread " << this_thread::get_id() << endl;
	g_lock.unlock();
}
void lockGuard()
{
	lock_guard<mutex> locker(g_lock);
	cout << "entered thread " << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "leaving thread " << this_thread::get_id() << endl;
}
void test5_2_1()
{
	thread t1(mutexLock);
	thread t2(lockGuard);
	t1.join();
	t2.join();
}
class Complex
{
	//mutex m_mutex;//会发生死锁
	recursive_mutex m_mutex;
	int i;
public:
	Complex():i(0){}
	void mul(int x)
	{
		cout << "mul lock" << endl;
		//lock_guard<mutex> locker(m_mutex);
		lock_guard<recursive_mutex> locker(m_mutex);
		i *= x;
	}
	void div(int x)
	{
		cout << "div lock" << endl;
		//lock_guard<mutex> locker(m_mutex);
		lock_guard<recursive_mutex> locker(m_mutex);
		i /= x;
	}
	void both(int x, int y)
	{
		cout << "both lock" << endl;
		//lock_guard<mutex> locker(m_mutex);
		lock_guard<recursive_mutex> locker(m_mutex);
		mul(x);//mutex无法获取再次获取同一互斥量所有权,可使用recursive_mutex
		div(y);
	}
};
void test5_2_2()
{
	Complex c;
	c.both(33, 44);
}
timed_mutex g_timeLock;
void timedMutex()
{
	chrono::milliseconds timeout(100);
	while (true)
	{
		if (g_timeLock.try_lock_for(timeout))
		{
			cout << this_thread::get_id() << " get lock" << endl;
			this_thread::sleep_for(chrono::milliseconds(250));
			g_timeLock.unlock();
			this_thread::sleep_for(chrono::milliseconds(250));
		}
		else
		{
			cout << this_thread::get_id() << " not lock" << endl;
			this_thread::sleep_for(timeout);
		}
	}
}
void test5_2_3()
{
	thread t1(timedMutex);
	thread t2(timedMutex);
	t1.join();
	t2.join();
}
void test5_2()
{
	test5_2_1();
	test5_2_2();
	test5_2_3();
}