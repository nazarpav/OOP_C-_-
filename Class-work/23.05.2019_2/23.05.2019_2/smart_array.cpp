#include "smart_array.h"

void SMART_CLASS::add_elem()
{
	int *buf_arr = new int[size+1];
	size++;
	int buf = 0;
	for (int i = 0; i < size-1; i++)
	{
		buf_arr[i] = arr[i];
	}
	cout << "Enter write data-> ";
	cin >> buf;
	buf_arr[size - 1] = buf;
	delete[] arr;
	arr = buf_arr;
	cout << arr[0] << endl;
}

void SMART_CLASS::del_elem()
{
	size--;
	int *buf_arr = new int[size];
	for (int i = 0; i < size-1; i++)
	{
		buf_arr[i] = arr[i];
	}
	delete[] arr;
	arr = buf_arr;
}

void SMART_CLASS::show_arr()
{
	for (int i = 0; i < size; i++)
	{
		cout<<"-> "<<arr[i]<<endl;
	}
}

SMART_CLASS::SMART_CLASS()
{
	arr = nullptr;
	size = 0;
}
SMART_CLASS::~SMART_CLASS()
{
	cout << "Bye!\n";
	system("pause");
	delete[] arr;
}
SMART_CLASS::SMART_CLASS(int elem,const int &_size)
{
	arr = new int[size];
	size = _size;
	for (int i = 0; i < _size; i++)
	{
		arr[i] = elem;
	}
}
SMART_CLASS::SMART_CLASS(int *_arr, const int & _size)
{
	arr = new int[size];
	size = _size;
	for (int i = 0; i < _size; i++)
	{
		arr[i] = _arr[i];
	}
}
