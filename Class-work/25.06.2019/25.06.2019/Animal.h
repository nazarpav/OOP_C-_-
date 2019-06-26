#pragma once
#include<string>
using namespace std;
class Animal
{
protected:
	string type;
	string place;
	int weight;
public:
	void say();
	void move();
	Animal(string type, string place, int weight);
};

