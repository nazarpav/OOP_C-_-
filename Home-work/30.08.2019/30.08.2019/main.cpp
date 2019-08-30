#include<iostream>
#include<string>

using namespace std;
class Processor
{
	string processor_type;

	string Get_type()
	{
		return processor_type;
	}
	Processor()
	{
		processor_type = "Processor";
	}
};
class Main_board
{
	string main_board_type;

	string Get_type()
	{
		return main_board_type;
	}
	Main_board()
	{
		main_board_type = "Main board";
	}
};
class Hdd
{
	string Hdd_type;

	string Get_type()
	{
		return Hdd_type;
	}
	Hdd()
	{
		Hdd_type = "Hdd board";
	}
};
class Memory
{
	string Memory_type;

	string Get_type()
	{
		return Memory_type;
	}
	Memory()
	{
		Memory_type = "Memory board";
	}
};
class Box
{
	string Box_type;

	string Get_type()
	{
		return Box_type;
	}
	Box()
	{
		Box_type = "Box board";
	}
};



class PC
{
	Box Box()
	{

	}
};






int main()
{


	system("pause");
	return 0;
}