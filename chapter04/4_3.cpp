#include "test.h"
class A :public enable_shared_from_this<A>
{
public:
	shared_ptr<A> GetSelf()
	{
		//return shared_ptr<A>(this);//error,�ظ��ͷ�,����
		return shared_from_this();//һ��A is deleted
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
	//shared_ptr<B> bptr;//error,�޷��ͷ���Դ
	weak_ptr<B> bptr;
	~C() { cout << "C is delete!" << endl; }
};
void test4_3()
{
	shared_ptr<int> p1(new int(10));
	weak_ptr<int> p2(p1);
	shared_ptr<int> p3 = p1;
	cout << p2.use_count() << endl;//2������p1�����ü���
	if (p2.expired())//�ж����۲����Դ�Ƿ��Ѿ����ͷ�
		cout << "��Ч���ѱ��ͷ�" << endl;
	else
		cout << "��Ч" << endl;//
	cout << *p2.lock() << endl;//10����ȡ�����Դ��ֵ

	shared_ptr<A> p4(new A);
	shared_ptr<A> p5 = p4->GetSelf();

	{
		shared_ptr<B> bp(new B);
		shared_ptr<C> cp(new C);
		bp->bptr = cp;
		cp->bptr = bp;
	}
}