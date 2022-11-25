#include "test.h"

void test2_2()
{
	int b = 0;
	int& a = b;
	int&& c = int();
	cout << &a << " " << &c << endl;
}