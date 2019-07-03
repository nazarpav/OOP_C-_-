#include <iostream>
#include <string>
using namespace std;

int main()
{
	int convert=0;
	char data[]="0132123";
//	cin >> data;
	int counter = 1;
	int tmp = 0;
	if (char(data[0])-48 == 0)
		cout << "eror\n";

	for (int i = strlen(data)-1; i >= 0; i--)
	{
		tmp = char(data[i]);
		if (tmp > 57 || tmp < 48||tmp-48<0)
			cout << "eror\n";
		tmp -=48;
		convert +=tmp* counter;
		counter*=10;
	}
	cout << convert;
	system("pause");
	return 0;
}
