#include "Game.h"
//176-177-178

void Game::Create_map()
{
	const short quantity_step_checkpoint = 5;
	short counter=0;
	for (int i = 0; i < size_h; i++,counter++)
	{
		if (counter == 5)
		{
			short random_gates=Random(size_w-1);
			for (int j = 0; j < size_w; j++)
			{
				if (j == random_gates|| j == random_gates+1)
				{
					map[i][j] = ' ';
					continue;
				}
				map[i][j] = char(178);
			}
			counter = 0;
		}
		else
		{
			for (int j = 0; j < size_w; j++)
			{
				map[i][j] = char(176);
			}
		}
	}
	for (int j = 0; j < size_h; j++)
	{
		map[j][size_w] = ' ';
	}
	player_pos_y = 0; 
	player_pos_x = Random(size_w);
}



void Game::Render(string strategy_)
{
	Set_color(CYAN);
	buf_to_render_map += char(218);
	for (int j = 0; j < size_w; j++)
	{
		buf_to_render_map += char(196);
	}
	buf_to_render_map += char(191);
	buf_to_render_map += '\n';
	for (int i = 0; i < size_h; i++)
	{
		buf_to_render_map += char(179);
		for (int j = 0; j < size_w; j++)
		{
			buf_to_render_map += map[i][j];
		}
		buf_to_render_map += char(179);

		if (flag_first)
		{
		map[player_pos_y-1][size_w] = strategy_;
		buf_to_render_map += map[i][size_w];
		}
		buf_to_render_map += '\n';
	}
	flag_first = true;
	buf_to_render_map += char(192);
	for (int j = 0; j < size_w; j++)
	{
		buf_to_render_map += char(196);
	}
	buf_to_render_map += char(217);
	cout << buf_to_render_map;
	buf_to_render_map = "";
	cout<<endl << "x = " << player_pos_x << " | y = " << player_pos_y;

	cout << endl<<map[player_pos_y][size_w];
	Set_color(DARKGREEN);
	for (int j = 0; j < STRATEGY->capacity()/2; j++)
	{
		SetCursor(size_w+4, j);
		cout << STRATEGY[j];
	}
	SetCursor(size_w + 4, STRATEGY->capacity() / 2);
	Set_color(DARKYELLOW);
	cout << "Counter WIN = " << counter_win;
	Set_color(DARKRED);
	SetCursor(player_pos_x + 1, player_pos_y + 1);
	cout << char(219);
	SetCursor(0, 0);
	Set_color(WHITE);
}
bool Game::IS_game_over()
{
	if (*map[player_pos_y][player_pos_x].c_str() == char(178))
	{
		Set_color(RED);
		SetCursor(size_w/2-5, size_h/2);
		cout << "GAME OVER!!!:("; 
		Sleep(2000);
		return true;
	}
	return false;
}
bool Game::IS_WIN()
{
	if (map[size_h-1][player_pos_x] == " "&&size_h - 1== player_pos_y)
	{
		Set_color(GREEN);
		SetCursor(size_w / 2 -9, size_h / 2);
		cout << "WIN!!!";
		SetCursor(size_w / 2 -9, size_h / 2 + 1);
		cout << "PRESS ENTER to continue!!!";
		cin.get();
		counter_win++;
		flag_first = false;
		Console_clear();
		return true;
	}
	return false;
}

	string Game::Strategy1()
	{
		player_pos_y++;
		player_pos_x += -1;
		return "-1";
	}
	string Game::Strategy2()
	{
		player_pos_y++;
		player_pos_x += 2;
		return " 2";
	}
	string Game::Strategy4()
	{
		player_pos_y++;
		player_pos_x += -3;
		return "-3";
	}
	string Game::Strategy5()
	{
		player_pos_y++;
		player_pos_x += 4;
		return " 4";
	}
	string Game::Strategy7()
	{
		player_pos_y++;
		player_pos_x += -6;
		return "-6";
	}
	string Game::Strategy8()
	{
		player_pos_y++;
		player_pos_x += 7;
		return " 7";
	}


bool Game::Start_game()
{
	Create_map();
	string strategy_l=" ";
	Render(strategy_l);
	while (true)
	{
		switch (_getch())
		{
		case '1':
		case 'c':
		case 'C':
			if (player_pos_x == 0)
				continue;
			strategy_l = Strategy1();
			break;
		case '2':
		case 'v':
		case 'V':
			if (player_pos_x >=size_w-2)
				continue;
			strategy_l = Strategy2();
			break;
		case '4':
		case 'd':
		case 'D':
			if (player_pos_x <= 3)
				continue;
			strategy_l = Strategy4();
			break;
		case '5':
		case 'f':
		case 'F':
			if (player_pos_x >= size_w - 4)
				continue;
			strategy_l = Strategy5();
			break;
		case '7':
		case 'e':
		case 'E':
			if (player_pos_x <= 6)
				continue;
			strategy_l = Strategy7();
			break;
		case '8':
		case 'r':
		case 'R':
			if (player_pos_x >= size_w - 7)
				continue;
			strategy_l = Strategy8();
			break;
			case char(27) :
			return false;
				break;
		default:
			cout << char(7);
			continue;
			break;
		}
		Render(strategy_l);
		if (IS_game_over())
		{
			return false;
		}
		else if (IS_WIN())
		{
			return true;
		}
	}
}

Game::Game()
{
	buf_to_render_map.reserve(1456);
	player_pos_x=0;
	player_pos_y=0;
	counter_win = 0;
	flag_first = false;
	HideConsoleCursor();
}


Game::~Game()
{
}
