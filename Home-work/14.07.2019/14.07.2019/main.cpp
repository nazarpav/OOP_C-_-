#include<iostream>
#include<string>
//#include"Queue.h"
using namespace std;

//enum sign_operation { plus = 1, minus = -1, mult = 2, div = -2, null_ = 0 };
//double res(string data)
//{
//	Queue queue;
//	int left = 0;
//	int right = 0;
//	for (int i = data.length()-1; i >=0;  i--)
//	{
//		if (!(isdigit(data[i])))
//		{
//			throw "Eror digit";
//		}
//		i--;
//		right = data[i];
//		switch (data[i])
//		{
//		case '+':
//			break;
//		case '-':
//			break;
//		case '*':
//			break;
//		case '/':
//			break;
//		default:
//			throw "Error sign operation";
//			break;
//		}
//		i--;
//		if (!(isdigit(data[i])))
//		{
//			throw "Eror digit";
//		}
//	}
//
//}
double res(string data)
{
	int left = 0;
	int right = 0;
	for (int i = 0 ; data.length()!=3; i++)
	{
		if (!(isdigit(data[i]))&&data[i]!='+'&&data[i] != '-'&&data[i] != '*'&&data[i] != '/'&&data[i] != ' ')
		{
			throw "Eror digit or sign operation";
		}
		if (data[i] == '*' || data[i] == '/')
		{
			int tmp_ind = i;
			int tmp_ind2 = 0;
			for (; true;)
			{
				if (isdigit(data[i]))
				{
					right = data[i];
					tmp_ind2 = i;
					break;
				}
				i++;
			}
			i = tmp_ind;
			for (;true;)
			{
				if (isdigit(data[i]))
				{
					left = data[i];
					break;
				}
					i--;
			}
			if (data[tmp_ind] == '*')
			{
				data.insert(tmp_ind,to_string(left*right));
			}
			else
			{
				data.insert(tmp_ind, to_string(left/right));
			}
			i = tmp_ind2;
		}
	}
	return stod(data);
}
int main()
{
	string data = "3*3/2";
	cout << res(data);
	system("pause");
	return 0;
}