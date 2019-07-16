#pragma once
#include <iostream>
#include<string>
using namespace std;
class Element
{
private:
	/*1. Назва фірми;
	2. Власник;
	3. Телефон;
	4. Адреса;
	5. Рід діяльності.
	*/
	friend class List;
	friend std::istream& operator>> (std::istream &in, Element &point);
	friend std::ostream& operator<< (std::ostream &out, const Element &point);
	string firm_name;
	string owner;
	string tel_num;
	string addres;
	string firm_activity;
	Element * next;	// зв'язок з наступним елементом
	Element * prev;	// зв'язок з попереднім елементом
	public:
	Element operator=(const Element &other)
	{
		this->firm_name = other.firm_name;
		this->owner = other.owner;
		this->tel_num = other.tel_num;
		this->addres = other.addres;
		this->firm_activity = other.firm_activity;
		return *this;
	}
};
