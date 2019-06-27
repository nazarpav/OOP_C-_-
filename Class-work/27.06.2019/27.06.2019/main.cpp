#define _USE_MATH_DEFINES

#include<iostream>
#include<cmath>
//#include""
using namespace std;

class figure
{
public:
	virtual int Square() = 0;
};
//пр€мокутник, коло, пр€мокутний трикутник, трапец≥€
//rectangle, circle, rectangular triangle, trapeze
class rectangle:public figure
{
	int side;
public:
	rectangle(int side) :side (side)
	{
	}
	int Square()override
	{
		return pow(side, 2);
	}
};

class circle:public figure
{
	int radius;
public:
	circle(int radius) :radius(radius)
	{
	}

	int Square()override
	{
		return M_PI *pow(radius, 2);
	}
};
class rectangular:public figure
{
	int side1;
	int side2;
public:
	rectangular(int side1,int side2) :side1(side1), side2(side2)
	{
	}

	int Square()override
	{
		return side1*side2;
	}
};
class triangle:public figure
{
	int hypotenuse;
	int catet1;
	int catet2;
public:
	triangle(int hypotenuse, int catet1,int catet2) :hypotenuse(hypotenuse), catet1(catet1), catet2(catet2)
	{
	}

	int Square()override
	{
		return catet1*catet2/2;
	}
};
class trapeze:public figure
{
	int h;
	int side1;
	int side2;
public:
	trapeze(int h, int side1, int side2) :h(h), side1(side1), side2(side2)
	{
	}
	int Square()override
	{
		return h / 2 * (side1*side2);
	}
};


//int main()
//{
//	const int size = 5;
//	//rectangle, circle, rectangular triangle, trapeze
//	//пр€мокутник, коло, пр€мокутний трикутник, трапец≥€
//	figure*arr[size]
//	{
//		new rectangle(10),
//		new circle(5),
//		new rectangular(10,10),
//		new triangle(10,20,20),
//		new trapeze(10,5,5),
//	};
//	for (size_t i = 0; i < size; i++)
//	{
//		cout << arr[i]->Square() << endl;
//	}
//	system("pause");
//	return 0;
//}