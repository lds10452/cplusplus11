#include "test.h"
#include <vector>

void test2_2()
{
	int b = 0;
	int& a = b;
	int&& c = int();
	cout << &a << " " << &c << endl;

	shared_ptr<int> p(new int(10));
	shared_ptr<int> pp = move(p);//pp内部原指针指向数据10那个堆空间
	if (p.get() != NULL)
		cout << "p is not null" << endl;
	else
		cout << "p is null" << endl;//p内部原指针将变成NULL

	vector<int> pVec;
	pVec.push_back(10);
	pVec.push_back(20);
	vector<int> ppVec = move(pVec);
	cout << pVec.capacity() << " " << ppVec.capacity() << endl;//0 2
}