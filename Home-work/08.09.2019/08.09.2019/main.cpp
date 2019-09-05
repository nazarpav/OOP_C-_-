#include"Game.h"
int main()
{
	//Game obj;

	float a = 2000.0f;
	float b = 0.1f;
	int counter = 0;
	while (b < a)
	{
		b += 0.1f;
		cout << b << " ";
		counter++;
	}
	cout << endl << counter << endl;
	system("pause");
	return 0;
}