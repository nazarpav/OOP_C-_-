#include<iostream>
#include<ctime>
#include<queue>
#include<string>
#include<map>
#include"Transport.h"
#include"Enum_estimated_delivery_time.h"
using namespace std;

class Nova_poshta
{
	map<short, Transport*> transport_map;
public:
	Nova_poshta()
	{
		short tmp=0;
		transport_map[tmp++]=new Small_car_type_1;
		transport_map[tmp++]=new Small_car_type_2;

		transport_map[tmp++]=new Minivan_car_type_1;
		transport_map[tmp++]=new Minivan_car_type_2;

		transport_map[tmp++] = new Bus_car_type_1;
		transport_map[tmp++] = new Bus_car_type_2;

		transport_map[tmp++] = new Truck_car_type_1;
		transport_map[tmp++] = new Truck_car_type_2;

		transport_map[tmp++] = new Airplane_type_1;
		transport_map[tmp] = new Airplane_type_2;
	}
	bool Factory(Cargo& cargo)
	{
		/*short num = 0;
	label_factory:*/
		for (short i = 0; i < transport_map.size(); i++)
		{
			if (transport_map[i]->Delivery_Cargo(cargo/*,num*/))
			{
				return true;
			}
		}
		/*if (num++ <= 10)
			goto label_factory;*/
		return false;
	}
};





short Rand(short num)
{
	const short step = 50;
	return (rand() % (num/step + 1)*step);
}
Estimated_delivery_time Rand_estimated_delivery_time()
{
	switch (rand() % 3+1)
	{
	case Slow_delivery:
		return Slow_delivery;
		break;
	case Ordinary_delivery:
		return Ordinary_delivery;
		break;
	case Fast_delivery:
		return Fast_delivery;
		break;
	}
}


short Cargo::Counter_id = 0;
int main()
{
	srand(unsigned(time(NULL)));
	const short size_queue = 100;
	short num_buf;
	queue<Cargo> queue_;
	Nova_poshta nova_poshta;
	string buf;
	for (short i = 0; i < size_queue; i++)
	{
		num_buf = Rand(4000);
	queue_.push(Cargo(num_buf+ Rand(150), num_buf+Rand(250), Rand_estimated_delivery_time()));
	}
	for (short i = 0; i < size_queue; i++)
	{
		if (!(nova_poshta.Factory(queue_.front())))
		{
			cout <<"Cargo (id = "<< queue_.front().Get_id() <<") not delivered! (Size=> "<< queue_.front().Get_size()<<" Weigth=> "<< queue_.front().Get_weigth()<<" Delivery time=>  "<< queue_.front().Get_delivery_time() << "-------------------------------<" << endl;
		}
		else
		{
			cout << "Cargo (id = " << queue_.front().Get_id() << ") >>DELIVERED!<< (Size=> " << queue_.front().Get_size() << " Weigth=> " << queue_.front().Get_weigth() << " Delivery time=>  " << queue_.front().Get_delivery_time() << endl;

		}
		queue_.pop();
	}



	system("pause");
	return 0;
}