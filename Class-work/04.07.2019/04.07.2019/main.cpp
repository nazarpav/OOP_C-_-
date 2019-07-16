#include<iostream>
//#include""

using namespace std;
int main()
{
	int col=0, row = 0;
	cin >> col>>row;
	int **arr = new int*[row];
	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cin>>arr[i][j];
		}
	}
	for (int i = row-1; i >= 0; i--)
	{
		for (int j= col-1; j >= 0; j--)
		{
			cout<<arr[i][j]<<" ";
		}
		cout << endl;
	}
	for (size_t i = 0; i < row; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
	//system("pause");
	return 0;
}