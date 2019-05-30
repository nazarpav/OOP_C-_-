#include <iostream>
#include "drib.h"
using namespace std;

float drib::operator+(const  drib& other)const
{
	return (this->num + other.num);
}

float drib::operator-(const  drib& other)const
{
	return (this->num - other.num);
}

float drib::operator*(const  drib& other)const
{
	return (this->num * other.num);
}

float drib::operator/(const  drib& other)const
{
	return (this->num / other.num);
}

drib::drib(int chisl, int znam)
{
	this->chisl = chisl;
	this->znam = znam;
}

drib::~drib()
{
}