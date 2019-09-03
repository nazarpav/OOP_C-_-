#pragma once
#include"Template_menu.h"
#include <atltime.h>
#include<iostream>
#include<fstream>
#include<string>
#include <ctime>
using namespace std;

std::string now();
short Rand(short num)
{
	return rand() % num + 1;
}
int File_size(string path) {
	ifstream mySource;
	mySource.open(path, ios_base::binary);
	mySource.seekg(0, ios_base::end);
	int size = mySource.tellg();
	mySource.close();
	return size;
}
class Database
{
	fstream out;
	const string connection_string = "database.txt";
	bool is_connect;
public:
	Database()
	{
		is_connect = false;
	}
	~Database()
	{
		out.close();
	}
	bool Connetc()
	{
		out.open(connection_string, ios_base::out | ios_base::app);
		is_connect= out.is_open();
		out.close();
		if (is_connect == false)
			return is_connect;
		if (Rand(100) <= 40)
			is_connect = false;
		return is_connect;
	}

	void Log(string msg)
	{
		out.open(connection_string, ios_base::out | ios_base::app);
		out << msg << "| Time: " << now() << endl;
		out.close();
	}

};
class Database_proxy
{
	const string connection_string_local = "local_database.txt";
	const string connection_string = "database.txt";
	Database realDB;
	fstream fstr;
	bool is_connect;
public:
	Database_proxy()
	{
		is_connect = false;
	}
	bool Connetc()
	{
		is_connect = realDB.Connetc();
		return is_connect;
	}

	void Log(string msg)
	{
		if (is_connect == false)
		{
			fstr.open(connection_string_local, ios_base::out | ios_base::app);
			fstr << msg << "| Time: " << now() <<"\t with local"<< endl;
			fstr.close();
			return;
		}
		if (File_size(connection_string) != 0)
		{
			ifstream input(connection_string_local);
			ofstream output(connection_string, ios_base::app);
			output << input.rdbuf();
			output.close();
			input.close();
			fstr.open(connection_string_local, ios::out | ios_base::trunc);
			fstr.close();
		}
		realDB.Log(msg);
	}

	~Database_proxy()
	{
		fstr.close();
	}
};

std::string now()
{
	string time;
	CTime obj;
	obj = obj.GetCurrentTime();
	int Hour = obj.GetHour();
	int Minutes = obj.GetMinute();
	int Seconds = obj.GetSecond();
	time = to_string(Seconds) + ":" + to_string(Minutes) + ":" + to_string(Hour)+" data type-> "+"S,M,H";
	return time;
}

