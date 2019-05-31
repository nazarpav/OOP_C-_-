#pragma once

class DATE_
{
public:
	DATE_(int day, int month, int year);
	~DATE_();
	void show();

	int operator-(DATE_ & other);

	int operator+(DATE_ & other);
	
private:
	void day_in_month();
	void day_int_year();
	bool flag;
	int _day;
	int day;
	int month;
	int year;
	void to_day();
	void year_();
};
