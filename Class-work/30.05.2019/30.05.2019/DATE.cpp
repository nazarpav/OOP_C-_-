#include <iostream>
#include <string>
#include "DATE.h"
using namespace std;

int DATE_::operator-(const DATE_& other)const
{
	return (this->_day - other._day);
}
int DATE_::operator+(const DATE_& other)const
{
	return (this->_day + other._day);
}
void DATE_::show()
{
	cout << "day: " << day << "\nmonth: " << month << "\nyear: " << year << endl;

	cout << endl << _day << endl;
}

void DATE_::to_day()
{
	_day = 0;
	_day = day+month;
}
void DATE_::year_()
{
	if (year / 4 != 0 )
	{
		return;
	}
	else if (year / 100 != 0)
	{
		flag = true;
		return;
	}
	else if (year / 400 == 0)
	{
		flag=true;
		return;
	}


		//&& year / 100 == 0 && year / 400 == 0
}
void DATE_::day_in_month()
{
	for (int i = 1; i <= month; i++)
	{
		if (i % 2 != 0&&i!=2&&i!=7)
		{
			day += 31;
		}
		else if (i % 2 == 0 && i != 2 && i != 7)
		{
			day += 30;
		}
		else if (i == 2)
		{
			day += 28;
			if (flag == true)
			{
				day++;
			}
		}
		else if (i == 7)
		{
			day += 31;
		}
	}
}
void DATE_::day_int_year()
{
	int j = 0;
	for (int i = 1; i <= year; i++)
	{
		day += 365;
		j++;
		if (j == 4)
		{
			day ++;
			j = 0;
		}
	}
}
DATE_::DATE_(int day, int month, int year)
{
	if (day > 31 && day < 0)
	{

	}
	else
	{
		this->day = day;
	}
	if (month > 12 && day < 0)
	{

	}
	else
	{
		if (day == 31)
		{
			if (month == 1, month == 3, month == 5, month == 7, month == 8, month == 10, month == 12)
			{
				this->month = month;
			}
		}
		else
		{
			this->month = month;
		}
		
	}
	this->year = year;
	this->flag = false;
	day_int_year();
	day_in_month();
	to_day();
}

DATE_::~DATE_()
{
}