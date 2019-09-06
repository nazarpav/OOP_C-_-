#pragma once
#include"Cargo.h"
#include"Enum_estimated_delivery_time.h"



class Transport
{
protected:
	int carrying_capacity;
	int luggage_compartment_size;
	Estimated_delivery_time  speed_delivery;
public:
	virtual bool Delivery_Cargo(Cargo& cargo,short num=0) = 0;
};

class Small_car_type_1 :public Transport
{
public:
	Small_car_type_1()
	{
		this->carrying_capacity = 600;
		this->speed_delivery = Slow_delivery;
		this->luggage_compartment_size = 600;
	}
	virtual bool Delivery_Cargo(Cargo& cargo, short num = 0)override
	{
		if ((carrying_capacity >= cargo.Get_weigth()/* && carrying_capacity / 2 + num <= cargo.Get_weigth()*/) && cargo.Get_delivery_time() == speed_delivery && (luggage_compartment_size >= cargo.Get_size()/* && luggage_compartment_size / 2 + num >= cargo.Get_size()*/))
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
		this->carrying_capacity = 450;
		this->speed_delivery = Ordinary_delivery;
		this->luggage_compartment_size = 450;
	}
	virtual bool Delivery_Cargo(Cargo& cargo, short num = 0)override
	{
		if((carrying_capacity >= cargo.Get_weigth()/* && carrying_capacity / 2 + num <= cargo.Get_weigth()*/) && cargo.Get_delivery_time() == speed_delivery && (luggage_compartment_size >= cargo.Get_size()/* && luggage_compartment_size / 2 + num >= cargo.Get_size()*/))
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
	virtual bool Delivery_Cargo(Cargo& cargo, short num = 0)override
	{
		if ((carrying_capacity >= cargo.Get_weigth()/* && carrying_capacity / 2 + num <= cargo.Get_weigth()*/) && cargo.Get_delivery_time() == speed_delivery && (luggage_compartment_size >= cargo.Get_size()/* && luggage_compartment_size / 2 + num >= cargo.Get_size()*/))
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
		this->carrying_capacity = 1150;
		this->speed_delivery = Slow_delivery;
		this->luggage_compartment_size = 1150;
	}
	virtual bool Delivery_Cargo(Cargo& cargo, short num = 0)override
	{
		if ((carrying_capacity >= cargo.Get_weigth()/* && carrying_capacity / 2 + num <= cargo.Get_weigth()*/) && cargo.Get_delivery_time() == speed_delivery && (luggage_compartment_size >= cargo.Get_size()/* && luggage_compartment_size / 2 + num >= cargo.Get_size()*/))
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
	virtual bool Delivery_Cargo(Cargo& cargo, short num = 0)override
	{
		if ((carrying_capacity >= cargo.Get_weigth()/* && carrying_capacity / 2 + num <= cargo.Get_weigth()*/) && cargo.Get_delivery_time() == speed_delivery && (luggage_compartment_size >= cargo.Get_size()/* && luggage_compartment_size / 2 + num >= cargo.Get_size()*/))
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
		this->carrying_capacity = 2200;
		this->speed_delivery = Fast_delivery;
		this->luggage_compartment_size = 2200;
	}
	virtual bool Delivery_Cargo(Cargo& cargo, short num = 0)override
	{
		if ((carrying_capacity >= cargo.Get_weigth()/* && carrying_capacity / 2 + num <= cargo.Get_weigth()*/) && cargo.Get_delivery_time() == speed_delivery && (luggage_compartment_size >= cargo.Get_size()/* && luggage_compartment_size / 2 + num >= cargo.Get_size()*/))
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
	virtual bool Delivery_Cargo(Cargo& cargo, short num = 0)override
	{
		if ((carrying_capacity >= cargo.Get_weigth()/* && carrying_capacity / 2 + num <= cargo.Get_weigth()*/) && cargo.Get_delivery_time() == speed_delivery && (luggage_compartment_size >= cargo.Get_size()/* && luggage_compartment_size / 2 + num >= cargo.Get_size()*/))
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
		this->carrying_capacity = 4500;
		this->speed_delivery = Ordinary_delivery;
		this->luggage_compartment_size = 4500;
	}
	virtual bool Delivery_Cargo(Cargo& cargo, short num = 0)override
	{
		if ((carrying_capacity >= cargo.Get_weigth()/* && carrying_capacity / 2 + num <= cargo.Get_weigth()*/) && cargo.Get_delivery_time() == speed_delivery && (luggage_compartment_size >= cargo.Get_size()/* && luggage_compartment_size / 2 + num >= cargo.Get_size()*/))
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
		this->speed_delivery = Fast_delivery;
		this->luggage_compartment_size = 4000;
	}
	virtual bool Delivery_Cargo(Cargo& cargo, short num = 0)override
	{
		if ((carrying_capacity >= cargo.Get_weigth()/* && carrying_capacity / 2 + num <= cargo.Get_weigth()*/) && cargo.Get_delivery_time() == speed_delivery && (luggage_compartment_size >= cargo.Get_size()/* && luggage_compartment_size / 2 + num >= cargo.Get_size()*/))
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
		this->carrying_capacity = 5000;
		this->speed_delivery = Slow_delivery;
		this->luggage_compartment_size = 5000;
	}
	virtual bool Delivery_Cargo(Cargo& cargo,short num=0)override
	{
		if ((carrying_capacity >= cargo.Get_weigth()/* && carrying_capacity / 2 + num <= cargo.Get_weigth()*/) && cargo.Get_delivery_time() == speed_delivery && (luggage_compartment_size >= cargo.Get_size()/* && luggage_compartment_size / 2 + num >= cargo.Get_size()*/))
		{
			return true;
		}
		return false;
	}
};