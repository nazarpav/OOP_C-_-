#include<iostream>
#include<string>
#include"Bird.h"
#include"Fish.h"
#include"Reptile.h"
using namespace std;

class Kolibri : public Bird
{
public:
	//int Speed, int Weight, std::string Living_enviroment,int Flight_altitude, int Wingspan
	Kolibri() : Bird(20, 40,"forest",150,10)
	{ }
};
class Krokodil : public Reptile
{
public:
	//int Speed, int Weight, std::string Living_enviroment,Dwell_time;//час перебування під водою
	Krokodil() : Reptile(20, 40, "swamp", 50)
	{ }
};
class Shark : public Fish
{
public:
	//int Speed, int Weight, std::string Living_enviroment,Maximum_depth_of_immersion_under_water
	Shark() : Fish(20, 40, "ocean", 50)
	{ }
};

int main()
{
	Kolibri kol;
	kol.Show();
	Krokodil krok;
	krok.Show();
	Shark sha;
	sha.Show();
	kol.Move();
	krok.Move();
	sha.Move();
	system("pause");
	return 0;
}