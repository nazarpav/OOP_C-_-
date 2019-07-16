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
	
	void Open_file()
	{
		if (!this->file.eof())
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
			if (this->str[this->str.length() - 2] == ' ' && this->str[this->str.length() - 1] != ' ')
				this->quantity_word++;
		}
		this->quantity_word++;
	}
	void File_to_monitor()
	{
		cout << this->str;
	}
	int Find_your_string(string str_finded)
	{
		int tmp = 0;
		int counter = 0;
		while(tmp!=str.npos)
		{
		tmp=str.find(str_finded,tmp);
		counter++;
		}
		return counter;
	}
	long long int Replace_character(char character=NULL)
	{
		long long int counter = 0;
		int tmp = 0;
		while (tmp != str.npos)
		{
			tmp = str.find(character, tmp);
			str[tmp] = character;
			counter++;
		}
		return counter;
	}
	int Replace_string(string str_paste)
	{
		int counter = 0;
		int tmp = 0;
		while (tmp != str.npos)
		{
			tmp = str.find(str_paste, tmp);
			str.erase(tmp, str_paste.length());
			str.insert(tmp, str_paste);
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
		while (true)
		{
			cout << "1.file to monitor\n2.find your string\n3.replace character\n4.replace string\n5.revers data in file\n6.determination quantity sentence in file\n7.determination quantity string in file8.determination quantity word in file";
			cin >> choise;
			switch (choise)
			{
			case 1:
				this->File_to_monitor();
				break;
			case 2:
				this->Find_your_string("123");
				break;
			case 3:
				this->Replace_character(' ');
				break;
			case 4:
				this->Replace_string("123");
				break;
			case 5:
				this->revers_data_in_file();
				break;
			case 6:
				cout << this->quantity_string;
				break;
			case 7:
				cout << this->quantity_sentence;
				break;
			case 8:
				cout << this->quantity_word;
				break;
			default:
				break;
			}
		}
	}
	program(string path="data.txt")
	{
		file.open(this->path, ios::in || ios::out || ios::trunc);
		if (!(this->file.is_open()))
		{
			throw "Eror open";
		}
		this->Open_file();
	}
	~program()
	{
		file.close();
	}
	
};

