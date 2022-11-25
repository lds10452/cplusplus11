#include "test.h"

void PrintT(int& t)
{
	std::cout << "lvalue" << std::endl;
}

template <typename T>
void PrintT(T&& t)
{
	std::cout << "rvalue" << std::endl;
}

template <typename T>
void TestForward(T&& v)
{
	PrintT(v);
	PrintT(std::forward<T>(v));
	PrintT(std::move(v));
}

void test2_3()
{
	TestForward(1);
	int x = 1;
	TestForward(x);
	TestForward(std::forward<int>(x));
	cout << endl;
	auto a = forward<int>(x);
	PrintT(a);//lvalue
	PrintT(forward<int>(a));//right
	PrintT(forward<int>(x));//right
}
