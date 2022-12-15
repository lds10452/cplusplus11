#include "ThreadPool.hpp"

int main()
{
	ThreadPool pool(3);
	thread t1([&pool] {
		for (int i = 0; i < 10; i++)
		{
			auto id = this_thread::get_id();
			pool.AddTask([id] {
				cout << "ͬ�����߳�1���߳�ID��" << id << endl;
				});
		}
		});
	thread t2([&pool] {
		for (int i = 0; i < 10; i++)
		{
			auto id = this_thread::get_id();
			pool.AddTask([id] {
				cout << "ͬ�����߳�2���߳�ID��" << id << endl;
				});
		}
		});
	this_thread::sleep_for(chrono::seconds(2));
	pool.Stop();
	t1.join();
	t2.join();

	system("pause");
	return 0;
}