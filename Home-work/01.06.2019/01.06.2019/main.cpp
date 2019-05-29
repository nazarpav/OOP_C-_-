#include<iostream>
#include"Arr_student.h"
using namespace std;
int main()
{
	student obj;
	obj.show_student();
	obj.fill_data_on_student();
	obj.show_student();
	obj.Save_in_file();
	//obj.Load_from_file();
	//obj.show_student();

	return 0;
}