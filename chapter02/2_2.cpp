#include "test.h"

void test2_2()
{
	int b = 0;
	int& a = b;
	int&& c = int();
	cout << &a << " " << &c << endl;

	shared_ptr<int> p(new int(10));
	shared_ptr<int> pp = move(p);//pp�ڲ�ԭָ��ָ������10�Ǹ��ѿռ�
	if (p.get() != NULL)
		cout << "p is not null" << endl;
	else
		cout << "p is null" << endl;//p�ڲ�ԭָ�뽫���NULL
}