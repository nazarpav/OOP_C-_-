#include "Game.h"



Game::Game()
{
	vector<char>tmp(size_w);
	for (int i = 0; i < size_h; i++)
	{
		for (int j = 0; j < size_w; j++)
		{
			map[i].push_back('#');
		}
	}
	for (int i = 0; i < size_h; i++)
	{
		for (int j = 0; j < size_w; j++)
		{
			cout << map[i][j];
		}
	}
}


Game::~Game()
{
}
