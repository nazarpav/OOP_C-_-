#include <iostream>
#include <string>
#include <windows.h>
#include "Group.h"
using namespace std;

int main()
{
	student student1(1999, "bill", "gates", "rivne",12);
	student student3(1999, "bill", "gates", "rivne",132);
	student student4(1919, "bil2l", "gate2s", "riv2ne",3);

	//student1.show_student();

	student *student2 = new student[1];
	GROUP group;
	group.add_student(student1);
	group.add_student(student3);
	group.add_student(student4);
	group.set_specialization("math");
	group.show();
	system("pause");
	return 0;
}
