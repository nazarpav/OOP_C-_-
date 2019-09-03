#pragma once
#include"Template_menu.h"
#include <atltime.h>
#include<iostream>
#include<fstream>
#include<string>
#include <ctime>
using namespace std;

std::string now();

class Database
{
	string connection_string;
	bool is_connect;
public:
	bool Connetc(string str_conn = "database.txt")
	{
		ofstream out;
		out.open(str_conn, ios_base::out | ios_base::app);
		is_connect= out.is_open();
		out.close();
	}
};

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

