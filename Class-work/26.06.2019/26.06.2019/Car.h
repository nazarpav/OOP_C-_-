#pragma once
#include "Wheels.h"
#include "Engine.h"
#include "Door.h"
#include<iostream>
using namespace std;
class Car :
	public Wheels,
	public Engine,
	public Door
{
private:
	int max_speed;
public:
	Car(int max_speed,int size,int size_wheels,int pover);
	void Show()
	{
		cout << "Max speed: " << max_speed << endl;
		Wheels::Show();
		Engine::Show();
		Door::Show();
	}
	~Car();
};

