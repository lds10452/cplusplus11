#include "test.h"

class Entrust
{
public:
    Entrust() {};
    Entrust(int max)
    {
        this->m_max = max > 0 ? max : 100;
    }

    //Entrust(int max, int min)
    //{
    //    this->m_max = max > 0 ? max : 100;              // 冗余代码
    //    this->m_min = min > 0 && min < max ? min : 1;
    //}

    //Entrust(int max, int min, int mid)
    //{
    //    this->m_max = max > 0 ? max : 100;             // 冗余代码
    //    this->m_min = min > 0 && min < max ? min : 1;  // 冗余代码
    //    this->m_middle = mid < max&& mid > min ? mid : 50;
    //}
    
    //上面两段用下面替换
    Entrust(int max, int min) :Entrust(max)//, m_max(max)
    {
        //Entrust(max);	// error, 此处编译器会报错, 提示形参max被重复定义
        this->m_min = min > 0 && min < max ? min : 1;
    }

    Entrust(int max, int min, int mid) :Entrust(max, min)
    {
        this->m_middle = mid < max&& mid > min ? mid : 50;
    }

    int m_min;
    int m_max;
    int m_middle;
};

void testEntrust()
{
    Entrust t(90, 30, 60);
    cout << "min: " << t.m_min << ", middle: "
        << t.m_middle << ", max: " << t.m_max << endl;
}

//测继承构造函数
class Base
{
public:
    Base(int i) :m_i(i) {}
    Base(int i, double j) :m_i(i), m_j(j) {}
    Base(int i, double j, string k) :m_i(i), m_j(j), m_k(k) {}

    int m_i;
    double m_j;
    string m_k;
};

class Child : public Base
{
public:
    //Child(int i) :Base(i) {}
    //Child(int i, double j) :Base(i, j) {}
    //Child(int i, double j, string k) :Base(i, j, k) {}

    //以上代码用下行替换
    using Base::Base;
};

void testInherit()
{
    Child c(520, 13.14, "i love you");
    cout << "int: " << c.m_i << ", double: "
        << c.m_j << ", string: " << c.m_k << endl;
}

//测同名函数
class super
{
public:
    void func(int i)
    {
        cout << "base class: i = " << i << endl;
    }

    void func(int i, string str)
    {
        cout << "base class: i = " << i << ", str = " << str << endl;
    }
};
class son : public super
{
public:
    using super::func;
    void func()
    {
        cout << "child class: i'am luffy!!!" << endl;
    }
};

void testSuper()
{
    son c;
    c.func();
    c.func(19);
    c.func(19, "luffy");
}

void test7_1()
{
//    testEntrust();//测委托构造函数
//    testInherit();//测继承构造函数
    testSuper();//测同名函数
}