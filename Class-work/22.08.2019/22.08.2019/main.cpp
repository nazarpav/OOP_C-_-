#include<iostream>
#include<fstream>
#include<string>

#include <atltime.h>
#include <ctime>
using namespace std;

std::string now();

class Logger
{
private:
	static Logger * p_instance;

	// Конструктори і оператор присвоювання недоступні клієнтам
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
		string path = "Player.txt";
		out.open(path, ios_base::out|ios_base::app);
		out << massange << "| Time: " <<now() << endl;
		out.close();
	}
};
class Game
{
public:
	Game()
	{
		Logger::GetInstance()->Log("init game");
		Game_();
	}
	void Game_()
	{
		Logger::GetInstance()->Log("game start");
		Player_move(rand()%10+5);
	}
	void Player_move(short counter)
	{
		for (short i = 0; i < counter; i++)
		{
			Logger::GetInstance()->Log("player move");
		}
	}
	~Game()
	{
		Logger::GetInstance()->Log("end game");
		delete Logger::GetInstance();
	}

private:

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
	time = to_string(Seconds) +":"+ to_string(Minutes) + ":" + to_string(Hour);
	return time;
}

Logger * Logger::p_instance = 0;
int main()
{
	srand(unsigned(time(NULL)));
	Game obj;
	system("pause");

}