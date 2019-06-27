#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
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