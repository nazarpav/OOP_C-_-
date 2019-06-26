#include "Fish.h"



Fish::Fish(string place, int weight, int max_depth) : Animal("Fish", place, weight)
{
	this->max_depth = max_depth;
}

