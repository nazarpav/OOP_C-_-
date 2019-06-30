#pragma once
#include<iostream>
#include<string>
#include"Animal.h"
using namespace std;
class Parrot :public Animal
{
public:
	Parrot(string name, short age) :Animal(name, age)
	{
	}
	void Sound()
	{
		cout << "Parrot sound" << endl;
	}
	virtual void Show()
	{
		cout << "Name: " << name << "\nAge: " << age << endl;
	}
	virtual void Type()
	{
		cout << "Type: Parrot" << endl;
	}
};