#pragma once
#include<iostream>
#include<string>
#include"Animal.h"
using namespace std;
class Frog:public Animal
{
public:
	Frog(string name, short age) :Animal(name,age)
	{
	}
	void Sound()
	{
		cout << "Crakk" << endl;
	}
	virtual void Show()
	{
		cout << "Name: " << name << "\nAge: " << age << endl;
	}
	virtual void Type()
	{
		cout << "Type: frog" << endl;
	}
};