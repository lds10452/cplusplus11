#include "test.h"
#include <thread>
#include <mutex>
once_flag flag;
void do_once()
{
	cout << "start" << endl;
	call_once(flag, []() {cout << "called once" << endl; });
	cout << "end" << endl;
}
void test5_5()
{
	thread t1(do_once);
	thread t2(do_once);
	thread t3(do_once);
	t1.join();
	t2.join();
	t3.join();
}