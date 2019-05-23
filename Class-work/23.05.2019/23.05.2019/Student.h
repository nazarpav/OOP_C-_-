#pragma once
#include <string>
using namespace std;
class student
{
	static const int data_ = 2019;
	string name;
	string surname;
	unsigned short age;
	unsigned short year_of_birth;
	string address;
	unsigned short Cale_age(unsigned short year_of_birth)
	{
		return data_ - year_of_birth;
	}
public:
	void show_student();
	student();
	student(unsigned short new_year_of_birth, string new_name, string new_surname, string new_address);
	
};