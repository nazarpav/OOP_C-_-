#include<iostream>
#include<string>
#include"queue.h"
#include<conio.h>
#include<ctime>

using namespace std;

int main()
{
	srand(unsigned(time(NULL)));
	char button = 0;
	int score=0;
	game _1;
	game _2;
	game _3;
	char __1;
	char __2;
	char __3;
	cout << "PRES |\n     V\n";
	while (true)
	{
		_getch();
		button = _getch();
		if (button == 72 || button == 80)
		{
			system("cls");
			if (button == 72)
			{
				break;
			}
			else if (button == 80)
			{
				short tmp = rand() % 6 + 1;
				for (short i = 0; i < tmp - 1; i++)
				{
					_1.get();
				}
				__1 = _1.get();
				tmp = rand() % 6 + 1;
				for (short i = 0; i < tmp - 1; i++)
				{
					_2.get();
				}
				__2 = _2.get();
				tmp = rand() % 6 + 1;
				for (short i = 0; i < tmp - 1; i++)
				{
					_3.get();
				}
				__3 = _3.get();
				cout << "|===|\n|" << __1 << __2 << __3 << "|\t\t^Exit  v to game\n|===|\n" << endl;
				if (__1 == __2 && __2 == __3)
				{
					score += 50;
					cout << "GREAT!!!\n\n";
					system("pause");
				}
				else
				{
					score -= 1;
				}
				cout << " Score = > " << score << endl;
			}
		}
	}

	//system("pause");
	return 0;
}
/*
72-> UP
75-> LEFT
77-> RIGHT
80-> DOWN
*/
