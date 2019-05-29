#pragma once
#include <string>
using namespace std;
class student
{
	string name;
	string surname;
	unsigned short age;
	float assessment;
	int quantity_skips;
	unsigned short Cale_age(unsigned short year_of_birth)
	{
		return 2019 - year_of_birth;
	}
public:
	void set_surname(string);
	void set_name(string);
	void set_age(unsigned short);
	void set_quantity_skips(int);;
	void set_assessment(float);

	string get_surname();
	string get_name();
	unsigned short get_age();
	unsigned short get_quantity_skips();
	float get_assessment();
	void show_student(string var = "all");
	student get_successful_student(student & obj);
	student();
	student(const string new_name, const string new_surname, const float assessment, const int quantity_skips, const int age);
	

};