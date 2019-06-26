#pragma once
#include<string>
#include<iostream>
using namespace std;
class Passport
{
protected:
	short age;
	bool is_male;
	string name;
	string adress;
public:
	Passport(short age, bool is_male, string name, string adress);
	~Passport();
	void show()
	{
		cout << "Age: " << age << "\nSex: " << (is_male ? "women" : "man") << "\nName" << name << "Adress: " << adress<<endl;
	}
};

