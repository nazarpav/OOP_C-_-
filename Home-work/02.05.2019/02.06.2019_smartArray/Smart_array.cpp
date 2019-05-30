#include "Smart_array.h"
#include <iostream>
#include <windows.h>

using namespace std;
Smart_Array::Smart_Array()
{
	arr = nullptr;
	rows = 0;
	colums = 0;
	length = nullptr;
}
Smart_Array::Smart_Array(int value, int rows, int colums)
{
	if (rows <= 0 || colums <= 0)
	{
		std::cout << char(7) << "Eror!!!";
		Sleep(2200);
		system("cls");
	}
	else
	{
		this->colums = colums;
		this->rows = rows;
		this->arr = new int*[this->rows];

		for (int i = 0; i < this->rows; i++)
		{
			this->arr[i] = new int[this->colums];
		}
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->colums; j++)
			{
				this->arr[i][j] = value;
			}
		}
	}
}
Smart_Array::Smart_Array(int**& arr_, int rows, int colums)
{
	if (rows <= 0 || colums <= 0)
	{
		std::cout << char(7) << "Eror!!!";
		Sleep(2200);
		system("cls");
	}
	else
	{
		this->colums = colums;
		this->rows = rows;
		this->arr = new int*[this->rows];

		for (int i = 0; i < this->rows; i++)
		{
			this->arr[i] = new int[this->colums];
		}
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->colums; j++)
			{
				this->arr[i][j] = arr_[i][j];
			}
		}
	}
}
Smart_Array::~Smart_Array()
{
	del_arr();
}

void Smart_Array::del_arr()
{
	if (arr == nullptr)
		return;
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}

void Smart_Array::AddRow(int *row, int size)
{
	rows++;
	colums = size;
	int *row_ = new int[size];
		for (int i = 0; i < size; i++)
		{
			row_[i] = row[i];
		}

	int **Buf_Arr = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		Buf_Arr[i] = new int[colums];
	}

	for (int i = 0; i < rows - 1; i++)
	{
		Buf_Arr[i] = arr[i];
	}
	Buf_Arr[rows - 1] = row_;
	delete[]arr;
	arr = Buf_Arr;
}

void Smart_Array::AddCol(int col)
{
	if (col > colums || col < 0)
	{
		cout << char(7);
		return;
	}
	colums++;
	int **Buf_Arr = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		Buf_Arr[i] = new int[colums];
	}
	int g = 0;
	for (int i = 0; i < rows; i++)
	{
		g = 0;
		for (int j = 0; j < colums; j++)
		{
			if (j == col)
			{
				Buf_Arr[i][j] = rand() % 100 + 1;
				continue;
			};
			Buf_Arr[i][j] = arr[i][g];
			g++;
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	for (int i = 0; i < rows; i++)
	{
		arr[i] = Buf_Arr[i];
	}
	delete[]Buf_Arr;
}
void Smart_Array::RemoveCol(int col)
{
	if (col > colums || col < 0)
	{
		cout << char(7);
		return;
	}
	colums--;
	int **Buf_Arr =new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		Buf_Arr[i] = new int[colums];
	}
	int g = 0;
	for (int i = 0; i < rows; i++)
	{
		g = 0;
		for (int j = 0; j < colums+1; j++)
		{
			if (j == col) { continue; };
			Buf_Arr[i][g] = arr[i][j];
			g++;
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	for (int i = 0; i < rows; i++)
	{
		arr[i] = Buf_Arr[i];
	}
	delete[]Buf_Arr;
}

void Smart_Array::RemoveRow(int row)
{
	if (row > rows || row < 0)
	{
		cout << char(7);
		return;
	}
	rows--;
	delete[]arr[row];
	int **Buf_Arr = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		Buf_Arr[i] = new int[colums];
	}
	int j = 0;
	for (int i = 0; i < rows + 1; i++)
	{
		if (i == row) { continue; };
		Buf_Arr[j] = arr[i];
		j++;
	}
	delete[]arr;
	arr = Buf_Arr;
}

void Smart_Array::Show()const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Smart_Array::Clear()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			arr[i][j] = 0;
		}
	}
}