#include <iostream>
#include <string>
#include "DATE.h"
using namespace std;

int main()
{
	DATE_ obj1(23,8,2000);
	DATE_ obj2(23,8,2001);

	obj1.show();

	cout << obj2 + obj1<<endl;
	cout << obj2 - obj1;
	system("pause");
	return 0;
}