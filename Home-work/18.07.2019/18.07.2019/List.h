#pragma once
#include <iostream>
#include<string>
#include"Element.h"
using namespace std;

class List
{
private:
	// Опис елемента
	Element * head;		// голова списка (перший елемент)
	Element * tail;		// хвіст списка (останній елемент)

	int size;
public:
	friend std::istream& operator>> (std::istream &in, List &point);
	friend std::ostream& operator<< (std::ostream &out, const List &point);
	enum sort_ { Descending , Ascending};
	// Конструктор по замовчуванню
	List()
	{
		// На початку список порожній,
		// тобто першого елемента не існує
		head = tail = nullptr;
		size = 0;
	}

	bool IsEmpty() const { return size == 0; }

	// Добавлення елемента вкінець списку
	void AddTail(string firm_name, string owner, string tel_num, string addres, string firm_activity);
	void AddTail(Element other);
	// Добавлення елемента на початок списку
	void AddHead(string firm_name, string owner, string tel_num, string addres, string firm_activity);

	// Добавлення елемента в позицію
	void Add(int pos,string firm_name, string owner, string tel_num, string addres, string firm_activity);

	// Видалення голови (першого елемента)
	void DeleteHead();

	void DeleteTail();

	// Показ всіх елементів
	void ShowList() const;

	void Delete_list(List & obj);

	List operator+(const List & other) const;

	List(const List & other);

	List(List && other);

	List & operator=(const List & other);

	List & operator=(List && other);

	void delete_element_index(int index_);

	List sort_list(sort_ sort_by);

	int search_firm_name(string data);
	int search_owner(string data);
	int search_tel_num(string data);
	int search_addres(string data);
	int search_firm_activity(string data);
};
