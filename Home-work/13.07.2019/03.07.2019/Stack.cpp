#include "Stack.h"
#include <iostream>

void Dynamic_data_struct::Stack::Stack::Stack_show()
{
	std::cout << "data: " << this->stack << std::endl;
}

Dynamic_data_struct::Stack::Stack::Stack(int stack)
{
	this->stack = stack;
}

