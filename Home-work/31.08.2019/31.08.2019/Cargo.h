#pragma once
#include"Enum_estimated_delivery_time.h"

class Cargo
{
private:
	short weigth;
	short size;
	short ID_;
	Estimated_delivery_time delivery_time;
public:
	static short Counter_id;
	Cargo(short weigth, short size, Estimated_delivery_time delivery_time)
	{
		ID_ = ++Counter_id;
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
