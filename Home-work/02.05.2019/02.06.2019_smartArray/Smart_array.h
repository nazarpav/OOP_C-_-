#pragma once
class Smart_Array
{
public:

	Smart_Array();
	Smart_Array(int value, int rows, int colums);
	Smart_Array(int **& arr, int rows, int colums);
	~Smart_Array();


	void AddRow(int * row,int size);
	void AddCol(int col);
	void sort();
	void RemoveCol(int col);
	void RemoveRow(int row_);
	void Show() const;
	void Clear();
	void del_arr();

private:
	int **arr;
	int rows, colums;
};

