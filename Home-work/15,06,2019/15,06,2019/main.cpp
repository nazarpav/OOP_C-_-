#include<iostream>
#include<string>
#include"VAR.h"
using namespace std;
void main()
{
	VAR <double>obj1(123.43);
	VAR <double>obj2(1232.12);

	VAR <string>obj3;

	obj3 = obj1 + obj2;

	obj3.show();

	system("pause");
}