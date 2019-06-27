#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Driver
{
	string name;
	string surname;
	unsigned short age;
	unsigned short experience;
public:
	Driver(string name, string surname, unsigned short age, unsigned short experience)
	{
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->experience = experience;
	}
	void Show()
	{
		cout << "Name: " << name << "\nSurname: " << surname << "\nAge: " << age << "\nExpierience: " << experience << endl;
	}
};