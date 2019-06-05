#pragma once
#include<string>
using namespace std;
class AIRPLANE
{
public:
	int operator++();
	int operator--();
	friend bool operator==(const AIRPLANE & left, const AIRPLANE & right);
	friend bool operator>(const AIRPLANE & left, const AIRPLANE & right);
	friend bool operator<(const AIRPLANE & left, const AIRPLANE & right);
	void operator()(int add_passenger);
	void show();
	AIRPLANE(string model, string type, unsigned short quantity_passenger, unsigned short max_quantity_passenger);
	
private:
	string model;
	string type;
	unsigned short quantity_passenger;
	unsigned short max_quantity_passenger;
};
