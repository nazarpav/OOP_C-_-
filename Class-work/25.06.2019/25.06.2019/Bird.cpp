#include "Bird.h"



void Bird::fly()
{
}

Bird::Bird(string place, int weight, int fly_height, int len_of_wings) : Animal("Bird", place, weight)
{
	this->fly_height = fly_height;
	this->len_of_wings = len_of_wings;
}


