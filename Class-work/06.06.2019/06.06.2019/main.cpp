#include"time12.h"
#include"time24.h"
#include <iostream>
using namespace std;
int main()
{
	TIME12 obj12(15,19,12);
	TIME24 obj24(20,19,40);
	obj12.show();
	obj24.show();
	//obj24 = (TIME24)obj12;
	obj12 = (TIME24)obj24;
	cout << "24>>>>>>>>>>\n";
	obj24.show();
	cout << "12>>>>>>>>>>\n";
	obj12.show();
	system("pause");
	return 0;
}