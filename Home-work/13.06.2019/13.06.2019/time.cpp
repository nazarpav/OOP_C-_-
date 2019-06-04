#include<iostream>
#include"time.h"
using namespace std;
void TIME::add_second_to_time()
{
	this->time++;
	to_time(this->time);
}
void TIME::to_seconds()
{
	time = hours * 3600 + minutes * 60 + seconds;
}
void TIME::to_time(int time)
{
	this->hours = time / 3600;

	this->minutes = (time - this->hours * 3600) / 60;

	this->seconds = time - this->hours * 3600 - this->minutes * 60;
}
bool TIME::operator >(const TIME& obj)
{
	return this->time > obj.time;
}
bool TIME::operator <(const TIME& obj)
{
	return this->time < obj.time;
}
bool TIME::operator >=(const TIME& obj)
{
	return this->time >= obj.time;
}
bool TIME::operator <=(const TIME& obj)
{
	return this->time <= obj.time;
}
bool TIME::operator ==(const TIME& obj)
{
	return this->time == obj.time;
}
bool TIME::operator !=(const TIME& obj)
{
	return this->time != obj.time;
}
TIME::TIME(int time)
{
	to_time(time);
	this->time = time;
}
TIME::TIME(int hours, int minutes, int seconds)
{
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
	to_seconds();
}
TIME::TIME(const TIME & other)
{
	this->hours = other.hours;
	this->minutes = other.minutes;
	this->seconds = other.seconds;
	this->time = other.time;
}
TIME::~TIME()
{
}
void TIME::show()
{
	cout << this->hours << endl;
	cout << this->minutes << endl;
	cout << this->seconds << endl;
}