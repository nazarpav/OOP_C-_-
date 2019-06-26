#pragma once
#include "Animal.h"
class Bird :
	public Animal
{
protected:
	int fly_height;
	int len_of_wings;
public:
	void fly();
	Bird(string place, int weight, int fly_height, int len_of_wings);
};

