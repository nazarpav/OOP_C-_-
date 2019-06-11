#pragma once
#include <iostream>
#include <string>
using namespace std;

template < typename T_ >
class VAR
{
public:
	template < typename T >
	VAR(T var)
	{
		this->var = var;
	}
	VAR()
	{
		//this->var = NULL;
	}
	~VAR()
	{

	}
	void show();
	VAR operator+(const VAR&other)const
	{
		VAR obj;
		obj.var = this->var + other.var;
		return obj;
	}
private:
	
	T_ var;
	/*std::string var;
	int var;
	double var;*/
};

template<typename T_>
inline void VAR<T_>::show()
{
	cout << var << endl;
}
