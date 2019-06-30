#pragma once
#include"Animal.h"
#include<string>
#include<iostream>
class Reptile :public Animal
{
protected:
	int Dwell_time;//час перебування під водою
public:
	Reptile(int Speed, int Weight, std::string Living_enviroment, int Dwell_time) :Dwell_time(Dwell_time), Animal("Reptile", Speed, Weight, Living_enviroment)
	{
	}
	void Move()
	{
		std::cout << "Crawlllll<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
	}
	void Show()
	{
		Animal::Show();
		std::cout << "Dwell time: " << Dwell_time <<  std::endl;
	}
};