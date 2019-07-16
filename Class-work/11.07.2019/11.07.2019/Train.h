#pragma once
#include <string>
#include <iostream>
#include "my_time.h"
using namespace std;
/*Завдання:
Написати програму «Автоматизована інформаційна система залізничного вокзалу».
Система містить: відомості про відправлення поїздів далекого прямування.

Для кожного поїзда вказуємо:
- номер,
- час відправлення
- станцію призначення

Забезпечити:
■ Додати поїзд в систему;
■ Виведення інформації по всіх поїздах;
■ Виведення інформації по конкретному поїзді;
■ Відредагувати час відправлення поїзду;
■ Відсортувати список поїздів по часу відправлення;
■ Показати список поїздів по станції призначення;
■ Записати список в файл;
■ Зчитати список з файлу.*/
class Train
{
	int number;
	MyTime time_departure;
	std::string arriev_place;
public:
	Train()
	{
		number=0;
	}
	void operator=(Train &other)
	{
		this->number = number;
		this->time_departure = time_departure;
		this->arriev_place = arriev_place;
	}
	friend std::istream& operator>> (std::istream &in, Train &point);
	friend std::ostream& operator<< (std::ostream &out, const Train &point);
	Train(int number,MyTime time_, std::string arriev_place)
	{
		this->number = number;
		this->time_departure = time_;
		this->arriev_place = arriev_place;
	}
	void set_number(int number)
	{
		this->number = number;
	}
	void set_time_departure(MyTime time_departure)
	{
		this->time_departure = time_departure;
	}
	void set_arriev_place(std::string arriev_place)
	{
		this->arriev_place = arriev_place;
	}
	bool operator>(Train &other)
	{
		return this->time_departure > other.time_departure;
	}
	bool operator<(Train &other)
	{
		return this->time_departure < other.time_departure;
	}
	int get_number()
	{
		return number;
	}
	MyTime get_time_departure()
	{
		return this->time_departure;
	}
	std::string get_arriev_place()
	{
		return arriev_place ;
	}
};

std::ostream& operator<< (std::ostream &out, const Train &point)
{
	out << point.number << endl << point.time_departure << endl << point.arriev_place;
    return out;
}
std::istream& operator>> (std::istream &in, Train &point)
{
	in >> point.number;
	in >> point.time_departure;
	in >> point.arriev_place;
	return in;
}
