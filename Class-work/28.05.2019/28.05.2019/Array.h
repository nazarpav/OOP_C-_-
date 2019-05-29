#pragma once
#include <ctime>
#include <iostream>
class ARRAY
{
public:
	ARRAY();
	ARRAY(int elem, int row, int col);
	ARRAY(const ARRAY &ARRAY_);
	~ARRAY();
	void show();
	void del_arr();
	void add_row();
	int min_elem();
	int max_elem();
private:
	int **arr;
	int row;
	int col;
	
};



