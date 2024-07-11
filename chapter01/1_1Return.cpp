#include "test.h"

// R->����ֵ����, T->����1����, U->����2����
template <typename R, typename T, typename U>
R sub(T t, U u)
{
	return t - u;
}

//�������ͺ��õı�Ҫ��
template<typename T,typename U>
//decltype(t + u) add(T t, U u)	//error,ǰ���﷨��t��uδ����
//decltype(T() + U())add(T t, U u)	//���ʺ�TUû���޲ι��캯�������
//decltype((*(T*)0) + (*(U*)0)) add(T t, U u)	//�ɶ��Բ�
auto add(T t, U u)->decltype(t + u)	//�����﷨
{
	return t + u;
}

//3�ַ������ض�����ݣ�ʹ������ָ��
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
	cout << sub<decltype(3-2)>(3, 2) << endl;	//1
	cout << add(1, 2.1) << endl;	//3.1
	cout << retArray(0)[1][1] << endl;	//5
	auto arr = retArray(0);
	cout << sizeof(*arr) / sizeof(**arr) << endl;	//3
}