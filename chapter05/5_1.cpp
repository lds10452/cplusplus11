#include "test.h"
#include <thread>
#include <functional>
#include <vector>
vector<thread> g_vecList;
vector<shared_ptr<thread>> g_vecList2;
void func(int i, double b, const string& s)
{
	cout << i << " " << b << " " << s << endl;
}
void delayFunc()
{
	this_thread::sleep_for(chrono::seconds(3));
	cout << "time out" << endl;
}
void createThread()
{
	thread t(func, 11, 22, "vec");
	g_vecList.push_back(move(t));
	g_vecList2.push_back(make_shared<thread>(func, 44, 55, "shared_ptr"));
}
void test5_1()
{
	std::thread t(func, 1, 2, "test");
	//t.join();//线程阻塞
	//t.detach();//线程分离

	std::thread t1(std::move(t));
	t1.join();

	thread t2(bind(func, 3, 4, "bind"));
	thread t3([](int a, int b) {cout << a << " " << b << endl; }, 5, 6);
	t2.join();
	t3.join();

	cout << thread::hardware_concurrency() << endl;//12
	createThread();
	for (auto& tt : g_vecList)
	{
		cout << "join pre id:" << tt.get_id() << endl;//21644
		tt.join();
		cout << "join after id:" << tt.get_id() << endl;//0
	}
	for (auto& tt : g_vecList2)
	{
		tt->join();
	}

	thread t4(delayFunc);//3s后打印
	t4.join();
}
