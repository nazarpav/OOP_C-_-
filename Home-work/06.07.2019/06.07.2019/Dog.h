#pragma once
#include<iostream>
#include<string>
#include"Animal.h"
using namespace std;
class Dog :public Animal
{
public:
	Dog(string name, short age) :Animal(name, age)
	{
	}
	void Sound()
	{
		cout << "Gav Gav " << endl;
	}
	virtual void Show()
	{
		cout << "Name: " << name << "\nAge: " << age << endl;
	}
	virtual void Type()
	{
		cout << "Type: dog" << endl;
	}
};