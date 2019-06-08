#include"time24.h"
#include"time12.h"
#include <iostream>
using namespace std;
TIME12::TIME12(int hour, int minutes, int seconds)
{
	this->hour = hour;
	this->minutes = minutes;
	this->seconds = seconds;
	if (hour > 12)
	{
		this->hour = hour % 12;
		pm = true;
	}
}

TIME12::TIME12(const TIME12 & other)
{
	this-> hour= other.hour;
	this-> minutes= other.minutes;
	this-> seconds= other.seconds;
	this-> all_seconds= other.all_seconds;
}

TIME12::TIME12()
{
	hour = 0;
	minutes = 0;
	seconds = 0;
	all_seconds = 0;
}

void TIME12::show()
{
	cout << "\nHours: " << hour << " : Minutes: " << minutes<<":";
	if (!pm)
	{
		cout << "am\n";
	}
	else
	{
		cout << "pm\n";
	}
}

void TIME12::to_time(int all_seconds)
{
	this->hour = all_seconds / 3600;

	this->minutes = (all_seconds - this->hour * 3600) / 60;

	this->seconds = all_seconds - this->hour * 3600 - this->minutes * 60;
	if (hour > 12)
	{
		this->hour = hour % 12;
		pm = true;
	}
}
void TIME12::to_seconds()
{
	if (!pm)
	{
		hour += 12;
	}
	all_seconds = hour * 3600 + minutes * 60 + seconds;
}
TIME12::operator TIME24()
{
	TIME24 obj(this->hour, this->minutes, this->seconds);
	obj.to_seconds(*this);
	obj.to_time(obj.get_all_seconds());
	return obj;
}
