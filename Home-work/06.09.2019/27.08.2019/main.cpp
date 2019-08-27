#include <iostream>
using namespace std;
class Game_car;
class Car
{
public:
	void Push_gas_pedal()
	{
		cout << "Gas pedal pushed\n";
	}
	void Steer_wheel()
	{
		cout << "Wheel \n";
	}
	void Change_transmission()
	{
		cout << "Trnsmission changed\n";
	}
	void Push_beep()
	{
		cout << "Beep pushed\n";
	}
	void Push_clatch_pedal()
	{
		cout << "Clath pedal pushed\n";
	}
};

class Game_car
{
public:
	virtual void Forward()
	{
		cout << "go Forward\n";
	}
	virtual void Left()
	{
		cout << "go Forward\n";
	}
	virtual void Right()
	{
		cout << "go Right\n";
	}
	virtual void Backward()
	{
		cout << "go Backward\n";
	}
	virtual void Beep()
	{
		cout << "pushed beep\n";
	}
};
class Adapter : public Game_car
{
	Car* ca;
public:
	Adapter(Car *c)
	{
		ca = c;
	}
	void Forward()
	{
		ca->Push_gas_pedal();
	}
	void Left()
	{
		ca->Steer_wheel();
	}
	void Right()
	{
		ca->Steer_wheel();
	}
	void Backward()
	{
		ca->Push_clatch_pedal();
		ca->Change_transmission();
		ca->Push_gas_pedal();
	}
	void Beep()
	{
		ca->Push_beep();
	}
};

class Player
{
public:
	void Drive(Game_car *car)
	{
		car->Forward();
		car->Beep();
		car->Left();
		car->Backward();
	}
};
int main()
{
	Player pl;

	pl.Drive(new Game_car());
	cout << endl;
	pl.Drive(new Adapter(new Car()));

	system("pause");
	return 0;
}