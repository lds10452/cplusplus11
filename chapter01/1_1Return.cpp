#include "test.h"

auto sub(int a, int b)->int
{
	return a - b;
}

//返回类型后置的必要性
template<typename T,typename U>
//decltype(t + u) add(T t, U u)	//error,前置语法，t、u未定义
//decltype(T() + U())add(T t, U u)	//不适合TU没有无参构造函数的情况
//decltype((*(T*)0) + (*(U*)0)) add(T t, U u)	//可读性差
auto add(T t, U u)->decltype(t + u)	//后置语法
{
	return t + u;
}

//3种方案返回多个数据，使用数组指针
typedef int arr11[3];	//1
arr11* retArray(int mode)
//int (*retArray(int mode))[3]	//2
//auto retArray(int mode)->int(*)[3]	//3
{
	static int p[2][3]= { {0,1,2},{4,5,6} };
	return &p[mode];
}

void test1_1Return()
{
	cout << sub(3, 2) << endl;	//1
	cout << add(1, 2.1) << endl;	//3.1
	cout << retArray(0)[1][1] << endl;	//5
	auto arr = retArray(0);
	cout << sizeof(*arr) / sizeof(**arr) << endl;	//3
}