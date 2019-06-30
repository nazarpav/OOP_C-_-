#pragma once
#include<iostream>
#include<string>
#include"Animal.h"
using namespace std;
class Cat :public Animal
{
public:
	Cat(string name, short age) :Animal(name, age)
	{
	}
	void Sound()
	{
		cout << "May may May" << endl;
	}
	virtual void Show()
	{
		cout << "Name: " << name << "\nAge: " << age << endl;
	}
	virtual void Type()
	{
		cout << "Type: Cat" << endl;
	}
};