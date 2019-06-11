#include <iostream>
#include <string>
#include "smart_template_array.h"
using namespace std;

int main()
{
	S_T_A<string>obj("q", 5);
	S_T_A<string>obj3("q", 5);
	S_T_A<string>obj2(" ", 5);

	obj.fill();
	obj.show();
	obj.add_elem("e");
	obj.add_elem("e");
	obj.add_elem("e");
	obj.add_elem("e");
	obj.insert_elem("hello", 9);
	obj.show();
	cout<<obj.get_apper_bound();
	//obj2 = obj + obj3;
	obj2.show();
	obj.show();
	system("pause");
	return 0;
}