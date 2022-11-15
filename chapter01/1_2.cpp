#include "test.h"
#include<map>
//template<class T>
//typedef map<int, T> map_int_t;	//无法定义模板别名

typedef map<int, string> map_s_t;	//和下面方式用using等价
using map_s_t = map<int, string>;

template<class T>
struct func_st
{
	typedef void(*type)(T, T);
};

template<class T>
using func_t = void(*)(T, T);	//和上面方式等价

//void foo(void (*func_c)(int, int)){}		//无法同下面实现重载
//void foo(func_t<int> func_T){}	//形参和上面形参等价

void test1_2()
{
	func_st<int>::type func1;	//使用外敷模板定义模板别名，略显烦琐
	func_t<int> func2;	//使用using更加清晰,func2只是void(*)(T,T)的别名
}