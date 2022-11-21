#include "test.h"
#include <functional>
void fun1()
{
	cout << "����ָ��call" << endl;
}
class book
{
public:
	void operator()() { cout << "�º���call" << endl; }
};
class book1
{
	using pFun = void(*)(void);
public:
	static void fun2() { cout << "�ɱ�ת��Ϊ����ָ��������call" << endl; }
	operator pFun() { return fun2; }
};
class book2
{
public:
	int a;
	void fun3() { cout << "���Ա��������ָ��call" << endl; }
};

void test1()
{
	void (*fun4)(void) = &fun1;	//����ָ��
	fun4();
	book b;						//�º���
	b();
	book1 b1;					//�ɱ�ת��Ϊ����ָ��������
	b1();
	void (book2:: * mem_func)() = &book2::fun3;	//���Ա����ָ��
	int book2::* mem_obj = &book2::a;	//���Աָ��
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