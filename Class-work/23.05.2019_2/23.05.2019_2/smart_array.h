#pragma once
#include <iostream>
#include <string>
using namespace std;

class SMART_CLASS
{
	int * arr;
	int size;
public:
	void add_elem();
	void del_elem();
	void show_arr();
	SMART_CLASS();
	~SMART_CLASS();
	SMART_CLASS(int elem, const int & _size);
	SMART_CLASS(int *_arr, const int &_size);
};