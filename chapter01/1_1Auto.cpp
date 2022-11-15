#include "test.h"

//void func(auto a=1){}	//error:auto�������ں�������
class Foo
{
	//auto var1 = 0;	//error:auto�������ڷǾ�̬��Ա����
	static const auto var2 = 0;
public:
	static int get() { return 0; }
};

template<class T>
class Bar
{
public:
	static const char* get() { return "0"; }
};

template<typename T>
void func()
{
	auto val = T::get();
}

void test1_1Auto()
{
	//auto int r;	//error:auto���ٱ�ʾ�洢����ָʾ��
	//auto s;		//error���޷��Ƶ���s������

	int x = 0;
	auto& c = x;
	auto d = c;	//d->int,�������&����
	const auto e = x;
	auto f = e;	//f->int,���const����
	const auto& g = x;
	auto& h = g;	//h->const int&,���ú�const���ʱ������const

	//auto arr[10] = { 0 };	//error:�޷���������
	//Bar<auto> bb = Bar<int>();	//error:�޷�ͨ�����������Ƶ���ģ�����

	func<Foo>();
	func<Bar<int>>();
}

