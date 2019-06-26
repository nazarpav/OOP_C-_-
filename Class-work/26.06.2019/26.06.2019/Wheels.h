#pragma once
#include<iostream>
using namespace std;
class Wheels
{
protected:
	int size_wheels;
public:
	void Show()
	{
		cout << "Wheels size: " << size_wheels << endl;
	}
	Wheels(int size_wheels);
	~Wheels();
};

