#include<iostream>
#include"time.h"
using namespace std;

int main()
{

	TIME obj(111);
	TIME obj2(112);
	obj.show();
	if (obj2 >= obj)
	{
		cout << "==" << endl;
	}
	else
	{
		cout << "!=" << endl;
	}
	system("pause");
	return 0;
}