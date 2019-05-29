#include <iostream>
#include <string>
#include <windows.h>
#include "Student.h";

void student::show_student()
{
	cout <<"name: " <<name<<endl;
	cout <<"surnmae: "<< surname << endl;
	cout << "age: "<<age << endl;
	cout <<"year of birth: "<< year_of_birth << endl;
	cout <<"address: "<< address << endl;
}

student::student()
{
	year_of_birth = 0;
	age = 0;
	name = "Empty!";
	surname = "Empty!";
	address = "Empty!";
}

student::student(unsigned short new_year_of_birth, string new_name, string new_surname, string new_address)
{
	year_of_birth = new_year_of_birth;
	age = Cale_age(year_of_birth);
	name = new_name;
	surname = new_surname;
	address = new_address;
}
