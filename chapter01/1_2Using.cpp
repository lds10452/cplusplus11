#include "test.h"
#include<map>
//template<class T>
//typedef map<int, T> map_int_t;	//�޷�����ģ�����

typedef map<int, string> map_s_t;	//�����淽ʽ��using�ȼ�
using map_s_t = map<int, string>;

template<class T>
struct func_st
{
	typedef void(*type)(T, T);
};

template<class T>
using func_t = void(*)(T, T);	//�����淽ʽ�ȼ�

//void foo(void (*func_c)(int, int)){}		//�޷�ͬ����ʵ������
//void foo(func_t<int> func_T){}	//�βκ������βεȼ�

void test1_2Using()
{
	func_st<int>::type func1;	//ʹ�����ģ�嶨��ģ����������Է���
	func_t<int> func2;	//ʹ��using��������,func2ֻ��void(*)(T,T)�ı���
}