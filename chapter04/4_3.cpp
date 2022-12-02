#include "test.h"
class A :public enable_shared_from_this<A>
{
public:
	shared_ptr<A> GetSelf()
	{
		//return shared_ptr<A>(this);//error,重复释放,两次
		return shared_from_this();//一次A is deleted
	}
	~A()
	{
		cout << "A is deleted" << endl;
	}
};
class B;
class C;
class B
{
public:
	shared_ptr<C> bptr;
	~B() { cout << "B is delete!" << endl; }
};
class C
{
public:
	//shared_ptr<B> bptr;//error,无法释放资源
	weak_ptr<B> bptr;
	~C() { cout << "C is delete!" << endl; }
};
void test4_3()
{
	shared_ptr<int> p1(new int(10));
	weak_ptr<int> p2(p1);
	shared_ptr<int> p3 = p1;
	cout << p2.use_count() << endl;//2，返回p1的引用计数
	if (p2.expired())//判断所观测的资源是否已经被释放
		cout << "无效，已被释放" << endl;
	else
		cout << "有效" << endl;//
	cout << *p2.lock() << endl;//10，获取监测资源的值

	shared_ptr<A> p4(new A);
	shared_ptr<A> p5 = p4->GetSelf();

	{
		shared_ptr<B> bp(new B);
		shared_ptr<C> cp(new C);
		bp->bptr = cp;
		cp->bptr = bp;
	}
}