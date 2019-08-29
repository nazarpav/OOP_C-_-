#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>
using namespace std;
class Player;
enum Units{Human=1,Motor=2,Tank=3};

class Unit
{
protected:
	short Attak_point;
	short Defense_point;
	short Heal_point;
public:
	virtual void Display() = 0;
};
class Human_ :public Unit
{
public:
	Human_()
	{
		Attak_point=10;
		Defense_point=5;
		Heal_point=20;
	}
	void Display()
	{
		cout << "Human\n";
	}
};

class Motor_ :public Unit
{
public:
	Motor_()
	{
		Attak_point = 20;
		Defense_point = 8;
		Heal_point = 40;
	}
	void Display()
	{
		cout << "Motor\n";
	}
};

class Tank_:public Unit
{
public:
	Tank_()
	{
		Attak_point = 40;
		Defense_point = 15;
		Heal_point = 100;
	}
	void Display()
	{
		cout << "Tank\n";
	}
};
class Factory_unit
{
	map<Units,Unit*> _Unit;
public:
	short Get_size()
	{
		return _Unit.size();
	}
	Unit* Get_unit(Units u)
	{
		Unit * unit = nullptr;
		if (find(_Unit.begin(), _Unit.end(), u) != _Unit.end())
		{
			unit = _Unit[u];
		}
		else
		{
			switch (u)
			{
			case Human:
				unit = new Human_();
				_Unit[Human] = unit;
				break;
			case Motor:
				unit = new Motor_();
				_Unit[Motor] = unit;
				break;
			case Tank:
				unit = new Tank_();
				_Unit[Tank] = unit;
				break;
			default:
				throw new exception("Factory cannot create the object specified");
			}
		}
		return unit;
	}
};
class Player
{
	short Human__;
	short Motors__;
	short Tanks__;
	Factory_unit  f;
public:
	void Display_all_army()
	{
		cout << "Human> Motors> Tank\n";
	}
	short Get_all_stats()
	{
		cout <<f.Get_size()<< endl;
	}
	void Gen_unit(Units u)
	{
		switch (u)
		{
		case Human:
			Human__++;
			break;
		case Motor:
			Motors__++;
			break;
		case Tank:
			Tanks__++;
			break;
		}
		f.Get_unit(u);
	}
};


void main()
{
	Player p;
	p.Gen_unit(Human);
	p.Gen_unit(Human);
	p.Gen_unit(Human);
	p.Gen_unit(Human);
	p.Gen_unit(Human);
	p.Gen_unit(Human);
	p.Gen_unit(Human);
	p.Gen_unit(Human);
	p.Gen_unit(Human);
	p.Gen_unit(Human);
	p.Get_all_stats();
	system("pause");
}




