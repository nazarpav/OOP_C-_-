#include "Queue.h"
//#include "Queue_log.h"
#include <atltime.h>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>
enum priority { Root = 100, Admin = 80, User = 50, Visitor = 20 };
void log_(std::string user)
{
	CTime obj;
	obj = obj.GetCurrentTime();
	int Hour = obj.GetHour();
	int Minutes = obj.GetMinute();
	int Seconds = obj.GetSecond();
	std::ofstream out("log.txt", std::ios::app);
	out <<"User :> "<< user <<"| Time: "<<Hour<<":"<<Minutes<<":"<<Seconds << std::endl;
	out.close();
}
void client(Queue& q)
{
	switch (rand()%4+1)
	{
	case 1:
		q.Add(rand() % 1000+1, Root);
		break;
	case 2:
		q.Add(rand() % 1000 + 1, Admin);
		break;
	case 3:
		q.Add(rand() % 1000 + 1, User);
		break;
	case 4:
		q.Add(rand() % 1000 + 1, Visitor);
		break;
	}
	q.sort();
}
void print(Queue& q, int i)
{
	std::string user;
	//std::cout << q.data[i][1] << "\n";
	switch (q.data[i][1])
	{
	case 100:
		user = "ROOT";
		break; 
	case 80:
		user = "Admin";
		break;
	case 50:
		user = "User";
		break;
	case 20:
		user = "Visitor";
		break;
	}
	log_(user);
}
int main()
{
	srand(unsigned(time(0)));
	// Створення черги
	Queue q(25);


	// Показ черги
	q.Show();
	// Вилучення елемента
	//q.Extract();
	// Показ черги
	for (int i = 0; i < 20; i++)
	{
		client(q);
	}
	q.Show();
	for (int i = 0; i < 20; i++)
	{
		print(q, i);
	}
	system("pause");
	return 0;
}