#include <iostream>
#include <ctime>
#include "Smart_array.h"

using namespace std;
int main()
{
	srand(unsigned(time(NULL)));
	int **arr = new int*[5];

	for (unsigned int i = 0; i < 5; i++)
	{
		arr[i] = new int[5];
	}

	for (unsigned short i = 0; i < 5; i++)
	{
		for (unsigned short j = 0; j < 5; j++)
		{
			arr[i][j] = rand()%100+1;
		}
	}

	int *arr2 = new int[5];
	for (unsigned short j = 0; j < 5; j++)
	{
		arr2[j] = rand() % 100 + 1;
	}

	Smart_Array obj;

	obj.Show();
	obj.AddRow(arr2);
	obj.AddRow(arr2);
	//obj.AddRow(arr2,5);
	cout << endl;
	obj.Show();

	obj.RemoveRow(1);
	cout << endl;
	obj.Show();
	system("pause");
	return 0;
}