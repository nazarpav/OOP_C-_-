#pragma once
class TIME12;
class TIME24
{
public:
	TIME24(int hour,int minutes,int seconds);
	TIME24(const TIME24& other);
	void to_seconds(TIME12 & obj_);
	TIME24();
	void show();
	
	void to_time(int all_seconds);
	operator TIME12();
	int get_all_seconds()
	{
		return this->all_seconds;
	}
private:
	int all_seconds;
	int hour;
	int minutes;
	int seconds;
};

