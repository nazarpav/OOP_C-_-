#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Wheel
{
	int diametr;
	string disk_material;
public:
	Wheel(int diametr = 0, string disk_material = "", int quantity = 0) :diametr(diametr), disk_material(disk_material)
	{};
	void Show()
	{
		cout << "\ndiametr : " << diametr << "\ndisk_material : " << disk_material << endl;
	}
};
