#include "test.h"

void test7_2()
{
    string str = "D:\hello\world\test.text";
    cout << str << endl;//D:helloworld    est.text

    string str1 = "D:\\hello\\world\\test.text";
    cout << str1 << endl;//D : \hello\world\test.text

    string str2 = R"(D:\hello\world\test.text)";
    cout << str2 << endl;//D : \hello\world\test.text

    string str3 = R"luffy(D:\hello\world\test.text)luffy";
    cout << str3 << endl;//D : \hello\world\test.text

//    string str3 = R"luffy(D:\hello\world\test.text)robin";	// 语法错误，编译不通过
//     cout << str3 << endl;


    string str4 = "<html>\
        <title>\
        海贼王\
        </title>\
        </html>";
    cout << str4 << endl;//<html>        <title>        海贼王        </title>        </html>

    string str5 = R"(
<html>
      <title>
            海贼王
      </title>
</html>)";
    cout << str5 << endl;//显示和上面一样
}