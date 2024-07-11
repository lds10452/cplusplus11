#include "test.h"
#include <map>

//void func(auto a=1){}	//error:auto不能用于函数参数
class Foo
{
	//auto var1 = 0;	//error:auto不能用于非静态成员变量
	//static auto v2 = 0;             // error,类的静态非常量成员不允许在类内部直接初始化
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
	cout << val << endl;
}
//等价于上面写法
template <class A, typename B>        // 添加了模板参数 B
void func(void)
{
	B val = A::get();
	cout << "val: " << val << endl;
}

void test1_1Auto()
{
	//auto int r;	//error:auto不再表示存储类型指示符
	//auto s;		//error：无法推导出s的类型

	int x = 0;
	auto& c = x;//c->int&
	auto d = c;	//d->int,会把引用&抛弃
	const auto e = x;//e->const int
	auto f = e;	//f->int,会把const抛弃
	const auto& g = x;//g->const int &
	auto& h = g;	//h->const int&,引用和const结合时，保留const

	int array[] = { 1,2,3,4,5 };  
	auto t1 = array;            // ok, t1被推导为 int* 类型
	//auto arr[10] = { 0 };	//error:无法定义数组
	//Bar<auto> bb = Bar<int>();	//error:无法通过拷贝构造推导出模板参数

	map<int, string> person;
//	map<int, string>::iterator it = person.begin();
	auto it = person.begin();//等价于上面
	for (; it != person.end(); ++it)
	{
		// do something
	}

	func<Foo>();
	func<Bar<int>>();
	func<Foo, int>();                  // 手动指定返回值类型 -> int
	func<Bar<int>, string>();               // 手动指定返回值类型 -> string
}

