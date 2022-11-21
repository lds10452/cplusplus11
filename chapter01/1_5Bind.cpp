#include "test.h"
#include <functional>
using namespace placeholders;
void output(int x, int y, int z)
{
	cout << x << "," << y << "," << z << endl;
}
class AA
{
public:
	int i = 0;
	void bindPut(int x, int y) { cout << x << "," << y << endl; }
};
void test1_5Bind()
{
	AA a;
	function<void(int, int)> ff = bind(&AA::bindPut, &a, 4, 4);
	ff(1, 1);		//4,4
	function<int& (void)> ff_i = bind(&AA::i, &a);
	ff_i() = 123;
	cout << a.i << endl;	//123

	function<void(int, int, int)> fr;
	fr = bind(output, 1, 2, 3);		//必须绑定3个参数
	fr(1,2,2);						//必须传入3个实参，1.2.3
	bind(output, 2, placeholders::_2, 5)(0, 3);	//可传入部分实参，2.3.5
}