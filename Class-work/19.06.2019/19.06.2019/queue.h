#pragma once
#include "List.h"
template<typename T>
class queue
{
	List list_;
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
	int num_= this->list_.head->num;
	this->list_.DeleteHead();
	return num_;
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
	//List list2= nullptr;
	//for (int i = 0; i < this->size; i++)
	//{
	//	list2 = this->list_.head->next;
	//	std::cout << list2.head->num;
	//}
}

template<typename T>
queue<T>::queue()
{
	this->size = 0;
}

template<typename T>
queue<T>::~queue()
{
	//list_.clear();
}
