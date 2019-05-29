#include "Array.h"
#include <ctime>
#include <iostream>

using namespace std;
void ARRAY::show()
{
	if (arr == nullptr)
	{
		return;
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void ARRAY::del_arr()
{
	//cout << this->arr<<endl;
	for (int i = 0; i < row; i++)
	{
		delete[] this->arr[i];
	}
	//cout << this->arr<<endl;
	delete[] this->arr;
}
void ARRAY::add_row()
{
	srand(unsigned(time(NULL)));

	int ** buf_arr = new int*[row + 1];
	for (int i = 0; i < row+1; i++)
	{
		buf_arr[i] = new int[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			buf_arr[i][j] = arr[i][j];
		}
	}
	for (int j = 0; j < col; j++)
	{
		buf_arr[row][j] = rand() % 10 + 1;
	}
	del_arr();
	arr = buf_arr;
	row++;
}
int ARRAY::min_elem()
{
	if (arr == nullptr)
	{
		return 0;
	}
	int min = 1010000;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] < min)
			{
				min = arr[i][j];
			}
		}
	}
	return min;
}
int ARRAY::max_elem()
{
	if (arr == nullptr)
	{
		return 0;
	}
	int max = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
			}
		}
	}
	return max;
}

ARRAY::ARRAY()
{
	arr = nullptr;
	row = 0;
	col = 0;
}
ARRAY::ARRAY(int row, int col)
{
	srand(unsigned(time(NULL)));

	arr = new int*[row];
	
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
	//cout << this->arr << endl;
	this->col = col;
	this->row = row;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			this->arr[i][j] = rand()%100+1;
		}
	}

}

ARRAY::ARRAY(const ARRAY & ARRAY_):ARRAY()
{
	this->col = ARRAY_.col;
	this->row = ARRAY_.row;
	this->arr = new int*[this->row];

	for (int i = 0; i < this->row; i++)
	{
		this->arr[i] = new int[this->col];
	}
	//cout << this->arr << endl;
	//cout << ARRAY_.arr<<endl;
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->arr[i][j] = ARRAY_.arr[i][j];
		}
	}

}

ARRAY::~ARRAY()
{
	del_arr();
}