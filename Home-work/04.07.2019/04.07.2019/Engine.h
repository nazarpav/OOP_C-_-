#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Engine
{
	int pover;
	int volume;
public:
	Engine(int pover = 0, int volume = 0) :pover(pover), volume(volume) {};
	void Show()
	{
		cout << "\npover : " << pover << "\nvolume : " << volume << endl;
	}
};