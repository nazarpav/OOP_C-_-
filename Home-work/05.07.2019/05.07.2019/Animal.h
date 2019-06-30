#pragma once
#include<string>
#include<iostream>
class Animal
{
protected:
	std::string Kind;
	int Speed;
	int Weight;
	std::string Living_enviroment;
		
public:
	Animal(std::string Kind, int Speed, int Weight, std::string Living_enviroment) :Kind(Kind), Speed(Speed), Weight(Weight), Living_enviroment(Living_enviroment)
	{
	}
	void Move()
	{
		std::cout << "Move<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
	}
	void Show()
	{
		std::cout << "Kind: " << Kind << "\nSpeed: " << Speed << "\nWeight: " << Weight << "\nLiving enviroment: " << Living_enviroment<<std::endl;
	}
};

