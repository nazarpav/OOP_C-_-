#pragma once
#include<iostream>
using namespace std;
struct MyTime
{
	short seconds;
	short minutes;
	short hours;
	friend std::ostream& operator<< (std::ostream &out, const MyTime &point);
	friend std::istream& operator>> (std::istream &in, MyTime &point);

	MyTime operator=(MyTime &other)
	{
		this->seconds = other.seconds;
		this->minutes = other.minutes;
		this->hours = other.hours;
		return *this;
	}
	bool operator>(MyTime other)
	{
		bool h =this->seconds > other.seconds&&this->minutes > other.minutes&&this->hours > other.hours;
		return h;
	}
	bool operator<(MyTime other)
	{
		return !(*this > other);
		//return this->seconds < other.seconds&&this->minutes < other.minutes&&this->hours < other.hours;
	}
	MyTime()
	{
		this->seconds = 0;
		this->minutes = 0;
		this->hours = 0;
	}
};
std::ostream& operator<< (std::ostream &out, const MyTime &point)
{
	out << point.seconds << endl << point.minutes << endl << point.hours;
	return out;
}
std::istream& operator>> (std::istream &in, MyTime &point)
{
	in>>  point.seconds >> point.minutes >> point.hours;
	return in;
}