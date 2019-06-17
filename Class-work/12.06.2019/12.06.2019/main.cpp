#include<iostream>
#include <string>
#include "Stack.h"
using namespace std;

int main()
{
	enum en {_1='{',_2='(',_3='[', _4 = '}', _5 = ')', _6 = ']'};
	//string char_= { "{([})]" };
	Stack obj;
	string str;
	string tmp{};
	int ind_flag = 0;
	cout << "Enter string (max=> 10)" << endl;
	cin >> str;

	bool flag = false;
	int ind_ = 0;
	for (int i = 0; i<str.length(); i++)
	{
		switch (str[i])
		{
		case '{':
			obj.Push('{');
			break;
		case '(':
			obj.Push('(');
			break;
		case '[':
			obj.Push('[');
			break;
		case '}':
			if (obj.Pop() != '{')
			{
				obj.Push('}');
				ind_ = i;
				flag = true;
			}	
			break;
		case ')':
			if (obj.Pop() != '(')
			{
				obj.Push(')');
				ind_ = i;
				flag = true;
			}
			break;
		case ']':
			if (obj.Pop() != '[')
			{
				obj.Push(']');
				ind_ = i;
				flag = true;
			}
			break;
		}
		if(flag==true)
		{
			ind_ = i;
			break;
		}
	}
	if (obj.IsEmpty() == false)
	{
		flag = true;
	}
	if (flag == false)
	{
		cout << "GOOD" << endl;
	}
	else
	{
		for (int i = 0; i < ind_; i++)
		{
			cout<<str[i];
		}
		cout << "\nBAD" << endl;
	}



	//for (int i = 0; i < str.length(); i++)
	//{
	//	obj.Push(str[i]);
	//}
	//tmp = obj.Pop();
	//if (tmp[0] != char_[0])
	//{
	//	for (int i = 0; i < str.length(); i++)
	//	{
	//		for (int j = 0; j < char_.length() / 2; j++)
	//		{
	//			if (tmp[0] == char_[j])
	//			{
	//				flag = true;
	//				ind_flag = j;
	//			}
	//		}
	//		tmp = obj.Pop();
	//		if (tmp[0] != char_[ind_flag + 3] && flag == true)
	//		{
	//			true_ = true;
	//			break;
	//			//return;
	//		}
	//		else
	//		{
	//			ind_flag = 0;
	//			flag = false;
	//		}
	//	}
	//}
	//if (true_ == true)
	//{
	//	cout << "GOOD" << endl;
	//}
	system("pause");
	return 0;
}