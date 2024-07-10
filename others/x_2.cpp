#include "test.h"

void func(char* p)
{
	cout << "void func(char *p)" << endl;
}

void func(int p)
{
	cout << "void func(int p)" << endl;
}

void testx_2()
{
	func(NULL);		// void func(int p)
	func(250);		// void func(int p)
	func(nullptr);	// void func(char *p)
}