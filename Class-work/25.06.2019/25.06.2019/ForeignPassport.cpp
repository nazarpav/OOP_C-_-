#include "ForeignPassport.h"
#include<string>
#include<iostream>
using namespace std;



ForeignPassport::ForeignPassport(short age, bool is_male, string name, string adress, string visa, string nationality, short quantity_travels)
	: Passport(age, is_male, name, adress)
{
	this->visa = visa;
	this->nationality = nationality;
	this->quantity_travels = quantity_travels;
}

void ForeignPassport::show()
{
	Passport::show();
	cout << "Visa: " << visa << "\nNationality: " << nationality << "\nQuantity travels: " << quantity_travels << endl;
}
