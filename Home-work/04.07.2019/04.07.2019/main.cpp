#include<iostream>
#include<string>
#include<vector>
#include"Car.h"
using namespace std;

int main()
{
	//int diametr, string disk_material, int pover, int volume, string type, string body_material, int  quantity_wheel_
	Car obj(20,"carbon",220,3.5,"sport","aluminium",4);
	Driver robert("robert","gfdgfd",34,14);
	obj.Add_driver(&robert);
	obj.Show();
	system("pause");
	return 0;
}


