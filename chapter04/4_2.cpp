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
	unique_ptr<int> p2 = move(p);	//通过右值初始化，调移动构造,p不再拥有temp的所有权
	unique_ptr<int> p3;
	p3 = move(p2);
	p3.reset();
	p3.reset(new int(250));
	cout << *p3.get() << endl;	// 得到内存地址中存储的实际数值 250

	int* arr = new int[3]{ 1,2,3 };
	{
		unique_ptr<int[]>p3(arr);//加[],使用默认删除器,非数组不用加[]
	}
	cout << arr[1] << endl;//arr被释放，无效值

	//unique_ptr<int>p4(new int(1), [](int* p) {delete p; });//error
	unique_ptr<int, void(*)(int*)> p4(new int(1), [](int* p) {delete p; });
	//需要捕获外部变量时，下面第一行会编译报错，可以按第二行写
	//unique_ptr<int, void(*)(int*)> p5(new int(1), [&](int* p) {delete p; });//error
	unique_ptr<int, function<void(int*)>> p6(new int(1), [&](int* p) {delete p; });//true

	unique_ptr<int, MyDeleter> p5(new int(1));
}