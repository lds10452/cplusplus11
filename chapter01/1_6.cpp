#include "test.h"
#include <vector>
class B
{
	int a;
	void func(int x,int y)
	{
		auto x1 = [=] {return a + x + y; };
		//auto x1 = [] {return a; };			//error
		//auto x2 = [this] {return a + x + y; };//error
		auto x3 = [this] {return a++; };
		auto x4 = [&] {return a++; };
		//auto x5 = [=] {return x++; };	//error,xΪconst
		auto x5 = [=]()mutable {return x++; };
		auto x6 = [=, &x] {return y + (x++); };
	}
};
void test1_6()
{
	auto f=[]()->vector<int> {return{ 1,2 }; };//���س�ʼ���б���Ҫ����ʡ�Է�������
	for(auto t:f())
		cout << t << endl;
}