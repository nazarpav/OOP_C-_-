#include "Queue.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//
//const short priority = 0;
//const short sign_operation = 1;
//const short left = 2;
//const short right = 3;
enum sign_operation { plus = 1, minus = -1, mult = 2, div = -2, null_ = 0 };

Queue::Queue()
{
	
}

Queue::Queue(const Queue & other)
{
	this->data = other.data;
}

Queue::~Queue()
{
	// Видалення черги
}
void Queue::sort()
{
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data.size() -i; j++)
		{
			if (data[j].priority < data[j+1].priority)
			{
				My_vector temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}
void Queue::Add(int left, int right, int priority, sign_operation sign_operation)
{
	data[data.size()].left = left;
	data[data.size()].right = right;
	data[data.size()].priority = abs(sign_operation);
	data[data.size()].sop = sign_operation;
	this->sort();
}

int Queue::Extract()
{
	if (!IsEmpty())
	{
		// Зберігаємо перший елемент
		My_vector first = data[0];
		// Підсовуємо всі елементи
		for (int i = 0; i < data.size() - 2; i++)
		{
			data[i] = data[i+1];
		}
		this->sort();
		switch (first.sop)
		{
		case plus:
			return first.left+first.right;
			break;
		case minus:
			return first.left - first.right;
			break;
		case mult:
			return first.left * first.right;
			break;
		case div:
			return first.left / first.right;
			break;
		default:
			throw("Eror");
			break;
		}
	}
}

bool Queue::IsEmpty() const
{
	// Порожня?
	return data.size() == 0;
}

int Queue::GetCount() const
{
	// Розмір черги
	return data.size();
}

void Queue::Clear()
{
	// Очистка черги
	data.clear();
}
