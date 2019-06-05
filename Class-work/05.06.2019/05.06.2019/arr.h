#pragma once
class ARR
{
public:
	ARR(int num, int size);
	const int operator[](const int ind)const;
	void operator()(int ind);
	~ARR();
	void show()const;
	operator int();
	operator char*();
private:
	friend std::ostream& operator <<(std::ostream& out, const ARR& obj);
	int *arr;
	int size;
};

