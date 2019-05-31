#include <iostream>
#include <string>
#include "DATE.h"
using namespace std;

int main()
{
	DATE_ obj1(23,8,1999);
	DATE_ obj2(23,8,2000);

	obj2.show();

	//cout << obj2 + obj1<<endl;
	cout << obj2 - obj1 << endl;
	system("pause");
	return 0;
}