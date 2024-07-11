#include "test.h"
#include <map>

//void func(auto a=1){}	//error:auto�������ں�������
class Foo
{
	//auto var1 = 0;	//error:auto�������ڷǾ�̬��Ա����
	//static auto v2 = 0;             // error,��ľ�̬�ǳ�����Ա�����������ڲ�ֱ�ӳ�ʼ��
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
	cout << val << endl;
}
//�ȼ�������д��
template <class A, typename B>        // �����ģ����� B
void func(void)
{
	B val = A::get();
	cout << "val: " << val << endl;
}

void test1_1Auto()
{
	//auto int r;	//error:auto���ٱ�ʾ�洢����ָʾ��
	//auto s;		//error���޷��Ƶ���s������

	int x = 0;
	auto& c = x;//c->int&
	auto d = c;	//d->int,�������&����
	const auto e = x;//e->const int
	auto f = e;	//f->int,���const����
	const auto& g = x;//g->const int &
	auto& h = g;	//h->const int&,���ú�const���ʱ������const

	int array[] = { 1,2,3,4,5 };  
	auto t1 = array;            // ok, t1���Ƶ�Ϊ int* ����
	//auto arr[10] = { 0 };	//error:�޷���������
	//Bar<auto> bb = Bar<int>();	//error:�޷�ͨ�����������Ƶ���ģ�����

	map<int, string> person;
//	map<int, string>::iterator it = person.begin();
	auto it = person.begin();//�ȼ�������
	for (; it != person.end(); ++it)
	{
		// do something
	}

	func<Foo>();
	func<Bar<int>>();
	func<Foo, int>();                  // �ֶ�ָ������ֵ���� -> int
	func<Bar<int>, string>();               // �ֶ�ָ������ֵ���� -> string
}

