#include <iostream>
#include <string>
using namespace std;
class NOT_INTEGER
{
public:
	static void Show()
	{
		cout << "Not integer\n";
	}
};
class NUM_IS_LARGE
{
public:
	static void Show()
	{
		cout << "Num is large\n";
	}
};
int main()
{
	const signed long long int max_int = 2147483647;
	long long convert=0;
	char data[]="-214s7483649";
	long long counter = 1;
	long long tmp = 0;
	try
	{
		for (int i = strlen(data) - 1; i >= 1; i--)
		{
			tmp = char(data[i]);
			if (tmp > 57 || tmp < 48 || tmp - 48 < 0 && data[i] != '-')
			{
				throw(NOT_INTEGER());
			}
			tmp -= 48;
			convert += tmp * counter;
			counter *= 10;
		}

		if (data[0] == '-')
		{
			convert -= convert * 2;
		}
		else if(data[0]!='0'&& char(data[0]) < 57 || char(data[0]) > 48 || char(data[0]) - 48 < 0)
		{ 
			convert += (char(data[0])-48)* counter;
		}
		if (convert<(max_int-max_int*2-1) || convert>max_int)
			throw(NUM_IS_LARGE());
	}
	catch (NOT_INTEGER)
	{
		NOT_INTEGER::Show();
		system("pause");
		return 0;
	}
	catch (NUM_IS_LARGE)
	{
		NUM_IS_LARGE::Show();
		system("pause");
		return 0;
	}
	cout << convert;
	system("pause");
	return 0;
}
