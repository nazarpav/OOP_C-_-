#include"airplane.h"
#include <iostream>
using namespace std;
//string model,string type,
//unsigned short quantity_passenger,unsigned short max_quantity_passenger
int main()
{
	AIRPLANE obj("999s","10",100,300);
	AIRPLANE obj2("999", "10", 1110, 310);
	obj.show();
	obj2.show();
	//--obj2;//if quantity_passenger == 0 >> eror
	//++obj2;//if quantity_passenger == max_quantity_passenger >> eror
	obj2(-1000);
	obj2.show();
	if (obj > obj2)
	{
		cout << "\n>>>>> true <<<<<\n";
	}
	else
	{
		cout << "\n>>>>> false <<<<<\n";
	}
	system("pause");
	return 0;
}