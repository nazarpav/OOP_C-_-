#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Car_body.h"
#include"Driver.h"
#include"Engine.h"
#include"Wheel.h"
using namespace std;
class Car
{
	vector <Driver*> Driver_;
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
	Car(int diametr, string disk_material, int pover, int volume, string type, string body_material, int  quantity_wheel_,Driver * driver_)
	{
		this->Driver_.push_back(driver_);
		this->quantity_wheel = quantity_wheel_;
		wheel_ = new Wheel[quantity_wheel_];
		car_body_ = Car_body(type, body_material);

		for (int i = 0; i < quantity_wheel; i++)
		{
			wheel_[i] = Wheel(diametr, disk_material);
		}

		engine_ = Engine(pover, volume);
	}
	void Add_driver(Driver * driver_)
	{
		this->Driver_.push_back(driver_);
	}
	void Show()
	{
		cout << "Driver(s): \n";
		if (Driver_.empty())
		{
			cout << "No drivers found" << endl;
		}
		else
		{
			for (size_t i = 0; i < Driver_.size(); i++)
			{
				Driver_[i]->Show();
			}
		}
		cout << "\nCar body =>";
		car_body_.show();
		for (int i = 0; i < quantity_wheel; i++)
		{
			cout << "\nwheel =>";
			wheel_[i].Show();
		}
		cout << "\nQuantity : " << quantity_wheel << endl;
		cout << "\nengine =>";
		engine_.Show();
	}
	~Car()
	{
		delete[]  wheel_;
	}
};