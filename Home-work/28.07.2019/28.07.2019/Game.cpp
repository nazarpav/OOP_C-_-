#include "Game.h"
#include "Template_menu.h"
#include <string>
#include <iostream>
#include <windows.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;
void Game::Render_map()
{
	cout << " 0\n0";
	for (short i = 0; i < size_map; i++)
	{
		for (short j = 0; j < size_map; j++)
		{
			cout << char(197) << char(196) << char(197);
			Set_cursor(i+1, j);
			cout << char(124);
			switch (game_map[i][j])
			{
			case Game::type::NULL_:
				cout << "@";
				break;
			case Game::type::ZERO:
				cout << "0";
				break;
			case Game::type::CROSS:
				cout << "X";
				break;
			}
			cout << char(124);
			Set_cursor(i, j+3);
		}
		cout << endl<<" ";
	}
}
void Game::Set_cursor(short x, short y)
{
	COORD position = { x,y };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}
bool Game::Check_win()
{
	bool win=false;
	for (short g = 0; g < size_map; g++)
	{
		if (game_map[g][0] == -1)
		{
			win = false;
			continue;
		}
		for (short i = 1; i < size_map; i++)
		{
			if (game_map[g][i] == -1)
			{
				win = false;
				break;
			}
			if (game_map[g][0] == game_map[g][i])
				win = true;
			else
				win = false;
			break;
		}
		if (win)
			return win;
	}
	for (short g = 0; g < size_map; g++)
	{
		if (game_map[g][0] == -1)
		{
			win = false;
			continue;
		}
		for (short i = 1; i < size_map; i++)
		{
			if (game_map[g][i] == -1)
			{
				win = false;
				break;
			}
			if (game_map[0][g] == game_map[i][0] && game_map[size_map - 1][0] != -1)
				win = true;
			else
				win = false;
			break;
		}
		if (win)
			return win;
	}
	short it_1 = 0, it_2 = 0;
	for (short i = 1; i < size_map&&game_map[0][0]!=-1; i++)
	{
		if (game_map[i][i] == -1)
		{
			win = false;
			break;
		}
		if (game_map[0][0] == game_map[i][i])
			win = true;
		else
		{
			win = false;
			break;
		}
	}
	if (win)
		return win;
	it_1 = size_map - 1;
	it_2 =0;
	for (short i = 0; i < size_map&&game_map[0][size_map - 1] != -1; i++)
	{
		if (game_map[it_1][it_2] == -1)
		{
			win = false;
			break;
		}
		if (game_map[size_map - 1][0] == game_map[it_1--][it_1++])
			win = true;
		else
		{
			win = false;
			break;
		}
	}
	if (win)
		return win;
	return win;
}
void Game::Copm_logic(short true_sign,short false_sign)
{
	for (short j = 0; j < size_map; j++)
	{
		for (short i = 0; i < size_map; i++)
		{
			if (game_map[j][i] == true_sign && game_map[j][i + 1] != false_sign)
			{
				game_map[j][i + 1] = true_sign;
				return;
			}
		}
	}
	for (short j = 0; j < size_map; j++)
	{
		for (short i = 0; i < size_map; i++)
		{
			if (game_map[i][j] == true_sign && game_map[i][j + 1] != false_sign)
			{
				game_map[i][j + 1] = true_sign;
				return;
			}
		}
	}
	short it_1 = 0, it_2 = 0;
	for (short i = 0; i < size_map; i++)
	{
		it_1++;
		it_2++;
		if (true_sign == game_map[it_1][it_2] && game_map[it_1][it_2] != false_sign)
			game_map[it_1][it_2] = true_sign;
	}
	it_1 = size_map - 1;
	it_2 = 0;
	for (short i = 0; i < size_map; i++)
	{
		it_1--;
		it_2++;
		if (true_sign == game_map[it_1][it_2] && game_map[it_1][it_2] != false_sign)
			game_map[it_1][it_2] = true_sign;
	}
}
bool Game::Start_game_()
{
	const short SIZE_Select_type_game = 3;
	const string Select_type_game[SIZE_Select_type_game] =
	{ 
		"Player and computer",
		"Player and player",
		"Computer and computer "
	};
	string name_1, name_2;
	switch (Template_menu::template_menu(Select_type_game, SIZE_Select_type_game))
	{
	case 1:
		cout << "Enter your name:  ";
		cin >> name_1;
		Game_player_and_comp(name_1);
		break;
	case 2:
		cout << "Enter your name 1:  ";
		cin >> name_1;
		cout << "Enter your name 2:  ";
		cin >> name_2;
		Game_player_and_player(name_1, name_2);
		break;
	case 3:
		Game_copm_and_comp();
		break;
	default:
		throw "Eror";
		break;
	}
	return false;
}

/////////////////////////////////////////////////
/////////////////////////////////////////////////

void Game::Player_move(const string name, const short sign)
{
	short x = 0, y = 0;
	while (true)
	{
		system("cls");
		Render_map();
		cout << "Player:" << name << "\n\nEnter coordination x:";
		cin >> x;
		cout << "\nEnter coordination y:";
		cin >> y;
		if (x > size_map || x < 0 || y > size_map || y < 0 )
		{
			cout << "Eror <<<<<<<<=\n\n" << endl;
			system("pause");
			system("cls");
		}
		else
		{
		if (game_map[x][y] != -1)
		{
			cout << "Eror <<<<<<<<=\n\n" << endl;
			system("pause");
			system("cls");
		}
		else
			break;
		}
	}
	game_map[x][y] = sign;
}

bool Game::Game_player_and_player(const string name_1, const string name_2)
{
	system("cls");
	short first_move = Rand_();

	if (first_move == 0)
	{
		first_move = -1;
		Player_move(name_1, Game::type::ZERO);
	}
	while (true)
	{
		Player_move(name_2, Game::type::CROSS);
		if (Check_win())
		{
			system("cls");
			cout << "Player: " << name_2 << " is winer!!!\n";
			Render_map();
			system("pause");
			break;
		}
		Player_move(name_1, Game::type::ZERO);
		if (Check_win())
		{
			system("cls");
			cout << "Player: " << name_1 << " is winer!!!\n";
			Render_map();
			system("pause");
			break;
		}
	}
	return false;
}

bool Game::Game_copm_and_comp()
{
	system("cls");
	Render_map();
	cout << Check_win();
	return false;
}

bool Game::Game_player_and_comp(const string name)
{
	system("cls");
	Render_map();
	return false;
}

/////////////////////////////////////////////////
/////////////////////////////////////////////////

Game::Game(short size_map)
{
	this->size_map = size_map;
	game_map = new short*[size_map];
	for (short i = 0; i < size_map; i++)
	{
		game_map[i] = new short(size_map);
		for (short j = 0; j < size_map; j++)
		{
			game_map[i][j] = Game::type::NULL_;
		}
	}
}

Game::Game(string name_1, string name_2, short size_map=3):Game(size_map)
{
	Game_player_and_player(name_1, name_2);
}

Game::Game(string name_1, short size_map=3) : Game(size_map)
{
	Game_player_and_comp(name_1);
}


Game::~Game()
{
	/*for (short i = 0; i < size_map; i++)
	{
		delete[] game_map[i];
	}
	delete[] game_map;*/
}
