#include "test.h"
#include <map>
class Person1
{
	map<int, int> content_;
	using pair_t = map<int, int>::value_type;
public:
	Person1(initializer_list<pair_t> list)
	{
		for (auto it = list.begin(); it != list.end(); it++)
		{
			content_.insert(*it);
		}
		cout << list.size() << endl;	//3
		list = { {2,2},{3,3} };
		cout << list.size() << endl;	//2
	}
};

void test1_3()
{
	Person1 p1{ {1,1},{2,2},{3,3} };
}