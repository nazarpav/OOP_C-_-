#include "Animal.h"
#include <iostream>
#include<string>
using namespace std;


void Animal::say()
{
	cout << "I "<<type<<", i say  BUUUUU\n";
}

void Animal::move()
{
	cout << "I move!!\n";
}

Animal::Animal(string type, string place, int weight)
{
	this->type = type;
	this->place = place;
	this->weight = weight;
}

