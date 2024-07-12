#include "test.h"

class Base
{
public:
    virtual void test()
    {
        cout << "Base class...";
    }
};

class Child : public Base
{
public:
    void test() final override
    {
        cout << "Child class...";
    }
};

class GrandChild final: public Child
{
public:
    // 语法错误, 不允许重写
    //void test()
    //{
    //    cout << "GrandChild class...";
    //}
};

// error, 语法错误,不允许被继承
//class GrandChild1 : public GrandChild
//{
//
//};

void test7_3()
{

}