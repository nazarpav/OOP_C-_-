#pragma once
#include"Base_iterator.h"
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
	class iterator : public base_iterator<Element>
	{
	public:
		iterator() {}
		iterator(Element* data) : base_iterator(data) {}
		iterator& operator ++()
		{
			data = data->next;
			return *this;
		}
		iterator& operator ++ (int)
		{
			iterator copy = *this;
			data = data->next;
			return copy;
		}
		iterator& operator --()
		{
			data = data->prev;
			return *this;
		}
		iterator& operator -- (int)
		{
			iterator copy = *this;
			data = data->prev;
			return copy;
		}
	};
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
	void AddTail(int data);
	// Добавлення елемента на початок списку
	void AddHead(int data);

	// Добавлення елемента в позицію
	void Add(int pos, int data);

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
	int search_elem(int elem);
};

template <class T>
class iterator : public base_iterator<T>
{
public:
	iterator() {}
	iterator(T* data) : base_iterator(data) {}
	iterator& operator ++ ()
	{
		data++;
		return *this;
	}
	iterator& operator ++ (int)
	{
		iterator copy = *this;
		data++;
		return copy;
	}
};

