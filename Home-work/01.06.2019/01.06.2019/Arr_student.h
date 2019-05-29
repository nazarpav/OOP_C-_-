#pragma once
#include <string>
using namespace std;
class student
{
private:
	string name;
	string surname;
	string date_of_birth;
	string address;
	unsigned int telephone_number;
	float average_assessment;
public:
	student();
	~student();

	string get_name()const;

	string get_surname()const;

	string get_date_of_birth()const;

	string get_address()const;

	unsigned int get_telephone_number()const;

	float get_average_assessment()const;

	void set_name(string new_name);

	void set_surname(string new_surname);

	void set_date_of_birth(string new_date_of_birth);

	void set_address(string new_address);

	void set_telephone_number(unsigned int new_telephone_number);

	void set_average_assessment(float new_average_assessment);

	void show_student()const;

	void Load_from_file();

	void Save_in_file();

	void fill_data_on_student();


};



