#pragma once
#include <iostream>
#include <string>
#include <conio.h>
using  std::cout;
using  std::endl;
using  std::string;
class Template_menu
{
public:
	static const int template_menu(const string menu[], const unsigned short size)
	{
		for (unsigned short i = 0; i < size; i++)
		{
			if (i == 0)
			{
				cout << "[ " << menu[i] << " ]" << endl;
				continue;
			}
		cout << menu[i] << endl;
		}
		unsigned short choise = 1;
		char Control_Symbol{};
		while (Control_Symbol != 13)
		{
			Control_Symbol = _getch();
			if (Control_Symbol != 72 && Control_Symbol != 80)
			{
				continue;
			}
			else
			{
				Control_Symbol == 72 ? choise-- : choise++;
				if (choise == 0)
				{
					choise++;
					continue;
				}
				else if (choise > size)
				{
					choise--;
					continue;
				}
			}
			system("cls");
			for (unsigned short i = 0; i < size; i++)
			{
				if (i + 1 == choise)
				{
					cout << "[ " << menu[i] << " ]" << endl;
					continue;
				}
				cout << menu[i] << endl;
			}
		}
		return choise;
	}
};

