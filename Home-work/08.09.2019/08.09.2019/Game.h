#pragma once
#include<iostream>
#include<string>
#include<array>
#include<ctime>
#include<conio.h>
#include<Windows.h>
#include"Console_colors.h"
using namespace std;
const int size_w = 35;
const int size_h = 26;
class Game
{
	array<array<string, size_w+1>, size_h> map;
	short player_pos_x,player_pos_y;
	string buf_to_render_map;
	short counter_win;
	bool flag_first;
	const string STRATEGY[7] = { { "Strategy | KEY\n" }
	,{" - 1 | KEY \'1\'or\'c\'\n"}
	,{" - 3 | KEY \'4\'or\'d\'\n"}
	,{" - 6 | KEY \'7\'or\'e\'\n"}
	,{" + 2 | KEY \'2\'or\'v\'\n"}
	,{" + 4 | KEY \'5\'or\'f\'\n"}
	,{" + 7 | KEY \'8\'or\'r\'\n"}
	};
	void Create_map();
	void Render(string strategy_ );
	bool IS_game_over();
	bool IS_WIN();
	bool Start_game();
	inline int Random(int num)
	{
		return rand() % num;
	}
	inline void Console_clear()
	{
		system("cls");
	}
	inline void HideConsoleCursor()
	{
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(consoleHandle, &info);
	}
	inline void SetCursor(short x, short y) {
		COORD pos = { x, y };
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(output, pos);
	}
	inline void Set_color(ConsoleColors color)
	{
		SetConsoleTextAttribute(consoleWndHandle, color);
	}
	inline string Strategy1();
	inline string Strategy2();
	inline string Strategy4();
	inline string Strategy5();
	inline string Strategy7();
	inline string Strategy8();
public:
	Game();
	inline void To_game(Game& obj)
	{
		while (obj.Start_game())
		{
		}
	}
	~Game();
};