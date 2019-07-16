#pragma once
#include<iostream>
using namespace std;
struct MyTime
{
	short seconds;
	short minutes;
	short hours;
	short day;
	short month;
	short year;
	friend std::ostream& operator<< (std::ostream &out, const MyTime &point);
	friend std::istream& operator>> (std::istream &in, MyTime &point);

	MyTime operator=(MyTime &other)
	{
		this->seconds = other.seconds;
		this->minutes = other.minutes;
		this->hours = other.hours;
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
		return *this;
	}
	bool operator>(MyTime other)
	{
		return this->seconds > other.seconds&&this->minutes > other.minutes&&this->hours > other.hours&&this->day > other.day&&this->month > other.month&&this->year > other.year;
	}
	bool operator<(MyTime other)
	{
		return !(*this > other);
		//return this->seconds < other.seconds&&this->minutes < other.minutes&&this->hours < other.hours&&this->day < other.day&&this->month < other.month&&this->year < other.year;
	}
	MyTime()
	{
		this->seconds = 0;
		this->minutes = 0;
		this->hours = 0;
		this->day = 0;
		this->month = 0;
		this->year = 0;
	}
};
std::ostream& operator<< (std::ostream &out, const MyTime &point)
{
	out << point.seconds << endl << point.minutes << endl << point.hours << endl<<point.day << endl << point.month << endl << point.year;
	return out;
}
std::istream& operator>> (std::istream &in, MyTime &point)
{
	in>>  point.seconds >> point.minutes >> point.hours >> point.day >> point.month >> point.year;
	return in;
}