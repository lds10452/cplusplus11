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
		cout << "�޲ι��죺" << m_data << endl;
	}
	MyString(const char* p)
	{
		m_len = strlen(p);
		copyData(p);
		cout << "�вι��죺" << m_data << endl;
	}
	MyString(const MyString& str)
	{
		m_len = str.m_len;
		copyData(str.m_data);
		cout << "�������죺" << m_data << endl;
	}
	MyString& operator=(const MyString& str)
	{
		if (this != &str)
		{
			delete[]m_data;
			m_len = str.m_len;
			copyData(str.m_data);
		}
		cout << "������ֵ��" << m_data << endl;
		return *this;
	}
	MyString(MyString&& str)
	{
		m_len = str.m_len;
		m_data = str.m_data;	
		str.m_data = NULL;	//�������첻������д����Ϊ����Ϊconst,����const���޷������������ʼ��
		cout << "�ƶ����죺" << m_data << endl;
	}
	MyString& operator=(MyString&& str)
	{
		if (this != &str)
		{
			m_len = str.m_len;
			m_data = str.m_data;
			str.m_data = NULL;
		}
		cout << "�ƶ���ֵ��" << m_data << endl;
		return *this;
	}
	~MyString()
	{
		delete[]m_data;
	}
};

void test2_1_2()
{
	MyString a;
	a = MyString("hello");
	vector<MyString> vec;
	vec.push_back(MyString("world"));

	int c1 = 3;
	const int c2 = 4;
	const int& b1 = c1;		//left
	const int& b2 = int();	//right
	const int& b3 = c2;		//const left

	//int& d = int();//error
}