#include "test.h"
#include <vector>
class MyString
{
private:
	char* m_data;
	size_t m_len;
	void copyData(const char* s)
	{
		m_data = new char[m_len + 1];
		memcpy(m_data, s, m_len);
		m_data[m_len] = '\0';
	}
public:
	MyString()
	{
		m_len = 0;
		m_data = new char('\0');
		cout << "无参构造：" << m_data << endl;
	}
	MyString(const char* p)
	{
		m_len = strlen(p);
		copyData(p);
		cout << "有参构造：" << m_data << endl;
	}
	MyString(const MyString& str)
	{
		m_len = str.m_len;
		copyData(str.m_data);
		cout << "拷贝构造：" << m_data << endl;
	}
	MyString& operator=(const MyString& str)
	{
		if (this != &str)
		{
			delete[]m_data;
			m_len = str.m_len;
			copyData(str.m_data);
		}
		cout << "拷贝赋值：" << m_data << endl;
		return *this;
	}
	MyString(MyString&& str)
	{
		m_len = str.m_len;
		m_data = str.m_data;	
		str.m_data = NULL;	//拷贝构造不能这样写，因为参数为const,不加const，无法用匿名对象初始化
		cout << "移动构造：" << m_data << endl;
	}
	MyString& operator=(MyString&& str)
	{
		if (this != &str)
		{
			m_len = str.m_len;
			m_data = str.m_data;
			str.m_data = NULL;
		}
		cout << "移动赋值：" << m_data << endl;
		return *this;
	}
	~MyString()
	{
		delete[]m_data;
	}
};

void test2_1_2()
{
	MyString a;//无参
	a = MyString("hello");//有参，移动
	MyString aa = a;//拷贝
	vector<MyString> vec;
	vec.push_back(MyString("world"));//有参，移动

	int c1 = 3;
	const int c2 = 4;
	const int& b1 = c1;		//left
	const int& b2 = int();	//right
	const int& b3 = c2;		//const left

	//int& d = int();//error
}