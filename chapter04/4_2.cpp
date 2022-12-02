#include "test.h"
#include <functional>
class MyDeleter//自定义删除器
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
	//unique_ptr<int> p1 = p;	//error, 不能复制
	unique_ptr<int> p2 = move(p);	//只能移动,p不再拥有temp的所有权
	int* arr = new int[3]{ 1,2,3 };
	{
		unique_ptr<int[]>p3(arr);
	}
	cout << arr[1] << endl;//arr被释放，无效值

	//unique_ptr<int>p4(new int(1), [](int* p) {delete p; });//error
	unique_ptr<int, void(*)(int*)> p4(new int(1), [](int* p) {delete p; });
	//需要捕获外部变量时，下面第一行会编译报错，可以按第二行写
	//unique_ptr<int, void(*)(int*)> p5(new int(1), [&](int* p) {delete p; });//error
	unique_ptr<int, function<void(int*)>> p6(new int(1), [&](int* p) {delete p; });//true

	unique_ptr<int, MyDeleter> p5(new int(1));
}