#include "test.h"
#include <tuple>
#include <map>
void test1_7()
{
	tuple<int, double, string> tp1{ 22,1.2,"333" };
	tuple<const char*, int> tp2 = make_tuple("111", 2);
	cout << get<0>(tp1)<<"	"<< get<2>(tp1) << endl;//22,333

	int a;
	tie(ignore, a) = tp2;
	cout << a << endl;//2

	tuple<int, string, float> tp4(9, "test", 2.11);
	int n = 4;
	auto tp5 = tuple_cat(tp4, make_pair("foo", 10), tp4, tie(n));
	n = 9;
}