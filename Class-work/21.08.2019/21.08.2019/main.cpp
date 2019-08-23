#include<iostream>
#include<string>
using namespace std;

class Bullet
{
	float caliber;
	float weight;
	float speed;
public:
	virtual void Hit() = 0;
	Bullet(float caliber, float weight, float speed)
	{
		this->caliber= caliber;
		this->weight= weight;
		this->speed= speed;
	}
	virtual void Start_move() = 0;
};
 
class Shotgun_bullet:public Bullet
{
public:
	Shotgun_bullet(float caliber, float weight, float speed) :Bullet(caliber, weight, speed)
	{}
	void Hit()
	{
		cout << "Ai Ai Ai" << endl;
	}
	void Start_move()
	{
		cout << "Bang bang bang (Shotgun_bullet)" << endl;
	}
};

class Automatic_bullet :public Bullet
{
public:
	Automatic_bullet(float caliber, float weight, float speed) :Bullet(caliber, weight, speed)
	{}
	void Hit()
	{
		cout << "Ai Ai Ai" << endl;
	}
	void Start_move()
	{
		cout << "Bang bang bang (Automatic_bullet)" << endl;
	}
};


class Weapon
{
	float caliber;
	short damage;
	double distance;
	virtual Bullet* Create_bullet() = 0;
public:
	virtual Bullet* Shoot()
	{
		return Create_bullet();
	}
};

class Shotgun:public Weapon 
{
	Bullet* Create_bullet()
	{
		return new Shotgun_bullet(1, 2, 3);
	}
};
class Automatic :public Weapon
{
	Bullet* Create_bullet()
	{
		return new Automatic_bullet(11, 22, 33);
	}
};

int main()
{
	Weapon *g = new Automatic;
	Bullet* bullet = g->Shoot();
	bullet->Hit();

	system("pause");
	return 0;
}