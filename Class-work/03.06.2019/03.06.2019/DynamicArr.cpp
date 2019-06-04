#include <iostream>
#include "DynamicArr.h"
#include <ctime>
using namespace std;
void DynamicArr::fill_rand()
{
	srand(unsigned(time(NULL)));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand()%100+1;
	}
}
void DynamicArr::fill_keyboard()
{
	for (int i = 0; i < size; i++)
	{
		cin>>arr[i];
	}
}
void DynamicArr::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;
}
DynamicArr DynamicArr:: operator+(const DynamicArr&other)const
{
	int new_size = this->size + other.size;
	DynamicArr buf(new_size);
	int j = 0;
	for (int i = 0; i < this->size; i++)
	{
		buf.arr[j] = this->arr[i];
		j++;
	}
	for (int i = 0; i < other.size; i++)
	{
		buf.arr[j] = other.arr[i];
		j++;
	}
	buf.size = new_size;
	return buf;
}
DynamicArr& DynamicArr:: operator=(const DynamicArr&other)
{
	if (this->arr != nullptr)
	{
		delete[]arr;
	}
	arr = new int[other.size];
	this->size = other.size;
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = other.arr[i];
	}
	return *this;
}
bool DynamicArr::operator<(const DynamicArr&other)const
{
	return this->size < other.size;
}
bool DynamicArr::operator>(const DynamicArr&other)const
{
	return this->size > other.size;
}
bool DynamicArr::operator<=(const DynamicArr&other)const
{
	return this->size <= other.size;
}
bool DynamicArr::operator>=(const DynamicArr&other)const
{
	return this->size >= other.size;
}
bool DynamicArr::operator==(const DynamicArr&other)const
{
	if (this->size != other.size)
	{
		return false;
	}
	for (int i = 0; i < this->size; i++)
	{
		if (this->arr[i] != other.arr[i])
		{
			return false;
		}
	}
	return true;
}
bool DynamicArr::operator!=(const DynamicArr&other)const
{
	if (this->size == other.size)
	{
		return false;
	}
	for (int i = 0; i < this->size; i++)
	{
		if (this->arr[i] == other.arr[i])
		{
			return false;
		}
	}
	return true;
}
DynamicArr::DynamicArr(int size)
{
	this->size = size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}

DynamicArr::DynamicArr()
{
	this->arr = nullptr;
	this->size = 0;
}

DynamicArr::DynamicArr(const DynamicArr&obj)
{
	arr = new int[obj.size];
	this->size = obj.size;
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = obj.arr[i];
	}
}
DynamicArr::~DynamicArr()
{
	delete[]arr;
}