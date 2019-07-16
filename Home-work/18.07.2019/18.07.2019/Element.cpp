#include <iostream>
#include<string>
#include"Element.h"
using namespace std;

std::ostream& operator<< (std::ostream &out, const Element &point)
{
	out << point.firm_name <<" "<< point.owner << " " << point.tel_num << " " <<point.addres << " " <<point.firm_activity << " ";
	return out;
}
std::istream& operator>> (std::istream &in, Element &point)
{
	in >> point.firm_name >> point.owner >> point.tel_num >> point.addres >> point.firm_activity;
	return in;
}