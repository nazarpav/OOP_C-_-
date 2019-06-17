#pragma once

class List
{
private:
	// Опис елемента
	struct Element
	{
		int num;		// дані
		Element * next;	// зв'язок з наступним елементом
	};
	Element * head;		// голова списка (перший елемент)
	Element * tail;		// голова списка (перший елемент)

public:
	// Конструктор по замовчуванню
	List()
	{ 
		// На початку список порожній,
		// тобто першого елемента не існує
		head = nullptr; 
		tail = nullptr;
	}

	bool IsEmpty() const { return head == nullptr; }

	// Добавлення елемента вкінець списку
	void AddToEnd(int data);
	// Добавлення елемента на початок списку
	void AddToBegin(int data);

	// Видалення голови (першого елемента)
	void DeleteHead();

	//void AddToHead(int data);

	//void AddToTail(int data);

	void DeleteFromTail();

	void DeleteAll();


	// Показ всіх елементів
	void ShowList() const;
};