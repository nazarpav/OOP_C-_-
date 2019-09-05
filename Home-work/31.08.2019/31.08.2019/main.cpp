#include<iostream>
#include<string>
#include<ctime>
#include<queue>
using namespace std;

enum Estimated_delivery_time{ Slow_delivery=1, Ordinary_delivery, Fast_delivery};
struct Cargo;

struct Cargo
{
private:
	short weigth;
	short size;
	short ID_;
	Estimated_delivery_time delivery_time;
public:
	static short Counter_id;
	Cargo(short weigth,short size, Estimated_delivery_time delivery_time)
	{
		ID_=++Counter_id;
		this->weigth = weigth;
		this->size = size;
		this->delivery_time = delivery_time;
	}
	short Get_id()
	{
		return this->ID_;
	}
	short Get_size()
	{
		return this->size;
	}
	short Get_weigth()
	{
		return this->weigth;
	}
	Estimated_delivery_time Get_delivery_time()
	{
		return this->delivery_time;
	}
};

class Transport
{
protected:
	int carrying_capacity;
	int luggage_compartment_size;
	Estimated_delivery_time  speed_delivery;
public:
	virtual bool Add_Cargo(Cargo& cargo) = 0;
};

class Small_car_type_1:public Transport
{
public:
	Small_car_type_1()
	{
		this->carrying_capacity = 500;
		this->speed_delivery = Ordinary_delivery;
		this->luggage_compartment_size = 500;
	}
	virtual bool Add_Cargo(Cargo& cargo)override
	{
		if (carrying_capacity >= cargo.Get_weigth() && cargo.Get_delivery_time() == speed_delivery && luggage_compartment_size >= cargo.Get_size())
		{
			return true;
		}
		return false;
	}
};
class Small_car_type_2 :public Transport
{
public:
	Small_car_type_2()
	{
		this->carrying_capacity = 250;
		this->speed_delivery = Fast_delivery;
		this->luggage_compartment_size = 250;
	}
	virtual bool Add_Cargo(Cargo& cargo)override
	{
		if (carrying_capacity >= cargo.Get_weigth() && cargo.Get_delivery_time() == speed_delivery && luggage_compartment_size >= cargo.Get_size())
		{
			return true;
		}
		return false;
	}
};


class Minivan_car_type_1 :public Transport
{
public:
	Minivan_car_type_1()
	{
		this->carrying_capacity = 1000;
		this->speed_delivery = Fast_delivery;
		this->luggage_compartment_size = 1000;
	}
	virtual bool Add_Cargo(Cargo& cargo)override
	{
		if ((carrying_capacity>= cargo.Get_weigth()&& carrying_capacity/2 <= cargo.Get_weigth()) && cargo.Get_delivery_time() == speed_delivery && (luggage_compartment_size >= cargo.Get_size()&& luggage_compartment_size/2 >= cargo.Get_size()))
		{
			return true;
		}
		return false;
	}
};
class Minivan_car_type_2 :public Transport
{
public:
	Minivan_car_type_2()
	{
		this->carrying_capacity = 850;
		this->speed_delivery = Ordinary_delivery;
		this->luggage_compartment_size = 850;
	}
	virtual bool Add_Cargo(Cargo& cargo)override
	{
		if ((carrying_capacity >= cargo.Get_weigth() && carrying_capacity / 2 <= cargo.Get_weigth()) && cargo.Get_delivery_time() == speed_delivery && (luggage_compartment_size >= cargo.Get_size() && luggage_compartment_size / 2 >= cargo.Get_size()))
		{
			return true;
		}
		return false;
	}
};

class Bus_car_type_1 :public Transport
{
public:
	Bus_car_type_1()
	{
		this->carrying_capacity = 2000;
		this->speed_delivery = Ordinary_delivery;
		this->luggage_compartment_size = 2000;
	}
	virtual bool Add_Cargo(Cargo& cargo)override
	{
		if ((carrying_capacity >= cargo.Get_weigth() && carrying_capacity / 2 <= cargo.Get_weigth()) && cargo.Get_delivery_time() == speed_delivery && (luggage_compartment_size >= cargo.Get_size() && luggage_compartment_size / 2 >= cargo.Get_size()))
		{
			return true;
		}
		return false;
	}
};
class Bus_car_type_2 :public Transport
{
public:
	Bus_car_type_2()
	{
		this->carrying_capacity = 1500;
		this->speed_delivery = Slow_delivery;
		this->luggage_compartment_size = 1500;
	}
	virtual bool Add_Cargo(Cargo& cargo)override
	{
		if ((carrying_capacity >= cargo.Get_weigth() && carrying_capacity / 2 <= cargo.Get_weigth()) && cargo.Get_delivery_time() == speed_delivery && (luggage_compartment_size >= cargo.Get_size() && luggage_compartment_size / 2 >= cargo.Get_size()))
		{
			return true;
		}
		return false;
	}
};

class Truck_car_type_1 :public Transport
{
public:
	Truck_car_type_1()
	{
		this->carrying_capacity = 4000;
		this->speed_delivery = Slow_delivery;
		this->luggage_compartment_size = 4000;
	}
	virtual bool Add_Cargo(Cargo& cargo)override
	{
		if ((carrying_capacity >= cargo.Get_weigth() && carrying_capacity / 2 <= cargo.Get_weigth()) && cargo.Get_delivery_time() == speed_delivery && (luggage_compartment_size >= cargo.Get_size() && luggage_compartment_size / 2 >= cargo.Get_size()))
		{
			return true;
		}
		return false;
	}
};
class Truck_car_type_2 :public Transport
{
public:
	Truck_car_type_2()
	{
		this->carrying_capacity = 3500;
		this->speed_delivery = Ordinary_delivery;
		this->luggage_compartment_size = 3500;
	}
	virtual bool Add_Cargo(Cargo& cargo)override
	{
		if ((carrying_capacity >= cargo.Get_weigth() && carrying_capacity / 2 <= cargo.Get_weigth()) && cargo.Get_delivery_time() == speed_delivery && (luggage_compartment_size >= cargo.Get_size() && luggage_compartment_size / 2 >= cargo.Get_size()))
		{
			return true;
		}
		return false;
	}
};

class Airplane_type_1 :public Transport
{
public:
	Airplane_type_1()
	{
		this->carrying_capacity = 4000;
		this->speed_delivery = Ordinary_delivery;
		this->luggage_compartment_size = 4000;
	}
	virtual bool Add_Cargo(Cargo& cargo)override
	{
		if ((carrying_capacity >= cargo.Get_weigth() && carrying_capacity / 2 <= cargo.Get_weigth()) && cargo.Get_delivery_time() == speed_delivery && (luggage_compartment_size >= cargo.Get_size() && luggage_compartment_size / 2 >= cargo.Get_size()))
		{
			return true;
		}
		return false;
	}
};
class Airplane_type_2 :public Transport
{
public:
	Airplane_type_2()
	{
		this->carrying_capacity = 3500;
		this->speed_delivery = Fast_delivery;
		this->luggage_compartment_size = 3500;
	}
	virtual bool Add_Cargo(Cargo& cargo)override
	{
		if ((carrying_capacity >= cargo.Get_weigth() && carrying_capacity / 2 <= cargo.Get_weigth()) && cargo.Get_delivery_time() == speed_delivery && (luggage_compartment_size >= cargo.Get_size() && luggage_compartment_size / 2 >= cargo.Get_size()))
		{
			return true;
		}
		return false;
	}
};


short Rand(short num)
{
	const short step = 5;
	return (rand() % (num/step + 1)*step);
}
Estimated_delivery_time Rand_estimated_delivery_time()
{
	switch (Rand(3))
	{
	case Ordinary_delivery:
		return Ordinary_delivery;
		break;
	case Fast_delivery:
		return Fast_delivery;
		break;
	case Slow_delivery:
		return Slow_delivery;
		break;
	}
}


short Cargo::Counter_id = 0;
int main()
{
	srand(unsigned(time(NULL)));
	queue<Cargo> queue_;
	for (short i = 0; i < 100; i++)
	{
	queue_.push(Cargo(Rand(1000), Rand(500), Rand_estimated_delivery_time()));
	cout << queue_.back().Get_id();
	}

	system("pause");
	return 0;
}