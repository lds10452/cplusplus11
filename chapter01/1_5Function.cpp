#include "test.h"
#include <functional>
void fun1()
{
	cout << "函数指针call" << endl;
}
class book
{
public:
	void operator()() { cout << "仿函数call" << endl; }
};
class book1
{
	using pFun = void(*)(void);
public:
	static void fun2() { cout << "可被转换为函数指针的类对象call" << endl; }
	operator pFun() { return fun2; }
};
class book2
{
public:
	int a;
	void fun3() { cout << "类成员（函数）指针call" << endl; }
};

void test1()
{
	void (*fun4)(void) = &fun1;	//函数指针
	fun4();
	book b;						//仿函数
	b();
	book1 b1;					//可被转换为函数指针的类对象
	b1();
	void (book2:: * mem_func)() = &book2::fun3;	//类成员函数指针
	int book2::* mem_obj = &book2::a;	//类成员指针
	book2 b2;
	(b2.*mem_func)();
	b2.*mem_obj = 123;
}
void test2()
{
	function<void(void)> fc1 = fun1;
	fc1();
	fc1 = book1::fun2;
	fc1();
	book b;
	fc1 = b;
	fc1();
}
class book3
{
	function<void()> callback;
public:
	book3(const function<void()>&f):callback(f){}
	void notify() { callback(); }
};
void test3()
{
	book3 b(fun1);
	b.notify();
}
void test1_5Function()
{
	//test1();
	//test2();
	test3();
}