#pragma once
#include "Animal.h"
class Reptile :
	public Animal
{
	bool bite_death;
public:
	Reptile(string place, int weight, bool bite_death);
};

