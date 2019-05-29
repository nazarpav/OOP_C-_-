#include <string>
#include <iostream>
#include "Arr_student.h"
#include <fstream>
#include <windows.h>
using namespace std;

	inline string student::get_name()const
	{
		return name;
	}
	inline string student::get_surname()const
	{
		return surname;
	}
	inline string student::get_date_of_birth()const
	{
		return date_of_birth;
	}
	inline string student::get_address()const
	{
		return address;
	}
	inline unsigned int student::get_telephone_number()const
	{
		return telephone_number;
	}
	inline float student::get_average_assessment()const
	{
		return average_assessment;
	}
	inline void student::set_name(string new_name)
	{
		name = new_name;
	}
	inline void student::set_surname(string new_surname)
	{
		surname = new_surname;
	}
	inline void student::set_date_of_birth(string new_date_of_birth)
	{
		date_of_birth = new_date_of_birth;
	}
	inline void student::set_address(string new_address)
	{
		address = new_address;
	}
	inline void student::set_telephone_number(unsigned int new_telephone_number)
	{
		telephone_number = new_telephone_number;
	}
	inline void student::set_average_assessment(float new_average_assessment)
	{
		average_assessment = new_average_assessment;
	}
	

	void student::show_student()const
	{
		cout << "Name: " << this->name << "\nSurname: " << this->surname<<"\nDate of birth: "<< this->date_of_birth<<"\nAddress: "<< this->address<<"\nTelephone number: "<< this->telephone_number<<"\nAverage assessment: "<< this->average_assessment<<"\n=======================================================================\n";
	}
	void student::Save_in_file()
	{
		ofstream out;
		string path = "Player.txt";
		out.open(path, ios_base::out);

		//out << "12";

		out << this->name << endl;
		out << this->surname << endl;
		out << this->date_of_birth << endl;
		out << this->address << endl;
		out << this->telephone_number << endl;
		out << this->average_assessment << endl;

		out.close();

		cout << "Great!!!\n";
		Sleep(2000);//sleep 2 sec
	}
	void student::Load_from_file()
	{
		ifstream in("Player.txt", ios_base::in);

			in >> this->name;
			in >> this->surname;
			in >> this->date_of_birth;
			in >> this->address;
			in >> this->telephone_number;
			in >> this->average_assessment;

		in.close();

		cout << "Great!!!\n";
		Sleep(2000);//sleep 2 sec
	}

	

	void student::fill_data_on_student()
	{
		cout << "Enter Name: ";
		cin >> this->name;
		cout << "\nEnter Surname: ";
		cin >> this->surname;
		cout << "\nEnter date of birth: ";
		cin >> this->date_of_birth;
		cout << "\nEnter Address: ";
		cin >> this->address;
		cout << "\nEnter Telephone number: ";
		cin >> this->telephone_number;
		cout << "\nEnter Average assessment: ";
		cin >> this->average_assessment;
	}
	student::student()
	{
		string name = "Empty";
		string surname = "Empty";
		string date_oF_birth = "Empty";
		string address = "Empty";
		unsigned int telephone_number = 0;
		float average_assessment = 0;

	}

	student::~student()
	{


	}