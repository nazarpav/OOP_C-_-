#include"airplane.h"
#include <iostream>
using namespace std;
int AIRPLANE::operator++()
{
	if (quantity_passenger != max_quantity_passenger)
	{
		return this->quantity_passenger++;
	}
	else
	{
		cout << "\nEROR <<<<<<<<<<<<<<<<<<<<\n" << char(7);
		return this->quantity_passenger;
	}
}
int AIRPLANE::operator--()
{
	if (quantity_passenger != 0)
	{
		return this->quantity_passenger--;
	}
	else
	{
		cout << "\nEROR <<<<<<<<<<<<<<<<<<<<\n" << char(7);
		return this->quantity_passenger;
	}
}
bool operator==(const AIRPLANE& left,const AIRPLANE& right)
{
	return left.type == right.type&&left.model == right.model;
}
bool operator>(const AIRPLANE& left, const AIRPLANE& right)
{
	return left.type > right.type;
}
bool operator<(const AIRPLANE& left, const AIRPLANE& right)
{
	return left.type < right.type;
}

void AIRPLANE::operator()(int add_passenger)
{
	if (this->quantity_passenger + add_passenger > max_quantity_passenger)
	{
		this->quantity_passenger = max_quantity_passenger;
		return;
	}
	else if(this->quantity_passenger + add_passenger < 0)
	{
		this->quantity_passenger = 0;
		return;
	}
	else
	{
		this->quantity_passenger += add_passenger;
	}
}
void AIRPLANE::show()
{
	cout << "\nModel: " << model << "\nType: " << type << "\nQuantity passenger: " << quantity_passenger << "\nMax quantity passenger" << max_quantity_passenger << endl;
}
AIRPLANE::AIRPLANE(string model, string type, unsigned short quantity_passenger, unsigned short max_quantity_passenger)
{
	this->model = model;
	this->type = type;
	this->quantity_passenger = quantity_passenger;
	this->max_quantity_passenger = max_quantity_passenger;
	if (this->max_quantity_passenger < this->quantity_passenger)
	{
		this->quantity_passenger = this->max_quantity_passenger;
	}
}
