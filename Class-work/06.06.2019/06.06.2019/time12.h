#pragma once
class TIME24;
class TIME12
{
public:
	TIME12(int hour, int minutes, int seconds);
	TIME12(const TIME12& other);
	TIME12();
	void show();
	operator TIME24();

	void to_time(int all_seconds);
	void to_seconds();
	int get_all_seconds()
	{
		return this->all_seconds;
	}
	bool get_pm()
	{
		return this->pm;
	}
private:
	int all_seconds;
	int hour;
	int minutes;
	int seconds;
	bool pm;
};


