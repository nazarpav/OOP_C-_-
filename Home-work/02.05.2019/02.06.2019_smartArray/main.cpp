#include <iostream>
#include <ctime>
#include "Smart_array.h"

using namespace std;
int main()
{
	srand(unsigned(time(NULL)));

	int size1 = 5;
	int size2 = 5;

	int **arr = new int*[size1];

	for (unsigned int i = 0; i < size1; i++)
	{
		arr[i] = new int[size2];
	}

	for (unsigned short i = 0; i < size1; i++)
	{
		for (unsigned short j = 0; j < size2; j++)
		{
			arr[i][j] = rand()%100+1;
		}
	}

	int *arr2 = new int[size1];
	for (unsigned short j = 0; j < size1; j++)
	{
		arr2[j] = rand() % 100 + 1;
	}
	int *arr3 = new int[size1];
	for (unsigned short j = 0; j < size1; j++)
	{
		arr3[j] = rand() % 100 + 1;
	}
	Smart_Array obj(arr,size1,size2);

	obj.Show();
	obj.AddRow(arr2,5);
	obj.AddRow(arr2,5);
	cout << endl;
	obj.Show();

	obj.RemoveRow(1);
	cout << endl;
	obj.Show();

	obj.RemoveCol(1);
	obj.RemoveCol(1);
	cout << endl;
	obj.Show();

	obj.AddCol(2);
	obj.AddCol(2);
	obj.AddCol(2);

	cout << endl;
	obj.Show();

	obj.sort();
	cout << endl;
	obj.Show();

	system("pause");
	return 0;
}