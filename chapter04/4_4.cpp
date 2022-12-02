#include "test.h"
#define toString(exp) #exp		//��exp����ַ����������չ��
#define _toString(exp) toString(exp)	//���չ��
#define appendStr(exp1,exp2) exp1##exp2	//ƴ�Ӳ����������չ��
#define _appendStr(exp1,exp2) appendStr(exp1,exp2)	//���չ��
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
	//Guard(p);//error,���֮��ᵼ��p�ͷţ���Ұָ��,������������д
	//FUN(p);//true,1
	shared_ptr<void> p1 = Guard(p);//1
	cout << *p << endl;
}
void test4_4()
{
	//testString();
	testGuard();
}