#pragma once

// Двузв'язний список
class List
{
private:
	// Опис елемента
	struct Element
	{
		int num;		// дані
		Element * next;	// зв'язок з наступним елементом
		Element * prev;	// зв'язок з попереднім елементом
	};

	Element * head;		// голова списка (перший елемент)
	Element * tail;		// хвіст списка (останній елемент)
	int size;

public:
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
	void AddTail(int data);
	List operator+(const List & other)const;
	List(const List & other);
	List(List && other);
	// Добавлення елемента на початок списку
	void AddHead(int data);

	// Добавлення елемента в позицію
	void Add(int pos, int data);
	void Delete_list(List &obj);
	// Видалення голови (першого елемента)
	void DeleteHead();
	List operator-();
	List& operator=(const List&other);
	List& operator=(List&&other);
	// Показ всіх елементів
	void ShowList() const;
};