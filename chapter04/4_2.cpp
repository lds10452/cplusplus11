#include "test.h"
#include <functional>
class MyDeleter//�Զ���ɾ����
{
public:
	void operator()(int* p)
	{
		cout << "delete" << endl;
		delete p;
	}
};
void test4_2()
{
	int* temp = new int(1);
	unique_ptr<int> p(temp);
	//unique_ptr<int> p1 = p;	//error, ���ܸ���
	unique_ptr<int> p2 = move(p);	//ֻ���ƶ�,p����ӵ��temp������Ȩ
	int* arr = new int[3]{ 1,2,3 };
	{
		unique_ptr<int[]>p3(arr);
	}
	cout << arr[1] << endl;//arr���ͷţ���Чֵ

	//unique_ptr<int>p4(new int(1), [](int* p) {delete p; });//error
	unique_ptr<int, void(*)(int*)> p4(new int(1), [](int* p) {delete p; });
	//��Ҫ�����ⲿ����ʱ�������һ�л���뱨�����԰��ڶ���д
	//unique_ptr<int, void(*)(int*)> p5(new int(1), [&](int* p) {delete p; });//error
	unique_ptr<int, function<void(int*)>> p6(new int(1), [&](int* p) {delete p; });//true

	unique_ptr<int, MyDeleter> p5(new int(1));
}