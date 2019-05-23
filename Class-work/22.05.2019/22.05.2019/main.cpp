#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include"color.h"
using namespace std;

class rectangle
{
	short height, wight; //coordination
	short x=0, y=0;
public:
	void SetCursor(int x_, int y_) {
		COORD pos = { x_, y_ };
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(output, pos);
	}
	void set_x(int new_x)
	{
		if (new_x <= 0 || new_x > 50)
		{
			return;
		}
		this->x = new_x;
	}
	void set_y(int new_y)
	{
		if (new_y <= 0||new_y > 50)
		{
			return;
		}
		this->y=new_y;
	}
	void set_wight(short new_wight)
	{
		this->wight = new_wight;
	}
	void set_height(short new_height)
	{
		this->height = new_height;
	}
	void HideConsoleCursor()
	{
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(consoleHandle, &info);
	}
	void show()
	{
		system("cls");
		HideConsoleCursor();
		SetConsoleTextAttribute(consoleWndHandle, ConsoleColors::RED);
		for (unsigned short i = 0; i < height; i++)
		{
			SetCursor(x, y + i);
			for (unsigned short j = 0; j < wight; j++)
			{
				cout << char(219);
			}
			cout << endl;
		}
	}
};

int main()
{
	rectangle rectangle_obj;
	short height = 0,wight=0,x=0,y=0;

	cout << "Set height-> ";
	cin >> height;
	rectangle_obj.set_height(height);
	cout << "Set wight-> ";
	cin >> wight;
	rectangle_obj.set_wight(wight);
	system("cls");
	short var = 0;
	while (true)
	{
		_getch();
		var = _getch();
		if (var == 72)
		{
			y--;
			rectangle_obj.set_y(y);
		}
		else if (var == 80)
		{
			y++;
			rectangle_obj.set_y(y);
		}
		else if (var == 75)
		{
			x--;
			rectangle_obj.set_x(x);
		}
		else if (var == 77)
		{
			x++;
			rectangle_obj.set_x(x);
		}
		else
		{
			break;
		}
		rectangle_obj.show();
	}
	rectangle_obj.SetCursor(4*3, 4*3);
	return 0;
}
/*
72-> UP
75-> LEFT
77-> RIGHT
80-> DOWN
*/