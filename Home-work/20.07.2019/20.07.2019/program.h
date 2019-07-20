#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class program
{
	string str;
	string path;
	fstream file;
	//ofstream out(this->path, ios::out||ios::trunc);
	int quantity_string;
	int quantity_word;
	int quantity_sentence;
public:
	
	void Open_file(string path = "data.txt")
	{
		this->path = path;
		file.open(this->path, ios::in || ios::out || ios::trunc);
		if (!(this->file.is_open()))
		{
			throw "Eror open";
		}
		if (this->file.eof())
			throw"file empty!";
		this->str += this->file.get();
		if (this->str[this->str.length() - 1] == '!' || this->str[str.length() - 1] == '?' || this->str[str.length() - 1] == '.')
			this->quantity_sentence++;
		if (this->str[this->str.length() - 1] == '\n' || this->str[this->str.length() - 1] == 13)
			this->quantity_string++;
		while (!this->file.eof())
		{
			this->str += this->file.get();
			if (this->str[this->str.length() - 1] == '!' || this->str[str.length() - 1] == '?' || this->str[str.length() - 1] == '.')
				this->quantity_sentence++;
			if (this->str[this->str.length() - 1] == '\n' || this->str[this->str.length() - 1] == 13)
				this->quantity_string++;
			if ((this->str[this->str.length() - 1] == ' '|| (this->str[this->str.length() - 1] == '\n' || this->str[this->str.length() - 1] == 13)) && this->str[this->str.length() - 2] != ' ')
				this->quantity_word++;
		}
		this->quantity_word++;
		this->quantity_string++;
	}
	void File_to_monitor()
	{
		cout << this->str;
	}
	int Find_your_string(string str_finded)
	{
		unsigned long long int tmp = 0;
		int counter = 0;
		while(true)
		{
			tmp = str.find(str_finded, tmp);
			if (tmp == 0||tmp == str.npos)
				break;
			else
				tmp += str_finded.length();
			counter++;
		}
		return counter;
	}
	long long int Replace_character(char character=NULL, char character2 = NULL)
	{
		long long int counter = 0;
		unsigned long long int tmp = 0;
		while (tmp != str.npos)
		{
			tmp = str.find(character, tmp);
			if (tmp == 0 || tmp == str.npos)
				break;
			else
			{
				str[tmp] = character2;
				tmp++;
			}
			counter++;
		}
		return counter;
	}
	int Replace_string(string str_1, string str_2)
	{
		int counter = 0;
		unsigned long long int tmp = 0;
		while (tmp != str.npos)
		{
			tmp = str.find(str_1, tmp);
			if (tmp == 0 || tmp == str.npos)
				break;
			else
			{
				str.erase(tmp,str_2.length());
				str.insert(tmp,str_2);
				tmp++;
			}
			counter++;
		}
		return counter;
	}
	void revers_data_in_file()
	{
		string buf;
		for  (int i = str.length(); i !=0 ; i--)
		{
			buf += str[i];
	
		}
		str = buf;
	}
	void menu()
	{
	short choise = 0;
	string tmp1;
	string tmp2;
	char char_1;
	char char_2;
		while (true)
		{
			system("cls");
			cout << "1.file to monitor\n2.find your string\n3.replace character\n4.replace string\n5.revers data in file\n6.determination quantity string in file\n7.determination quantity sentence in file\n8.determination quantity word in file\n0.Exit\n: ";
			cin >> choise;
			switch (choise)
			{
			case 1:
				this->File_to_monitor();
				cout << endl;
				system("pause");
				break;
			case 2:
				cin >> tmp1;
				cout<<"Strings of this type found: "<<this->Find_your_string(tmp1)<<endl;
				system("pause");
				break;
			case 3:
				cin >> char_1;
				cin >> char_2;
				cout << "Counter replced character: " << this->Replace_character(char_1, char_2) << endl;
				system("pause");
				break;
			case 4:
				cin >> tmp1;
				cin >> tmp2;
				cout << "Counter replced string: " << this->Replace_string(tmp1, tmp2) << endl;
				system("pause");
				break;
			case 5:
				this->revers_data_in_file();
				break;
			case 6:
				cout << "Quantity string: " << this->quantity_string << endl;
				system("pause");
				break;
			case 7:
				cout << "Quantity sentence string: " << this->quantity_sentence << endl;
				system("pause");
				break;
			case 8:
				cout << "Quantity word: " << this->quantity_word << endl;
				system("pause");
				break;
			case 0:
				return;
				break;
			}
		}
	}
	program(string path="data.txt")
	{
		this->Open_file(path);
	}
	~program()
	{
		file.close();
	}
	
};

