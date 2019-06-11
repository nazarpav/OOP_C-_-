#include<iostream>
#include"STRING_.h"
using namespace std;
STRING_ foo()
{
	STRING_ obj('*',5);
	return obj;
}
int main()
{
	STRING_ obj1('1',5);
	STRING_ obj2('2',5);
	STRING_ obj3('3',5);
	//obj1 = move(obj2/*+obj3*/);
	obj1.Show();
	obj2.Show();
	obj3.Show();
	obj3 = foo();
	obj3.Show();
	system("pause");
	return 0;
}