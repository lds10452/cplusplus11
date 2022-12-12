#include "test.h"
#include <future>
#include <Windows.h>
const char* s[] = { "ready","timeout","deferred" };
void test5_7()
{
	future<int> f1 = async(launch::async,
		[](int s) {cout << "async......" << endl; return s; }, 7);
	Sleep(1000);
	cout << "async:" << f1.get() << endl;

	future<string> f2 = async(launch::deferred,
		[](string s) {cout << "deferred......" << endl; return s; }, "aaa");
	Sleep(1000);
	//f2.wait();
	future_status status = f2.wait_for(chrono::milliseconds(1));
	cout << "��ǰ״̬Ϊ:" << s[((int)status)] << endl;
	cout << "deferred:" << f2.get() << endl;

	future<int> f3 = async(launch::async, [](int s)
		{this_thread::sleep_for(chrono::seconds(3)); return s; }, 12);
	cout << "start:" << endl;
	do
	{
		status = f3.wait_for(chrono::seconds(1));
		if (status == future_status::deferred)
		{
			cout << "status is deferred." << endl;
		}
		else if (status == future_status::ready)
		{
			cout << "status is ready." << endl;
		}
		else if (status == future_status::timeout)
		{
			cout << "status is timeout" << endl;
		}
	} while (status != future_status::ready);
	cout << "result is " << f3.get() << endl;
}