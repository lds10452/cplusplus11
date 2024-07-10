#include "test.h"
void func_3_1(const int num)
{
    const int count = 24;
//    int array[num];            // error，num是一个只读变量，不是常量
    int array1[count];         // ok，count是一个常量

    int a1 = 520;
    int a2 = 250;
    const int& b = a1;
//    b = a2;                         // error
    a1 = 1314;
    cout << "b: " << b << endl;     // 输出结果为1314
}

// 此处的constexpr修饰是无效的
//constexpr struct Test
//{
//    int id;
//    int num;
//};
struct Person
{
    int name;
    int age;
};
void func_3_2()
{
    constexpr Person  t{ 1, 2 };
    constexpr int id = t.name;
    constexpr int num = t.age;
    int a = 10;
//    constexpr int b = a;//error,a是变量，表达式必须含有常量值
//    t.num += 100;// error，不能修改常量
}

// 定义函数模板
template<typename T>
constexpr T dispaly(T t) {
    return t;
}
void func_3_3()
{
    struct Person p { 11, 19 };
    //普通函数
    struct Person ret = dispaly(p);
    cout << "luffy's name: " << ret.name << ", age: " << ret.age << endl;

    //常量表达式函数
    constexpr int ret1 = dispaly(250);
    cout << ret1 << endl;

    constexpr struct Person p1 { 11, 19 };
    constexpr struct Person p2 = dispaly(p1);
    cout << "luffy's name: " << p2.name << ", age: " << p2.age << endl;
}

void testx_3()
{
//    func_3_1(2);
//    func_3_2();
    func_3_3();
}