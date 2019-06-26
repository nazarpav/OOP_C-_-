#pragma once
#include<iostream>
using namespace std;
class Engine
{
protected:
	int pover;
public:
	Engine(int pover);
	void Show()
	{
		cout << "Engine pover: " << pover << endl;
	}
	~Engine();
};

