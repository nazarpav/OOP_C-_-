//За основу взяти зроблений проект з описом структури та функціями створення / виведення / запису / зчитуваня одного екземпляра структури
//
//В main створіть статичний масив таких структур розміром 10:
//const int size = 10;
//Player playerArr[10];
//
//Додайте наступний функціонал для роботи з ним :
//
//1 - Напишіть функцію, яка буде заповнювати елементи в масиві(використайте функцію Fill або Create)
//2 - Функція для виводу всього масиву на екран(також буде використовуватися написана функція для показу)
//3 - Запис масива в файл(використати Save)
//4 - Зчитування масива з файла(використати Load)

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include "Header.h"
using namespace std;

unsigned short template_menu(const string menu[], const unsigned short size_menu)
{
	for (unsigned short i = 0; i < size_menu; i++)
	{
		if (i == 0)
		{
			cout << "[ " << menu[i] << " ]" << endl;
			continue;
		}
		cout << menu[i] << endl;
	}
	unsigned short choise = 1;
	char Control_Symbol{};
	while (Control_Symbol != 13)
	{
		Control_Symbol = _getch();
		if (Control_Symbol != 72 && Control_Symbol != 80)
		{
			continue;
		}
		else
		{
			Control_Symbol == 72 ? choise-- : choise++;
			if (choise == 0)
			{
				choise++;
				continue;
			}
			else if (choise > size_menu)
			{
				choise--;
				continue;
			}
		}
		system("cls");
		for (unsigned short i = 0; i < size_menu; i++)
		{
			if (i + 1 == choise)
			{
				cout << "[ " << menu[i] << " ]" << endl;
				continue;
			}
			cout << menu[i] << endl;
		}
	}
	return choise;
}
void show_players(const Player Players[], const unsigned short &size)
{
	system("cls");
	for (unsigned short i = 0; i < size; i++)
	{
		cout << "Name:" << Players[i].name << endl;
		cout << "Surname:" << Players[i].surname << endl;
		cout << "Age:" << Players[i].age << endl;
		cout << "Games:" << Players[i].games << endl;
		cout << "Points:" << Players[i].points << endl;
		cout << "AvgPointPerGame:" << Players[i].avgPointPerGame << endl;
	}
	if (size == 0)
	{
		cout << "Your array is Empty!\n";
	}
	Sleep(5000);//sleep 5 sec
}

float AveragePoint(const Player player_arr[],const unsigned short &index_)
{
	return (float)player_arr[index_].games / player_arr[index_].points;
}

void fill_player_arr(Player *player_arr, const unsigned short size, unsigned short i = 0)
{
	system("cls");
	for (; i < size; i++)
	{

		cout << "Please enter name:" << endl;
		cin >> player_arr[i].name;

		cout << "Please enter surname:" << endl;
		cin >> player_arr[i].surname;

		cout << "Please enter age:" << endl;
		cin >> player_arr[i].age;

		cout << "Please enter games:" << endl;
		cin >> player_arr[i].games;

		cout << "Please enter points:" << endl;
		cin >> player_arr[i].points;

		player_arr[i].avgPointPerGame = AveragePoint(player_arr, i); // обчислення середньої кількості

	}
}
void add_player_to_arr(Player *&player_arr, unsigned short &size)
{
	Player *new_player_arr = new Player[size + 1];

	for (unsigned short i = 0; i < size; i++)
	{
		new_player_arr[i] = player_arr[i];
	}
	size++;
	fill_player_arr(new_player_arr, size, size-1);
	delete[] player_arr;
	player_arr = new_player_arr;
}

void del_player_to_arr(Player *&player_arr, unsigned short &size, unsigned short index_)
{
	Player *new_player_arr = new Player[size -1];
	unsigned short iterator_ = 0;
	for (unsigned short i = 0; i < size; i++)
	{
		if (index_ == i)
		{
			continue;
		}

		new_player_arr[iterator_] = player_arr[i];

		iterator_++;
	}
	size--;
	delete[] player_arr;
	player_arr = new_player_arr;
}

unsigned short search_data_in_arr(const Player player_arr[], const unsigned short &size)
{
	system("cls");
	string data_to_search{};
	cout << "Enter data to search (\" Players name \")-> ";
	cin >> data_to_search;
	for (unsigned short i = 0; i < size; i++)
	{
		if (player_arr[i].name.find(data_to_search)!=string::npos)
		{
			return i;
		}
	}
}

void Save_in_file(const Player player_arr[], const unsigned short &size)
{
	ofstream out("Players.txt", ios_base::out);
	out << size<<endl;
	for (unsigned short i = 0; i < size; i++)
	{
		out << player_arr[i].name << endl;
		out << player_arr[i].surname << endl;
		out << player_arr[i].age << endl;
		out << player_arr[i].games << endl;
		out << player_arr[i].points << endl;
		out << player_arr[i].avgPointPerGame << endl;
	}

	out.close();

	cout << "Great!!!\n";
	Sleep(2000);//sleep 2 sec
}

void Load_from_file(Player *&player_arr, unsigned short &size)
{
	ifstream in("Players.txt", ios_base::in);
	in >> size;
	player_arr = new Player[size];
	for (unsigned short i = 0; i < size; i++)
	{
		in >> player_arr[i].name;
		in >> player_arr[i].surname;
		in >> player_arr[i].age;
		in >> player_arr[i].games;
		in >> player_arr[i].points;
		in >> player_arr[i].avgPointPerGame;
	}

	in.close();

	cout << "Great!!!\n";
	Sleep(2000);//sleep 2 sec
}

int main()
{
	unsigned short size = 0;
	Player * player_arr = nullptr; // = CreatePlayer();
	const unsigned short size_menu = 7; // size menu
	string menu[size_menu] // = menu
	{
		"Load from file",
		"Show all players",
		"Save to file",
		"Fill all data players",
		"Add new player",
		"Del player",
		"Exit"
	};
	unsigned short ind = 0;
	bool flag = true;
	while (flag == true)
	{
		system("cls");
		switch (template_menu(menu, size_menu))
		{
		case 1:
			Load_from_file(player_arr, size);
			break;
		case 2:
			show_players(player_arr, size);
			break;
		case 3:
			Save_in_file(player_arr, size);
			break;
		case 4:
			fill_player_arr(player_arr, size);
			break;
		case 5:
			add_player_to_arr(player_arr, size);
			break;
		case 6:
			del_player_to_arr(player_arr, size, search_data_in_arr(player_arr, size));
			break;
		case 7:
			flag = false;
			break;
		}
	}
	return 0;
}