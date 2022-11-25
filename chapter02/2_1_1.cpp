#include "test.h"

void printValue(int& i)
{
	cout << "lvalue:" << i << endl;
}
void printValue(int&& i)
{
	cout << "rvalue" << i << endl;
}
void Forward(int&& i)
{
	printValue(i);//此时i是左值
}

template <class T>
std::string type_name()
{
	typedef typename std::remove_reference<T>::type TR;
	std::unique_ptr<char, void(*)(void*)> own(
#ifndef __GNUC__
		nullptr,
#else
		abi::__cxa_demangle(typeid(TR).name()), nullptr,
		nullptr, nullptr),
#endif
		std::free);

		std::string r = own != nullptr ? own.get() : typeid(TR).name();

		if (std::is_const<TR>::value)
		{
			r += " const";
		}
		if (std::is_volatile<TR>::value)
		{
			r += " volatile";
		}

		if (std::is_lvalue_reference<T>::value)
		{
			r += "&";
		}
		else if (std::is_rvalue_reference<T>::value)
		{
			r += "&&";
		}

		return r;
}

template <typename T>
void Func(T&& t)
{
	std::cout << type_name<T>() << std::endl;
}

void test2_1_1()
{
	int&& c = 1;
	auto&& d = c;	//a->int&

	int e;
	//decltype(e) && f = e;//error,左值初始化右值
	decltype(e) && f = move(e);

	int g = 0;
	printValue(g);
	printValue(4);
	Forward(3);

	std::string str = "Test";
	Func(str);
	Func(std::move(str));
}