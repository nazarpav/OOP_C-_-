#include <iostream>
#include "DynamicArr.h"

using namespace std;

int main()
{
	DynamicArr obj1(2);
	DynamicArr obj2(2);
	DynamicArr obj3(5);
	obj1.fill_rand();
	obj2.fill_rand();
	cout << endl;
	obj1.show();
	cout << endl;
	obj2.show();
	cout << endl;
	if (obj1 != obj2)
	{
		cout << "=" << endl;
	}
	else
	{
		cout << "!=" << endl;

	}
	//obj3=obj1 + obj2;
	cout << endl;
	//obj3.show();
	system("pause");
	return 0;
}