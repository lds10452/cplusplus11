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
    // �﷨����, ��������д
    //void test()
    //{
    //    cout << "GrandChild class...";
    //}
};

// error, �﷨����,�������̳�
//class GrandChild1 : public GrandChild
//{
//
//};

void test7_3()
{

}