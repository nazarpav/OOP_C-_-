//#include "Smart_array.h"
//#include <iostream>
//#include <windows.h>
//
//using namespace std;
//Smart_Array::Smart_Array()
//{
//	arr = nullptr;
//	rows = 0;
//	colums = 0;
//	length = nullptr;
//}
//Smart_Array::Smart_Array(int value, int rows, int colums)
//{
//	if (rows <= 0 || colums <= 0)
//	{
//		std::cout << char(7) << "Eror!!!";
//		Sleep(2200);
//		system("cls");
//	}
//	else
//	{
//		this->colums = colums;
//		this->rows = rows;
//		this->arr = new int*[this->rows];
//
//		for (int i = 0; i < this->rows; i++)
//		{
//			this->arr[i] = new int[this->colums];
//		}
//		for (int i = 0; i < this->rows; i++)
//		{
//			for (int j = 0; j < this->colums; j++)
//			{
//				this->arr[i][j] = value;
//			}
//		}
//	}
//}
////Smart_Array::Smart_Array(int**& arr_, int rows, int colums)
////{
////	if (rows <= 0 || colums <= 0)
////	{
////		std::cout << char(7) << "Eror!!!";
////		Sleep(2200);
////		system("cls");
////	}
////	else
////	{
////		this->colums = colums;
////		this->rows = rows;
////		this->arr = new int*[this->rows];
////
////		for (int i = 0; i < this->rows; i++)
////		{
////			this->arr[i] = new int[this->colums];
////		}
////		for (int i = 0; i < this->rows; i++)
////		{
////			for (int j = 0; j < this->colums; j++)
////			{
////				this->arr[i][j] = arr_[i][j];
////			}
////		}
////	}
////}
//Smart_Array::Smart_Array(int**& arr_, int rows, int colums)
//{
//	if (rows <= 0 || colums <= 0)
//	{
//		std::cout << char(7) << "Eror!!!";
//		Sleep(2200);
//		system("cls");
//	}
//	else
//	{
//		length = new int[rows];
//		for (int i = 0; i < rows; i++)
//		{
//			length[i] = colums;
//		}
//		//this->colums = colums;
//		this->rows = rows;
//		this->arr = new int*[this->rows];
//
//		for (int i = 0; i < this->rows; i++)
//		{
//			this->arr[i] = new int[length[i]];
//		}
//		for (int i = 0; i < this->rows; i++)
//		{
//			for (int j = 0; j < length[i]; j++)
//			{
//				this->arr[i][j] = arr_[i][j];
//			}
//		}
//	}
//}
//Smart_Array::~Smart_Array()
//{
//	del_arr();
//}
//
//void Smart_Array::del_arr()
//{
//	if (arr == nullptr)
//		return;
//	for (int i = 0; i < rows; i++)
//	{
//		delete[]arr[i];
//	}
//	delete[]arr;
//}
//void Smart_Array::AddElement(int elem, int index_rows)
//{
//	if (rows == 0)
//	{
//		cout << "Array is EMPTY!!!\n"<<char(7);
//		Sleep(3000);
//		system("cls");
//	}
//	if (length == nullptr)
//	{
//		int *length = new int[this->rows];
//		for (int i = 0; i < rows; i++)
//		{
//			length[i] = 0;
//		}
//	}
//
//	length[index_rows]++;
//	int **Buf_Arr = new int*[rows];
//
//	for (int i = 0; i < rows; i++)
//	{
//		cout<<length[i]<<endl;
//	}
//
//	for (int i = 0; i < rows; i++)
//	{
//		Buf_Arr[i] = new int[length[i]+1];
//	}
//	length[index_rows]--;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < length[i] + 1; j++)
//		{
//			Buf_Arr[i][j] = arr[i][j];
//		}
//	}
//	length[index_rows]++;
//	Buf_Arr[index_rows][length[index_rows]] = elem;
//
//	del_arr();
//
//	arr=Buf_Arr;
//}
//
//void Smart_Array::AddRow(int *row_,int size)
//{
//	rows++;
//	length = (int*)realloc(length, rows * sizeof(int));
//	length[rows - 1] = size;
//	int **Buf_Arr = Buf_Arr = new int*[rows];
//
//	for (int i = 0; i < rows; i++)
//	{
//		Buf_Arr[i] = new int[length[i]];
//	}
//
//	for (int i = 0; i < rows-1; i++)
//	{
//		Buf_Arr[i] = arr[i];
//	}
//	Buf_Arr[rows - 1]=row_;
//
//	arr = Buf_Arr;
//}
//
//void Smart_Array::RemoveRow(int row_)
//{
//	if (row_ > rows || row_ < 0)
//	{
//		cout << char(7);
//		return;
//	}
//	rows--;
//	delete[]arr[row_];
//	int **Buf_Arr = new int*[rows];
//
//	for (int i = 0; i < rows; i++)
//	{
//		Buf_Arr[i] = new int[length[i]];
//	}
//	int j = 0;
//	for (int i = 0; i < rows+1; i++)
//	{
//		if (i == row_) { continue; };
//		Buf_Arr[j] = arr[i];
//		j++;
//	}
//
//	
//	if(rows==0)
//	{
//		arr = nullptr;
//	}
//	else
//	{
//		arr = Buf_Arr;
//	}
//}
//
//void Smart_Array::Show()const
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < length[i]; j++)
//		{
//			std::cout<<arr[i][j]<<" ";
//		}
//		std::cout << std::endl;
//	}
//}
//
//void Smart_Array::Clear()
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < length[i]; j++)
//		{
//			arr[i][j] =0;
//		}
//	}
//}

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
//void Smart_Array::AddElement(int elem, int index_rows)
//{
//	if (rows == 0)
//	{
//		cout << "Array is EMPTY!!!\n"<<char(7);
//		Sleep(3000);
//		system("cls");
//	}
//	if (length == nullptr)
//	{
//		int *length = new int[this->rows];
//		for (int i = 0; i < rows; i++)
//		{
//			length[i] = 0;
//		}
//	}
//
//	length[index_rows]++;
//	int **Buf_Arr = new int*[rows];
//
//	for (int i = 0; i < rows; i++)
//	{
//		cout<<length[i]<<endl;
//	}
//
//	for (int i = 0; i < rows; i++)
//	{
//		Buf_Arr[i] = new int[length[i]+1];
//	}
//	length[index_rows]--;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < length[i] + 1; j++)
//		{
//			Buf_Arr[i][j] = arr[i][j];
//		}
//	}
//	length[index_rows]++;
//	Buf_Arr[index_rows][length[index_rows]] = elem;
//
//	del_arr();
//
//	arr=Buf_Arr;
//}

void Smart_Array::AddRow(int *row_)
{
	rows++;

	int **Buf_Arr = Buf_Arr = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		Buf_Arr[i] = new int[colums];
	}

	for (int i = 0; i < rows - 1; i++)
	{
		Buf_Arr[i] = arr[i];
	}
	Buf_Arr[rows - 1] = row_;

	arr = Buf_Arr;
}

void Smart_Array::RemoveRow(int row_)
{
	if (row_ > rows || row_ < 0)
	{
		cout << char(7);
		return;
	}
	rows--;
	delete[]arr[row_];
	int **Buf_Arr = Buf_Arr = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		Buf_Arr[i] = new int[colums];
	}
	int j = 0;
	for (int i = 0; i < rows + 1; i++)
	{
		Buf_Arr[j] = arr[i];
		if (i == row_) { continue; };
		j++;
	}

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
