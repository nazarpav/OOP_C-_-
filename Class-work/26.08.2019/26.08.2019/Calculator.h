#pragma once
class Calculator
{
public:
	float Add(float num1, float num2)
	{
		return num1 + num2;
	}
	float Sub(float num1, float num2)
	{
		return num1 - num2;
	}
	float Mul(float num1, float num2)
	{
		return num1 * num2;
	}
	float Div(float num1, float num2)
	{
		return num1 / num2;
	}
	Calculator();
	~Calculator();
};

