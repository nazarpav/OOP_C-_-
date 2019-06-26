#include<iostream>
#include<string>
using namespace std;

class Wheel
{
	int diametr;
	string disk_material;
public:
	Wheel(int diametr = 0,string disk_material="",int quantity= 0) :diametr(diametr), disk_material(disk_material)
	{};
	void show()
	{
		cout << "\ndiametr : "<<diametr <<"\ndisk_material : "<< disk_material<<endl;
	}
};

class Engine
{
	int pover;
	int volume;
public:
	Engine(int pover =0,int volume=0) :pover(pover),volume(volume) {};
	void show()
	{
		cout << "\npover : " << pover << "\nvolume : " << volume << endl;
	}
};

class Car_body
{
	string type;
	string body_material;
public:
	Car_body(string type ="", string body_material="") :type(type), body_material(body_material){};
	void show()
	{
		cout << "\ntype : " << type << "\nbody_material : " << body_material << endl;

	}
};
class Car
{
	Car_body car_body_;
	Wheel *wheel_;
	Engine engine_;
	int quantity_wheel;
public:
	Car()
	{
	}
	Car(int diametr, string disk_material, int pover, int volume,string type, string body_material,int  quantity_wheel_)
	{
		this->quantity_wheel = quantity_wheel_;
		wheel_ = new Wheel[quantity_wheel_];
		car_body_ = Car_body(type, body_material);

		for (int i = 0; i < quantity_wheel; i++)
		{
			wheel_[i] =  Wheel(diametr, disk_material);
		}

		engine_ = Engine(pover, volume);
	};
	void show()
	{

		cout << "\nCar body =>";
		car_body_.show();
		for (int i = 0; i < quantity_wheel; i++)
		{
		cout << "\nwheel =>";
		wheel_[i].show();
		}
		cout << "\nquantity : " << quantity_wheel<<endl;
		cout << "\nengine =>";
		engine_.show();
	}
	~Car()
	{
		delete[]  wheel_;
	}
};
class Driver
{
	Car* cars;
	string name;
	int quantity_driver;
public:
	Driver(int quantity_driver, string name)
	{
		this->quantity_driver = quantity_driver;
		this->name = name;
		cars = new Car[quantity_driver];
		for (int i = 0; i < quantity_driver; i++)
		{
			cars[i] = Car(20, "carbon", 220, 4, "sport", "steel", 4);
		}
	}
	void show()
	{
		for (int i = 0; i < quantity_driver; i++)
		{
			cars[i].show();
		}
	}
	~Driver()
	{
		delete[]cars;
	}
};
int main()
{
	Driver robert(1, "robert");
	robert.show();
	system("pause");
	return 0;
}