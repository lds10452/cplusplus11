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
	//构造
	shared_ptr<int> sp(new int);
	weak_ptr<int> wp1;//默认构造
	weak_ptr<int> wp2(wp1);//拷贝构造
	weak_ptr<int> wp3(sp);//有参构造
	//赋值
	weak_ptr<int> wp4;
	wp4 = sp;
	weak_ptr<int> wp5;
	wp5 = wp3;

	cout << "wp1: " << wp1.use_count() << endl;//0
	cout << "wp2: " << wp2.use_count() << endl;//0
	cout << "wp3: " << wp3.use_count() << endl;//1
	cout << "wp4: " << wp4.use_count() << endl;//1
	cout << "wp5: " << wp5.use_count() << endl;//1

	cout << endl;
	cout << "1. weak " << (wp3.expired() ? "is" : "is not") << " expired" << endl;// is not
	sp.reset();
	cout << "2. weak " << (wp3.expired() ? "is" : "is not") << " expired" << endl;//is

	cout << endl;
	sp.reset(new int(255));
	wp3 = sp;
	shared_ptr<int> sp1 = wp3.lock();
	cout << "use_count: " << wp3.use_count() << endl;//2
	sp.reset();
	cout << "use_count: " << wp3.use_count() << endl;//1
	sp = wp3.lock();
	cout << "use_count: " << wp3.use_count() << endl;//2
	cout << "*sp: " << *sp << endl;//255
	cout << "*sp1: " << *sp1 << endl;//255

	cout << endl;
	cout << "1. wp " << (wp3.expired() ? "is" : "is not") << " expired" << endl;//is not
	wp3.reset();
	cout << "2. wp " << (wp3.expired() ? "is" : "is not") << " expired" << endl;//is

	cout << endl;
	shared_ptr<A> p4(new A);
	shared_ptr<A> p5 = p4->GetSelf();

	{
		shared_ptr<B> bp(new B);
		shared_ptr<C> cp(new C);
		bp->bptr = cp;
		cp->bptr = bp;
	}
}