#pragma once
#include "List.h"
template<typename T>
class queue
{
	std::List list_;
	int size;
public:
	T exstract();
	void add(T data);
	void show();
	queue();
	~queue();
};

template<typename T>
T queue<T>::exstract()
{
	return this->list_.;
}

template<typename T>
void queue<T>::add(T data)
{
	list_.AddTail(data);
	this->size++;
}

template<typename T>
void queue<T>::show()
{

	for (int i = 0; i < this->size; i++)
	{
		std::cout << list_;
	}
}

template<typename T>
queue<T>::queue()
{
	this->size = 0;
}

template<typename T>
queue<T>::~queue()
{
	list_.clear();
}
