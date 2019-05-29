#include <iostream>
#include <string>
#include <windows.h>
#include "Student.h";

using namespace std;




void student::show_student(string var)
{
	cout << "name: " << name << endl;
	cout << "surnmae: " << surname << endl;
	cout << "assessment: " << assessment << endl;
	if (var == "short")
	{	
		return;
	}
	cout << "age: " << age << endl;
	cout << "quantity skips: " << quantity_skips << endl;
}

student  student::get_successful_student(student &obj)
{
	if (obj.get_assessment() > this->get_assessment())
	{
		return obj;
	}
	return*this;
}

student::student()
{
	this->quantity_skips = 0;
	this->age = 0;
	this->name = "Empty!";
	this->surname = "Empty!";
	this->assessment = 0;
}

student::student(const string new_name, const string new_surname, const float assessment, const int quantity_skips,const int age):student()
{
	this->quantity_skips = quantity_skips;
	this->age = age;
	this->name = new_name;
	this->surname = new_surname;
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

void student::set_quantity_skips(int quantity_skips)
{
	this->quantity_skips = quantity_skips;
}


void student::set_assessment(float assessment)
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

unsigned short student::get_quantity_skips()
{
	return this->quantity_skips;
}

float student::get_assessment()
{
	return this->assessment;
}

