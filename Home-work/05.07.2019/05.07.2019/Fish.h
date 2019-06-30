#pragma once
#include"Animal.h"
#include<string>
#include<iostream>
class Fish :public Animal
{
protected:
	int Maximum_depth_of_immersion_under_water;
public:
	Fish(int Speed, int Weight, std::string Living_enviroment, int Maximum_depth_of_immersion_under_water) :Maximum_depth_of_immersion_under_water(Maximum_depth_of_immersion_under_water), Animal("Fish", Speed, Weight, Living_enviroment)
	{
	}
	void Move()
	{
		std::cout << "Swimmingggggg<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
	}
	void Show()
	{
		Animal::Show();
		std::cout << "Maximum depth of immersion under water : " << Maximum_depth_of_immersion_under_water << std::endl;
	}
};