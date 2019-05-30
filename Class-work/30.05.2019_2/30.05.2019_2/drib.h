#pragma once

class drib
{
public:
	drib(int chisl, int znam);
	~drib();

	float operator/(const drib & other) const;

	float operator+(const  drib& other)const;

	float operator-(const drib & other) const;

	float operator*(const drib & other) const;
	
private:
	int chisl;
	int znam;
};