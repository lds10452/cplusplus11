#include "test.h"
#include <thread>
#include <list>
#include <mutex>
#include <condition_variable>
template<typename T>
class SimpleSyncQueue
{
public:
	void Put(const T& x)
	{
		this_thread::sleep_for(chrono::milliseconds(50));
		lock_guard<mutex> locker(m_mutex);
		cout << "װ�����ݡ�����" << endl;
		m_queue.push_back(x);
		m_notEmpty.notify_one();
	}
	void Take(T& x)
	{
		/*lock_guard<mutex> locker(m_mutex);
		while (m_queue.empty())
		{
			m_notEmpty.wait(m_mutex);
		}*/
		unique_lock<mutex> uniqueLock(m_mutex);//��ͬ��һ����
		m_notEmpty.wait(uniqueLock, [this] {return !m_queue.empty(); });//����2Ϊ����ִ�е�����
		x = m_queue.front();
		cout << "ȡ���ݡ�����" << x << endl;
		m_queue.pop_front();
	}

private:
	std::list<T> m_queue;                  //������
	std::mutex m_mutex;                    //�����������������������ʹ��
	//std::condition_variable_any m_notEmpty;//��Ϊ�յ���������
	condition_variable m_notEmpty;
};
SimpleSyncQueue<int> syncQueue;//
void PutDatas()
{
	for (int i = 0; i < 20; ++i)
	{
		syncQueue.Put(888);
	}
}

void TakeDatas()
{
	int x = 0;

	for (int i = 0; i < 20; ++i)
	{
		syncQueue.Take(x);
	}
}
void test5_3()
{
	std::thread t1(PutDatas);
	std::thread t2(TakeDatas);

	t1.join();
	t2.join();
}