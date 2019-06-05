#include <iostream>
#include<ostream>
#include "arr.h"
using namespace std;

std::ostream& operator <<(std::ostream& out, const ARR& obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		out << obj.arr[i] << " ";
	}
	out << endl;
	return out;
}
ARR::ARR(int num, int size)
{
	this->arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = num;
	}
	this->size = size;
}
const int ARR::operator[](const int ind)const
{
	if (ind > size || ind < 0)
	{
		cout << char(7);
		return 0;
	}
	return this->arr[ind];
}
void ARR::operator()(int num)
{
	for (int i = 0; i < size; i++)
	{
		this->arr[i] += num;
	}
}
ARR::~ARR()
{
	delete[]arr;
}

void ARR::show()const
{
	for (int i = 0; i < size; i++)
	{
		cout<<this->arr[i]<<" ";
	}
	cout << endl;
}

ARR::operator int()
{
	int buf = 0;
	for (int i = 0; i < size; i++)
	{
		buf+=this->arr[i];
	}
	return buf;
}
ARR::operator char*()
{
	char* buf = new char[this->size+1];
	char* buf_=new char [10];
	for (int i = 0; i < size; i++)
	{
		_itoa_s(this->arr[i], buf,size-1, 10);
		//strcpy_s(buf[i],strlen(buf_), buf_);
	}
	buf[size] = '\0';
	return buf;
}
