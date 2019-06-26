#pragma once
#include<iostream>
using namespace std;
class Door
{
protected:
	int size;
public:
	Door(int size);
	void Show()
	{
		cout << "Door size: " << size << endl;
	}
	~Door();
};

