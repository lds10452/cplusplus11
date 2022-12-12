#include "test.h"
#include <mutex>
class Counter
{
	int value;
	mutex m_mutex;
public:
	void increment()
	{
		this_thread::sleep_for(chrono::milliseconds(10));
		lock_guard<mutex> locker(m_mutex);
		value++;
		cout << "increment:" << value << endl;
	}
	void decrement()
	{
		this_thread::sleep_for(chrono::milliseconds(10));
		lock_guard<mutex> locker(m_mutex);
		value--;
		cout << "decrement:" << value << endl;
	}
	int get()
	{
		return value;
	}
};
class AtomicCounter
{
	atomic<int> value;
public:
	void increment()
	{
		++value;
		cout << "increment:" << get() << endl;
	}
	void decrement()
	{
		--value;
		cout << "decrement:" << get() << endl;
	}
	int get()
	{
		return value.load();
	}
};
//Counter counter;
AtomicCounter counter;
void incNum()
{
	while (true)
	{
		counter.increment();
	}
}
void decNum()
{
	while (true)
	{
		counter.decrement();
	}
}
void test5_4()
{
	thread t1(incNum);
	thread t2(decNum);
	t1.join();
	t2.join();
}