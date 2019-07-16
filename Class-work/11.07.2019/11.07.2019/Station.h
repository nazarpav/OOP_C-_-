#pragma once
#include"my_time.h"
#include"Train.h"
#include<vector>
#include<string>
#include<fstream>
/*Завдання:
Написати програму «Автоматизована інформаційна система залізничного вокзалу».
Система містить: відомості про відправлення поїздів далекого прямування.

Для кожного поїзда вказуємо:
- номер,
- час відправлення
- станцію призначення

Забезпечити:
■ Додати поїзд в систему;
■ Виведення інформації по всіх поїздах;
■ Виведення інформації по конкретному поїзді;
■ Відредагувати час відправлення поїзду;
■ Відсортувати список поїздів по часу відправлення;
■ Показати список поїздів по станції призначення;
■ Записати список в файл;
■ Зчитати список з файлу.*/
using namespace std;
class Station
{
	vector<Train> Trains;
public:
	void Add_train(int number, MyTime time, std::string arriev_place)
	{
		Train tmp(number, time, arriev_place);
		Trains.push_back(tmp);
	}
	void Add_train(Train tmp)
	{
		Trains.push_back(tmp);
	}
	void Show()
	{
		for (Train item : Trains)
		{
			cout << item << endl;
		}
	}
	void Show(int number)
	{
		for (Train item : Trains)
		{
			if (item.get_number() == number)
			{
				cout << item << endl;
				return;
			}
		}
		cout << "Not found\n";
	}
	void Show(std::string arriev_place)
	{
		bool flag = true;
		for (Train item : Trains)
		{
			if (item.get_arriev_place() == arriev_place)
			{
				cout << item << endl;
				flag = false;
			}
		}
		if(flag)
		cout << "Not found\n";
	}
	void Sort_trains()
	{
		int j;
		// цикл проходів, i - номер проходу
		for (int i = 0; i < Trains.size(); i++)
		{
			Train x = Trains[i];

			// пошук місця для елемента в лівому підмасиві
			for (j = i - 1; j >= 0 && Trains[j] > x; j--)
			{
				// здвигаємо елемент вправо
				Trains[j + 1] = Trains[j];
			}

			// місце знайдено, вставити елемент
			Trains[j + 1] = x;
		}
	}
	void Red_time_departure(int number,MyTime time_)
	{
		for (Train item : Trains)
		{
			if (item.get_number() == number)
			{
				item.set_time_departure(time_);
				return;
			}
		}
		cout << "Not found\n";
	}
	void to_file(string path)
	{
		ofstream file(path, ios_base::out);
		for (Train item : Trains)
		{
			file << item;
		}
		file.close();
	}
	void to_vector(string path)
	{
		ifstream file(path, ios_base::in);
		Train obj;
		int tmp;
		string tmp3;
		MyTime tmp2;
		for (;!file.eof();)
		{
			file >> tmp;
			file >> tmp2;
			file >> tmp3;
			obj.set_number(tmp);
			obj.set_time_departure(tmp2);
			obj.set_arriev_place(tmp3);
			this->Trains.push_back(obj);
		}
		file.close();
	}
	Station()
	{
	}
	~Station()
	{

	}
};

