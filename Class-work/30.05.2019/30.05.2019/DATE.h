#pragma once

class DATE_
{
public:
	void day_in_month();
	void day_int_year();
	DATE_(int day, int month, int year);
	~DATE_();
	void show();
	int operator-(const DATE_ & other)const;

	int operator+(const DATE_ & other)const;
	
private:
	bool flag;
	int _day;
	int day;
	int month;
	int year;
	void to_day();
	void year_();
};
