#include <iostream>
#include <string>
#include "smart_template_array.h"
using namespace std;

int main()
{
	/*S_T_A<string>obj("q", 5);
	S_T_A<string>obj3("w", 5);
	S_T_A<string>obj2("s", 5);*/


	S_T_A<int>obj(2, 5);
	S_T_A<int>obj3(3, 5);
	S_T_A<int>obj2(4, 5);
	//obj.fill();
	//obj.show();
	/*obj.add_elem("e");
	obj.add_elem("e");
	obj.add_elem("e");
	obj.add_elem("e");
	obj.insert_elem("hello", 9);*/
	obj2.show();
	//cout<<obj.get_apper_bound();
	obj3.show();
	obj.show();
	obj2 = obj + obj3;

	obj2.show();
	system("pause");
	return 0;
}