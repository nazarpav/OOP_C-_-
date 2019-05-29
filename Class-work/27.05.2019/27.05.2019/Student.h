#pragma once
#include <string>
using namespace std;
class student
{
	//static const int data_ = 2019;
	string name;
	string surname;
	unsigned short age;
	unsigned short year_of_birth;
	float assessment;
	string address;
	unsigned short Cale_age(unsigned short year_of_birth)
	{
		return 2019 - year_of_birth;
	}
public:
	void set_surname(string);
	void set_name(string);
	void set_age(unsigned short);
	void set_year_of_bitrh(unsigned short);
	void set_address(string);
	void set_assessment(double);

	string get_surname();
	string get_name();
	unsigned short get_age();
	unsigned short get_year_of_bitrh();
	string get_address();
	double get_assessment();
	void show_student();
	student();
	student(unsigned short new_year_of_birth, string new_name, string new_surname, string new_address,double assessment);

	

};