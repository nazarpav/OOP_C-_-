#pragma once
#include "Animal.h"
class Fish :
	public Animal
{
	int max_depth;
public:
	Fish(string place, int weight, int max_depth);
};

