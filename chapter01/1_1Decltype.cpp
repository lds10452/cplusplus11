#include "test.h"

class DT
{
public:
	static const int number = 0;
	int x;
};

const int& func_cint_r();
const int func_cint();
const DT func_cdt();

void test1_1Decltype()
{
	int x = 0;
	const int& i = x;
	decltype(i)j = x;	//j->const int&,���Ա�������&��ָ��*��cv�޶���
	decltype(DT::number) c = 0;	//c->const int
	decltype(DT().x) d = 0;	//d->int,����ʱ��ʽ

	//��������
	decltype(func_cint_r()) a1 = x;	//a1->const int&
	decltype(func_cint()) b1 = 0;	//b1->int,����ֵֻ�������Ͳ�Я��cv��������Ե�
	decltype(func_cdt()) c1 = DT();	//c1->const DT

	const DT dd = DT();
	decltype(dd.x) a = 0;	//a->int
	decltype((dd.x)) b = a;	//b->const int&,��Ϊdd������const
	int n = 0, m = 0;
	decltype(n += m) r = n;	//r->int&
}