#include "test.h"

/*struct T1
{
    int x;
    long y;
protected:
    int z;
}t{ 1, 100, 2 };*/		// error, ������˽�г�Ա, �޷�ʹ�ó�ʼ���б��ʼ��

struct T2
{
    int x;
    long y;
protected:
    static int z;
}
//t{ 1, 100�� 2 };		// error�����ܳ�ʼ����̬��Ա��������Ҫ�����������滻
t{ 1, 100 };		// ok
// ��̬��Ա�ĳ�ʼ��
int T2::z = 2;

struct T3
{
    int x;
    double y = 1.34;
    int z[3]{ 1,2,3 };
};

void test1_3_1()
{
//	int a{ 1.1 };//error,������ʽת��

    T3 t{ 520, 13.14, {6,7,8} };		// error, c++11��֧��,��c++14��ʼ��֧����
}