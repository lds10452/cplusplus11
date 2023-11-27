#include "test.h"

template<typename T>
shared_ptr<T> make_shared_array(size_t size)
{
	return shared_ptr<T>(new T[size], default_delete<T[]>());
}
void fun(shared_ptr<int> p)
{

}
void test4_1_1()
{
	shared_ptr<int> p(new int(1));
	{
		shared_ptr<int>p2 = p;
		cout << p2.use_count() << " " << p.use_count() << endl;//2,2
	}
	shared_ptr<int>ptr = p;
	cout << ptr.use_count() << " " << p.use_count() << endl;//2,2
	ptr.reset(new int(1));
	if (ptr)
	{
		cout << "ptr not null "<<ptr.use_count() << " " 
			<< p.use_count() << endl; ///ptr not null,1,1
	}
	//shared_ptr<int> p3 = new int(1);//error
	shared_ptr<int> p0 = make_shared<int>(10);
	
	int* p4 = ptr.get();
	cout << *p4 << " " << *p0.get() << " " << ptr.use_count() << endl;//1,10,1

	shared_ptr<int> p5(new int[10], [](int* p) {delete[]p; });
	shared_ptr<int> p6(new int[10], default_delete<int[]>());
	shared_ptr<char> p7 = make_shared_array<char>(10);
	cout << p7.use_count() << endl;//1

	int* p8 = new int(9);
	{
		shared_ptr<int> p9(p8);
		//shared_ptr<int> p10(p8);//logic error
	}
	cout << *p8 << endl;//堆空间已释放，无效值

	fun(shared_ptr<int>(new int(10), [](int* p) {delete p; }));//有缺陷
	
}