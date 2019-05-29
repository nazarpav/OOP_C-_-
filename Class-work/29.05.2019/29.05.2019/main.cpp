#include <iostream>
#include"String_.h"
using namespace std;
int STRING::counter = 0;
int main()
{
	STRING obj;
	obj.SetStringFromKeyboard();
	obj.Show();
	STRING obj2(obj);
	obj2.Show();
	cout<< STRING::counter;
	system("pause");
	return 0;
}