#include <iostream>
#include <string>
#include <windows.h>
#include "Student.h";

using namespace std;




void student::show_student()
{
	cout << "name: " << name << endl;
	cout << "surnmae: " << surname << endl;
	cout << "age: " << age << endl;
	cout << "year of birth: " << year_of_birth << endl;
	cout << "address: " << address << endl;
	cout << "assessment: " << assessment << endl;
}


student::student()
{
	year_of_birth = 0;
	age = 0;
	name = "Empty!";
	surname = "Empty!";
	address = "Empty!";
}

student::student(unsigned short new_year_of_birth, string new_name, string new_surname, string new_address,double assessment)
{
	year_of_birth = new_year_of_birth;
	age = Cale_age(year_of_birth);
	name = new_name;
	surname = new_surname;
	address = new_address;
	this->assessment = assessment;
}

void student::set_surname(string name)
{
	this->name = name;
}

void student::set_name(string surname)
{
	this->surname = surname;
}

void student::set_age(unsigned short age)
{
	this->age = age;
}

void student::set_year_of_bitrh(unsigned short year_of_bitrh)
{
	this->year_of_birth = year_of_bitrh;
}

void student::set_address(string address)
{
	this->address = address;
}

void student::set_assessment(double assessment)
{
	this->assessment = assessment;
}


string student::get_surname()
{
	return this->surname;
}

string student::get_name()
{
	return this->name;
}

unsigned short student::get_age()
{
	return this->age;
}
unsigned short student::get_year_of_bitrh()
{
	return this->year_of_birth;
}

string student::get_address()
{
	return this->address;
}

double student::get_assessment()
{
	return this->assessment;
}