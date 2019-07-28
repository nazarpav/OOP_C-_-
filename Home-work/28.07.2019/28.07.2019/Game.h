#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;
class Game
{
	enum type
	{
		NULL_=-1, ZERO = 0, CROSS = 1
	};
	short size_map = 3; 
	short **game_map;
	inline void Render_map();
	bool Game_player_and_comp(const string name);
	bool Game_copm_and_comp();
	bool Game_player_and_player(const string name_1, const string name_2);
	inline short Rand_()
	{
		return rand() % 2;
	}
	void Set_cursor(short x, short y);
	bool Check_win();
	void Copm_logic(short true_sign, short false_sign);
	void Player_move(const string name, const short sign);
public:
	bool Start_game_();
	Game(string name_1,string name_2, short size_map);
	Game(string name_1, short size_map);
	Game(short size_map);
	~Game();
};

