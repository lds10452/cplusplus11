#include "test.h"
#include <vector>
#include <map>

struct Complicated
{
	Complicated(int a,double b,string d):year(a), country(b), name(d) {
		cout << "construct" << endl;
	}
	Complicated(const Complicated& other) :
		year(other.year), country(other.country), name(move(other.name))
	{
		cout << "moved" << endl;
	}
private:
	int year;
	double country;
	string name;
};

void test2_4()
{
	map<int, Complicated> m;
	int anInt = 4;
	double aDouble = 5.0;
	string aString = "C++";

	cout << "--insert--" << endl;
	m.insert(make_pair(4, Complicated(anInt, aDouble, aString)));

	cout << "--emplace--" << endl;
	m.emplace(4, Complicated(anInt, aDouble, aString));

	cout << "--emplace_back--" << endl;
	vector<Complicated> v;
	v.emplace_back(anInt, aDouble, aString);

	cout << "--push_back--" << endl;
	v.push_back(Complicated(anInt, aDouble, aString));
}