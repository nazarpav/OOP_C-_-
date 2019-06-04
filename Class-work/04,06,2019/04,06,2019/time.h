#pragma once
class TIME
{
public:
	enum Operation { ADD, SUB };

	void add_second_to_time();
	int to_seconds(int hours, int minutes, int seconds);
	void to_seconds();
	void to_time(int time);
	bool operator>=(const TIME & obj);
	bool operator<=(const TIME & obj);
	bool operator!=(const TIME & obj);
	void operator()(int hours, int minutes, int seconds);
	void operator()(int time);

	friend bool operator==(const TIME & obj1, const TIME & obj2);
	friend TIME operator--(TIME&other);
	friend TIME operator++(TIME&other);

	TIME operator++(int tmp);
	TIME(int time);
	TIME(int hours, int minutes, int seconds);
	TIME(const TIME & other);
	~TIME();
	int get_time()
	{
		return this->time;
	}
	void set_time(int num, Operation op)
	{
		op == ADD ? this->time++:op== SUB ? this->time--: this->time+0;
	}
	int get_hours()
	{
		return this->hours;
	}
	int get_minutes()
	{
		return this->minutes;
	}
	int get_seconds()
	{
		return this->seconds;
	}
	void show();

private:
	int time;
	int hours;
	int minutes;
	int seconds;
};
