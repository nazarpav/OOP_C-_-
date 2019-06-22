#pragma once

// Опис елемента

class List
{
struct Element
{
	int num;		// дані
	Element * next;	// зв'язок з наступним елементом
};
private:
	Element * head;		// голова списка (перший елемент)
	Element * tail;		// голова списка (перший елемент)
	int size;
public:
	// Конструктор по замовчуванню
	List()
	{ 
		// На початку список порожній,
		// тобто першого елемента не існує
		head = nullptr; 
		tail = nullptr;
		size = 0;
	}

	bool IsEmpty() const { return head == nullptr; }

	// Добавлення елемента вкінець списку
	void AddToEnd(int data);
	// Добавлення елемента на початок списку
	void AddToBegin(int data);

	//replace element
	int Replace_element(int Replaceable_element, int exchangeable);

	//search element
	int search_element(int elem);

	// Видалення голови (першого елемента)
	void DeleteHead();

	void Delete_tail();

	void del_elem_ind(int ind);

	void add_elem_ind(int data, int ind);

	// Показ всіх елементів
	void ShowList() const;
};