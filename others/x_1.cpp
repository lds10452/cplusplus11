#include "test.h"

void testx_1()
{
    string str = "D:\hello\world\test.text";
    cout << str << endl;//D:helloworld    est.text

    string str1 = "D:\\hello\\world\\test.text";
    cout << str1 << endl;//D : \hello\world\test.text

    string str2 = R"(D:\hello\world\test.text)";
    cout << str2 << endl;//D : \hello\world\test.text

    string str3 = R"luffy(D:\hello\world\test.text)luffy";
    cout << str3 << endl;//D : \hello\world\test.text

//    string str3 = R"luffy(D:\hello\world\test.text)robin";	// �﷨���󣬱��벻ͨ��
//     cout << str3 << endl;


    string str4 = "<html>\
        <title>\
        ������\
        </title>\
        </html>";
    cout << str4 << endl;//<html>        <title>        ������        </title>        </html>

    string str5 = R"(
<html>
      <title>
            ������
      </title>
</html>)";
    cout << str5 << endl;//��ʾ������һ��
}