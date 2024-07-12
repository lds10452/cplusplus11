#include "test.h"
//
template <typename T = int, T t = 520>
class Test
{
public:
    void print()
    {
        cout << "current value: " << t << endl;
    }
};
//
template <typename T = int>	// C++98/03不支持这种写法, C++11中支持这种写法
void func(T t)
{
    cout << "current value: " << t << endl;
}
//
template <typename R = int, typename N>
R func1(N arg)
{
    return arg;
}

// 函数模板定义
template <typename T, typename U = char>
void func2(T arg1 = 100, U arg2 = 100)
{
    cout << "arg1: " << arg1 << ", arg2: " << arg2 << endl;
}

void test1_2TemplateParameter()
{
    //
    Test<> t;
    t.print();

    Test<int, 1024> t1;
    t1.print();
    //
    func(100);
    //
    auto ret1 = func1(520);
    cout << "return value-1: " << ret1 << endl;//return value - 1: 520

    auto ret2 = func1<double>(52.134);
    cout << "return value-2: " << ret2 << endl;//return value - 2 : 52.134

    auto ret3 = func1<int>(52.134);
    cout << "return value-3: " << ret3 << endl;//return value - 3 : 52

    auto ret4 = func1<char, int>(100);
    cout << "return value-4: " << ret4 << endl;//return value - 4 : d

    // 模板函数调用
    func2('a'); //arg1: a, arg2 : d
    func2(97, 'a');//arg1 : 97, arg2 : a
    //func2();    //编译报错
}