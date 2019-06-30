#pragma once
#include"Animal.h"
#include<string>
#include<iostream>
class Bird:public Animal
{
protected:
	int Flight_altitude;
	int Wingspan;
public:
	Bird(int Speed, int Weight, std::string Living_enviroment,int Flight_altitude, int Wingspan):Flight_altitude(Flight_altitude),Wingspan(Wingspan),Animal("Bird", Speed,Weight,Living_enviroment)
	{
	}
	void Move()
	{
		std::cout << "Flyyyyy<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
	}
	void Show()
	{
		Animal::Show();
		std::cout << "Flight altitude: " << Flight_altitude << "\nWingspan: " << Wingspan << std::endl;
	}
};
