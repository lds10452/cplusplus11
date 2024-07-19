#include "test.h"

/*struct T1
{
    int x;
    long y;
protected:
    int z;
}t{ 1, 100, 2 };*/		// error, 类中有私有成员, 无法使用初始化列表初始化

struct T2
{
    int x;
    long y;
protected:
    static int z;
}
//t{ 1, 100， 2 };		// error，不能初始化静态成员变量，需要用以下三行替换
t{ 1, 100 };		// ok
// 静态成员的初始化
int T2::z = 2;

struct T3
{
    int x;
    double y = 1.34;
    int z[3]{ 1,2,3 };
};

void test1_3_1()
{
//	int a{ 1.1 };//error,不能隐式转换

    T3 t{ 520, 13.14, {6,7,8} };		// error, c++11不支持,从c++14开始就支持了
}