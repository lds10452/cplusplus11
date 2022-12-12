#include "test.h"
#include <future>

void test5_6()
{
	promise<int> pr;
	thread t([](promise<int>& p) {
		p.set_value_at_thread_exit(9);
		}, ref(pr));
	future<int> f = pr.get_future();
	auto r = f.get();
	cout << r << endl;//9
	t.join();

	packaged_task<int()> task([] {return 7; });
	future<int> f1 = task.get_future();
	//thread t1(ref(task));
	thread(move(task)).detach();
	auto r1 = f1.get();
	cout << r1 << endl;//7
	//t1.join();

	vector<shared_future<int>> v;
	shared_future<int> f2 = async(launch::async, [](int a, int b) {return a + b; }, 2, 3);
	v.push_back(f2);
	cout << "shared_future get value:" << v[0].get() << endl;//5
}