#pragma once
class DynamicArr
{
public:
	void fill_rand();
	void fill_keyboard();
	void show();
	DynamicArr operator+(const DynamicArr & other)const;
	DynamicArr& operator=(const DynamicArr & other);
	bool operator<(const DynamicArr & other) const;
	bool operator>(const DynamicArr & other) const;
	bool operator<=(const DynamicArr & other) const;
	bool operator>=(const DynamicArr & other) const;
	bool operator==(const DynamicArr & other) const;
	bool operator!=(const DynamicArr & other) const;
	DynamicArr(int size);
	DynamicArr();
	DynamicArr(const DynamicArr & obj);
	~DynamicArr();

private:
	int *arr;
	int size;
};

