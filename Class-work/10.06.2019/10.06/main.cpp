#include<iostream>
#include<string>
#include"Smart_arr.h"
using namespace std;

Smart_Array foo()
{
	Smart_Array obj(12,3,4);
	return obj;
}

int main()
{
	Smart_Array obj(5,5,5);
	Smart_Array obj2(7,5,5);
	string hg = "jhgu";
	hg.length();
	obj.Show();
	Smart_Array obj4(obj);
	obj4.Show();
	Smart_Array obj5 = foo();
	obj5.Show();
	system("pause");
	return 0;
}