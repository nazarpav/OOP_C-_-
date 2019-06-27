#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Driver;
class Wheel
{
	int diametr;
	string disk_material;
public:
	Wheel(int diametr = 0, string disk_material = "", int quantity = 0) :diametr(diametr), disk_material(disk_material)
	{};
	void show()
	{
		cout << "\ndiametr : " << diametr << "\ndisk_material : " << disk_material << endl;
	}
};

class Engine
{
	int pover;
	int volume;
public:
	Engine(int pover = 0, int volume = 0) :pover(pover), volume(volume) {};
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
	Car_body(string type = "", string body_material = "") :type(type), body_material(body_material) {};
	void show()
	{
		cout << "\ntype : " << type << "\nbody_material : " << body_material << endl;

	}
};
class Car
{
	vector <Driver> *Driver_;
	Car_body car_body_;
	Wheel *wheel_;
	Engine engine_;
	int quantity_wheel;
public:
	Car(int diametr, string disk_material, int pover, int volume, string type, string body_material, int  quantity_wheel_)
	{
		this->quantity_wheel = quantity_wheel_;
		wheel_ = new Wheel[quantity_wheel_];
		car_body_ = Car_body(type, body_material);

		for (int i = 0; i < quantity_wheel; i++)
		{
			wheel_[i] = Wheel(diametr, disk_material);
		}

		engine_ = Engine(pover, volume);
	}
	void show()
	{
			cout << "Driver: \n";
		for (size_t i = 0; i < Driver_->size(); i++)
		{
			Driver_[i]->Show();
		}
		cout << "\nCar body =>";
		car_body_.show();
		for (int i = 0; i < quantity_wheel; i++)
		{
			cout << "\nwheel =>";
			wheel_[i].show();
		}
		cout << "\nQuantity : " << quantity_wheel << endl;
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
	string name;
	string surname;
	unsigned short age;
	unsigned short experience;
public:
	Driver(string name, string surname,unsigned short age, unsigned short experience)
	{
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->experience = experience;
	}
	void show()
	{
		cout << "Name: " << name << "\nSurname: " << surname << "\nAge: " << age << "\nExpierience: " << experience << endl;
	}
};
int main()
{
	//int diametr, string disk_material, int pover, int volume, string type, string body_material, int  quantity_wheel_
	Car obj(20,"carbon",220,3.5,"sport","aluminium",4);
	//Driver robert(1, "robert");
	obj.show();
	system("pause");
	return 0;
}

