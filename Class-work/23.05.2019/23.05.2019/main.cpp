#include <iostream>
#include <string>
#include <windows.h>
#include "Student.h";
using namespace std;

int main()
{
	student student(1999,"bill","gates","rivne");
	student.show_student();
	system("pause");
	return 0;
}