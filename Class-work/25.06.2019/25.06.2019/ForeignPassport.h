#pragma once
#include<string>
using namespace std;
#include "Passport.h"
class ForeignPassport : public Passport
{
protected:
	string visa;
	string nationality;
	short quantity_travels;
public:
	ForeignPassport(short age, bool is_male, string name, string adress, string visa, string nationality, short quantity_travels);
	void show();
};

