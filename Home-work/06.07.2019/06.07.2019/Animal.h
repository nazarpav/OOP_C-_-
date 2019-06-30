#pragma once
#include<iostream>
#include<string>
using namespace std;
class Animal
{
public:
	Animal(string name,short age):name(name),age(age)
	{
	}
	virtual void Sound() = 0;  
	virtual void Show() = 0;
	virtual void Type() = 0;
protected:
	string name;
	short age;
};


