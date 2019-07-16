#include<string>
#include<map>
#include<iostream>
#include<fstream>
using namespace std;
/*Використовуючи контейнер map реалізувати програму - словник.
Основні можливості:
- пошук слова;
- додавання, видалення, редагування слів;
- читання і запис словника в файл.*/

map<string, string>::iterator Search_word(string word, map<string, string> &my_map)
{
	map<string, string>::iterator it = my_map.find(word);
	if (it == my_map.end())
	{
		cout << "Not found.\n";
	}
	else
	{
		return it;
	}
	cout << "------------------\n";
}
void Reduct_word(string word, map<string, string> &my_map)
{
	cout << "To reduct:  " << my_map[word] << endl;
	cin >> my_map[word];
}
void Add_word(string word, map<string, string> &my_map)
{
	my_map.insert(make_pair(word, ""));

}
void Erase_word(string word, map<string, string> &my_map)
{
	my_map.erase(word);
}
std::ostream& operator<< (std::ostream &out, const map<string, string> &my_map)
{
	for (auto i : my_map)
	{
		out <<i.first <<" "<<i.second << endl;
	}
	return out;
}
std::istream& operator>> (std::istream &in, map<string, string> &my_map)
{
	string tmp;
	string tmp2;
	in >> tmp;
	in >> tmp2;
	my_map.insert(make_pair(tmp, tmp2));
	return in;
}
int main()
{
	map<string, string> my_map;
	//Add_word("qwe", my_map);
	//Reduct_word("qwe", my_map);
	//ofstream ofile("data.txt", ios_base::out | ios_base::app);
	//ofile.close();
		ifstream ifile("data.txt", ios_base::in | ios_base::app);

		while (!(eof(ifile))

	ifile >> my_map;

	for (auto i : my_map)
	{
		cout << "Key: " << i.first << " Value: " << i.second << endl;
		cout << "------------------\n";
	}
	system("pause");
	return 0;
}