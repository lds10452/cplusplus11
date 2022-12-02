#include "test.h"
#define toString(exp) #exp		//将exp变成字符串，不会宏展开
#define _toString(exp) toString(exp)	//会宏展开
#define appendStr(exp1,exp2) exp1##exp2	//拼接参数，不会宏展开
#define _appendStr(exp1,exp2) appendStr(exp1,exp2)	//会宏展开
#define STR str
void testString()
{
	cout << toString(STR) << endl;	//STR
	cout << _toString(STR) << endl;	//str
	int STRSTR = 10, strstr = 5;
	cout << appendStr(STR, STR) << endl;	//10
	cout << _appendStr(STR, STR) << endl;	//5
	cout << toString(appendStr(STR, STR)) << endl;//appendStr(STR, STR)
	cout << _toString(appendStr(STR, STR)) << endl; //STRSTR
	cout << _toString(STRSTR) << endl; //STRSTR
}

shared_ptr<void> Guard(void* p)
{
	return shared_ptr<void>(p, [&](void* p) {delete p; });
}
#define FUN(p) shared_ptr<void> p##p(p,[](void* p) {delete p; })
void testGuard()
{
	int* p = new int(1);
	//Guard(p);//error,这句之后会导致p释放，成野指针,可以下面这样写
	//FUN(p);//true,1
	shared_ptr<void> p1 = Guard(p);//1
	cout << *p << endl;
}
void test4_4()
{
	//testString();
	testGuard();
}