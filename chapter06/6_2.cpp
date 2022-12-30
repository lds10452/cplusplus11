#include "test.h"
#include <string>
#include <codecvt>

void num2str()
{
	double f = 1.53;
	string str = to_string(f);
	cout << str << endl;//1.53

	wstring wstr = to_wstring(f);
	wcout << wstr << endl;//1.53

	const char* str1 = "110";
	const char* str2 = "3.14159";
	const char* str3 = "1233 with words";
	const char* str4 = "words and 2";

	int num1 = atoi(str2);//3
	int num2 = atoi(str3);//1233
	int num3 = atoi(str4);//0
	cout << num1 << " " << num2 << " " << num3 << endl;
}

void str2wstr()
{
	wstring wstr = L"ÖÐ¹úÁú";
	wstring_convert<codecvt<wchar_t, char, mbstate_t>> converter
	(new codecvt<wchar_t, char, mbstate_t>("CHS"));
	string str = converter.to_bytes(wstr);
	wstring wstr1 = converter.from_bytes(str);
	cout << str << endl;
	wcout.imbue(locale("chs"));
	wcout << wstr1 << endl;
}

void test6_2()
{
	num2str();
	str2wstr();
}