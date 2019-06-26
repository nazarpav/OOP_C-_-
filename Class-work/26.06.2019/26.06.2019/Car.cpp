#include "Car.h"



Car::Car(int max_speed, int size, int size_wheels, int pover):Wheels(size_wheels),Engine(pover),Door(size)
{
	this->max_speed = max_speed;
}


Car::~Car()
{
}
