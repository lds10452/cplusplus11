#include "test.h"
#include <list>

class DT
{
public:
	static const int number = 0;
	int x;
};

int&& func_int_rr();
const int& func_cint_r();
const int func_cint();
const DT func_cdt();

template <class T>
class Container
{
public:
	void func(T& c)
	{
		for (m_it = c.begin(); m_it != c.end(); ++m_it)
		{
			cout << *m_it << " ";
		}
		cout << endl;
	}
private:
//	T::iterator m_it;  //error 这里不能确定迭代器类型
	decltype(T().begin()) m_it;//ok
};

void test1_1Decltype()
{
	int x = 0;
	const int& i = x;
	decltype(i)j = x;	//j->const int&,可以保留引用&、指针*和cv限定符
	decltype(DT::number) c = 0;	//c->const int
	decltype(DT().x) d = 0;	//d->int,类访问表达式

	//函数调用
	decltype(func_int_rr()) e1 = 0;//e1->int&&
	decltype(func_cint_r()) a1 = x;	//a1->const int&
	decltype(func_cint()) b1 = 0;	//b1->int,纯右值只有类类型才携带cv，否则忽略掉
	decltype(func_cdt()) c1 = DT();	//c1->const DT

	const DT dd = DT();
	decltype(dd.x) a = 0;	//a->int
	decltype((dd.x)) b = a;	//b->const int&,因为dd类型是const
	int n = 0, m = 0;
	decltype(n + m) e = 0;//e->int
	decltype(n += m) r = n;	//r->int&

	list<int> lst{ 1,2,3,4,5,6,7,8,9 };;
	Container<list<int>> obj;
	obj.func(lst);
	const list<int> lst1{ 1,2,3,4,5,6,7,8,9 };
	Container<const list<int>> obj1;
	obj1.func(lst1);
}