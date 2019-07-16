#include<iostream>
#include"Unique_ptr.h"
#include<string>
using namespace std;


int main()
{
	Unique_ptr<int> obj = (new int);
	int * data;
	*data = 78;
	obj.Reset(data);
	cout<<obj.Get();

	system("pause");
	return 0;
}