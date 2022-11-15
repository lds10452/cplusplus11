#include "test.h"

//void func(auto a=1){}	//error:auto不能用于函数参数
class Foo
{
	//auto var1 = 0;	//error:auto不能用于非静态成员变量
	static const auto var2 = 0;
public:
	static int get() { return 0; }
};

template<class T>
class Bar
{
public:
	static const char* get() { return "0"; }
};

template<typename T>
void func()
{
	auto val = T::get();
}

void test1_1Auto()
{
	//auto int r;	//error:auto不再表示存储类型指示符
	//auto s;		//error：无法推导出s的类型

	int x = 0;
	auto& c = x;
	auto d = c;	//d->int,会把引用&抛弃
	const auto e = x;
	auto f = e;	//f->int,会把const抛弃
	const auto& g = x;
	auto& h = g;	//h->const int&,引用和const结合时，保留const

	//auto arr[10] = { 0 };	//error:无法定义数组
	//Bar<auto> bb = Bar<int>();	//error:无法通过拷贝构造推导出模板参数

	func<Foo>();
	func<Bar<int>>();
}

