#pragma once
#include"Calculator.h"
#include"Template_menu.h"
#include <atltime.h>
#include<iostream>
#include<fstream>
#include<string>
#include <ctime>
using namespace std;

std::string now();

class Logger
{
private:
	static Logger * p_instance;

	Logger() {}
	Logger(const Logger&);
	Logger& operator=(Logger&);
public:
	static Logger * GetInstance() {
		if (p_instance == NULL/*!p_instance*/)
			p_instance = new Logger();
		return p_instance;
	}
	void Log(const string massange)
	{
		ofstream out;
		string path = "LOG.txt";
		out.open(path, ios_base::out | ios_base::app);
		out << massange << "| Time: " << now() << endl;
		out.close();
	}
};
std::string now()
{
	//#include <atltime.h>
	//#include <ctime>
	string time;
	CTime obj;
	obj = obj.GetCurrentTime();
	int Hour = obj.GetHour();
	int Minutes = obj.GetMinute();
	int Seconds = obj.GetSecond();
	time = to_string(Seconds) + ":" + to_string(Minutes) + ":" + to_string(Hour);
	return time;
}

Logger * Logger::p_instance = 0;


class Calc_proxy
{
	Calculator *Calc;
	

	float Add(float num1, float num2)
	{
		Logger::GetInstance()->Log(to_string(num1)+"+"+to_string(num2));
		return num1 + num2;
	}
	float Sub(float num1, float num2)
	{
		Logger::GetInstance()->Log(to_string(num1) + "-" + to_string(num2));
		return num1 - num2;
	}
	float Mul(float num1, float num2)
	{
		Logger::GetInstance()->Log(to_string(num1) + "*" + to_string(num2));
		return num1 * num2;
	}
	float Div(float num1, float num2)
	{
		if (num2 == 0)
		{
			Logger::GetInstance()->Log("two num is 0");
			throw "two num != 0\n";

		}
		Logger::GetInstance()->Log(to_string(num1) + "/" + to_string(num2));
		return num1 / num2;
	}

	void Menu_text(float& num1,float& num2)
	{
		cout << "Enter first num-> ";
		cin >> num1;
		cout << "Enter second num-> ";
		cin >> num2;
	}

	void Result(float num)
	{
		cout << "Result = "<<num << endl;
	}

	void Clear()
	{
		system("cls");
	}

	void Pause()
	{
		system("pause");
	}
public:
	Calc_proxy()
	{
		Calc = nullptr;
	}
	void Menu()
	{
		float num1 = 0, num2 = 0;
		while (true)
		{
			const short SIZE_Select_type_game = 5;
			const string Select_type_game[SIZE_Select_type_game] =
			{
				"+",
				"-",
				"*",
				"/",
				"Exit"
			};
			Menu_text(num1, num2);
			switch (Template_menu::template_menu(Select_type_game, SIZE_Select_type_game))
			{
			case 1:
				Result(Add(num1, num2));
				Pause();
				Clear();
				break;
			case 2:
				Result(Sub(num1, num2));
				Pause();
				Clear();
				break;
			case 3:
				Result(Mul(num1, num2));
				Pause();
				Clear();
				break;
			case 4:
				try
				{
					Result(Div(num1, num2));
					Pause();
					Clear();
				}
				catch (char* text)
				{
					cout << text << endl;
				}
				break;
			case 5:
				return;
				break;
			}
		}
	}
};