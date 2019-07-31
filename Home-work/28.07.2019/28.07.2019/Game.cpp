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
	short it_x = 0, it_y = 0;
	for (short i = 0; i < size_map; i++)
	{
		for (short j = 0; j < size_map; j++)
		{
			cout << char(197) << char(196) << char(196) << char(196) << char(197);
			Set_cursor(it_x, it_y +1);
			cout << char(179);
			switch (game_map[i][j])
			{
			case Game::type::NULL_:
				cout << " " << char(176) << " ";
				break;
			case Game::type::ZERO:
				cout << " 0 ";
				break;
			case Game::type::CROSS:
				cout << " X ";
				break;
			}
			cout << char(179);
			Set_cursor(it_x, it_y + 2);
			cout << char(197) << char(196) << char(196) << char(196) << char(197);
			Set_cursor(it_x+5, it_y);
			it_x += 5;
		}
		cout << endl<<endl<<endl;
	it_x = 0;
	it_y += 3;
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
			{
				win = false;
				break;
			}
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
			if (game_map[0][g] == game_map[i][0])
				win = true;
			else
			{
				win = false;
				break;
			}
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
	// '-' collums
	// '+' rows
	short max_quantity_sing_ind = 0;
	short counter_sing_max = -1;
	short counter_sing = 0;
	for (short i = 0; i < size_map; i++)
	{
		counter_sing = 0;
		if (game_map[i][0] == false_sign)
			continue;
		for (short j = 0; j < size_map; j++)
		{
			if (game_map[i][0] == game_map[i][j]&&game_map[i][j] == true_sign)
				counter_sing++;
		}
		if (counter_sing > counter_sing_max)
		{
			max_quantity_sing_ind = i;
			counter_sing_max = counter_sing;
		}
	}
	for (short i = 0; i < size_map; i++)
	{
		counter_sing = 0;
		if (game_map[0][i] == false_sign)
			continue;
		for (short j = 0; j < size_map; j++)
		{
			if (game_map[0][i] == game_map[j][i] && game_map[j][i] == true_sign)
				counter_sing++;
		}
		if (counter_sing > counter_sing_max)
		{
			max_quantity_sing_ind = i - (i * 2);
			counter_sing_max = counter_sing;
		}
	}
	if(max_quantity_sing_ind<0)
	{
		max_quantity_sing_ind = abs(max_quantity_sing_ind);
		for (short i = 0; i < size_map; i++)
		{
			if(game_map[i][max_quantity_sing_ind]== NULL_)
			{
				game_map[i][max_quantity_sing_ind] = true_sign;
				return;
			}
		}
	}
	else
	{
		for (short i = 0; i < size_map; i++)
		{
			if (game_map[max_quantity_sing_ind][i] == NULL_)
			{
				game_map[max_quantity_sing_ind][i] = true_sign;
				return;
			}
		}
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
			Render_map();
			cout << "Player: " << name_2 << " is winer!!!\n";
			system("pause");
			break;
		}
		Player_move(name_1, Game::type::ZERO);
		if (Check_win())
		{
			system("cls");
			Render_map();
			cout << "Player: " << name_1 << " is winer!!!\n";
			system("pause");
			break;
		}
	}
	return false;
}

bool Game::Game_copm_and_comp()
{
	system("cls");
	short first_move = Rand_();

	if (first_move == 0)
	{
		first_move = -1;
		Copm_logic(Game::type::ZERO, Game::type::CROSS);
	}
	while (true)
	{
		Copm_logic(Game::type::CROSS, Game::type::ZERO);
		if (Check_win())
		{
			system("cls");
			Render_map();
			cout << "Player: " << "comp_2" << " is winer!!!\n";
			system("pause");
			break;
		}
		Copm_logic(Game::type::ZERO, Game::type::CROSS);
		if (Check_win())
		{
			system("cls");
			Render_map();
			cout << "Player: " << "comp_1" << " is winer!!!\n";
			system("pause");
			break;
		}
	}
	return false;
}

bool Game::Game_player_and_comp(const string name)
{
	system("cls");
	short first_move = Rand_();

	if (first_move == 0)
	{
		first_move = -1;
		Player_move(name, Game::type::ZERO);
	}
	while (true)
	{
		Copm_logic(Game::type::CROSS, Game::type::ZERO);
		if (Check_win())
		{
			system("cls");
			Render_map();
			cout << "Player: " << "comp" << " is winer!!!\n";
			system("pause");
			break;
		}
		Player_move(name, Game::type::ZERO);
		if (Check_win())
		{
			system("cls");
			Render_map();
			cout << "Player: " << name << " is winer!!!\n";
			system("pause");
			break;
		}
	}
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
		game_map[i] = new short[size_map];
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
	for (short i = 0; i < size_map; i++)
	{
		delete[] game_map[i];
	}
	delete[] game_map;
}
