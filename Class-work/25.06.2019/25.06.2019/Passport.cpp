#include "Passport.h"



Passport::Passport(short age, bool is_male, string name, string adress)
{
	this->age= age;
	this->is_male= is_male;
	this->name= name;
	this->adress= adress;
}


Passport::~Passport()
{
}
