#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Game
{
	const short size_w = 20;
	const short size_h = 50;
	vector<vector<char>> map;
public:
	Game();
	~Game();
};

