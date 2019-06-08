#include"time24.h"
#include"time12.h"
#include <iostream>
using namespace std;
TIME24::TIME24(int hour, int minutes, int seconds)
{
	this->hour = hour;
	this->minutes = minutes;
	this->seconds = seconds;

}
TIME24::TIME24(const TIME24 & other)
{
	this->hour = other.hour;
	this->minutes = other.minutes;
	this->seconds = other.seconds;
	this->all_seconds = other.all_seconds;
}
void TIME24::to_seconds(TIME12 & obj_)
{
	if (obj_.get_pm())
	{
		hour += 12;
	}
	all_seconds = hour * 3600 + minutes * 60 + seconds;
}
TIME24::TIME24()
{
	hour=0;
	minutes=0;
	seconds=0;
	all_seconds=0;
}

void TIME24::show()
{
	cout << "\nHours: " << hour << " : Minutes: " << minutes << " : Seconds: " << seconds << endl;
}

void TIME24::to_time(int all_seconds)
{
	this->hour = all_seconds / 3600;

	this->minutes = (all_seconds - this->hour * 3600) / 60;

	this->seconds = all_seconds - this->hour * 3600 - this->minutes * 60;
}

TIME24::operator TIME12()
{
	TIME12 obj(this->hour, this->minutes, this->seconds);
	obj.to_seconds();
	obj.to_time(obj.get_all_seconds());
	return obj;
}