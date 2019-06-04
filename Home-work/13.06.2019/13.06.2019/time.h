#pragma once
class TIME
{
public:
	void add_second_to_time();
	void to_seconds();
	void to_time(int time);
	bool operator>(const TIME & obj);
	bool operator<(const TIME & obj);
	bool operator>=(const TIME & obj);
	bool operator<=(const TIME & obj);
	bool operator==(const TIME & obj);
	bool operator!=(const TIME & obj);
	TIME(int time);
	TIME(int hours, int minutes, int seconds);
	TIME(const TIME & other);
	~TIME();

	void show();

private:
	int time;
	int hours;
	int minutes;
	int seconds;
};
