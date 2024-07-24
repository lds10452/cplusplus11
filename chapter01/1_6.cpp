#include "test.h"
#include <vector>
int g_a = 100;
class B
{
	int a;
	void func(int x,int y)
	{
		auto x1 = [=] {return a + x + y; };
		//auto x1 = [] {return a; };			//error
		//auto x2 = [this] {return a + x + y; };//error
		auto x3 = [this] {return a++; };
		auto x4 = [&] {return a++; };
		//auto x5 = [=] {return x++; };	//error,x为const
		auto x5 = [=]()mutable {return x++; };
		auto x6 = [=, &x] {return y + (x++); };
		//auto x7 = [g_a] {};//error,无法捕获静态存储的变量
		auto ff = [=] {return g_a; };//ok
	}
};
void test1_6()
{
	//auto f2 = [g_a]()->int {return ++g_a; };//error,无法捕获静态存储的变量
	auto f2 = [&]()->int {return ++g_a; };//ok

	auto ff = [=]()->int {return g_a; };//ok
	//auto ff = [=] {return g_a; };//ok,省略返回类型
	cout << ff() << endl;

	//auto f = []() {return{ 1,2 }; };//返回初始化列表时不能省略返回类型
	auto f = []()->vector<int> {return{ 1,2 }; };
	for(auto t:f())
		cout << t << endl;
}