#include "Queue.h"
#include <iostream>

Queue::Queue(int maxSize)
{
	// Отримуємо максимальний розмір черги
	this->maxSize = maxSize;
	// Створюємо черу
	data = new int*[maxSize];
	for (int i = 0; i < maxSize; i++)
	{
		data[i] = new int[2];
	}
	// На початку черга порожня
	size = 0;
}

Queue(const Queue & other):Queue(other.maxSize)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < size; j++)
		{
			this->data[j][i] = other.data[j][i];
		}
	}
	this->maxSize=other.maxSize;
	this->size=other.size;
}

Queue::~Queue()
{
	// Видалення черги
	for (int i = 0; i < maxSize; i++)
	{
		delete[] data[i];
	}
	delete[]data;
}

void Queue::sort()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-i; j++)
		{
			if (data[j][1] < data[j + 1][1])
			{
				int *temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}
void Queue::Add(int elem,int priority)
{
	// Якщо черга має місце,
	// тоді добавляємо новий елемент
	// і змільшуємо розмір черги
	if (!IsFull())
	{
		data[size++][0] = elem;
		data[size - 1][1] = priority;
	}
}

int Queue::Extract()
{
	// Якщо черга не порожня, тоді повертаємо
	// той, який прийшов перший і "підсовуємо" чергу
	if (!IsEmpty())
	{
		// Зберігаємо перший елемент
		int first = data[0][0];
		// Підсовуємо всі елементи
		for (int i = 0; i < size - 1; i++)
		{
			data[i][0] = data[i+1][0];
		}

		// Проста черга
		--size;					// зменшуємо розмір черги

		// Кільцева черга
	//	data[size - 1] = first;	// переносимо перший елемент вкінець
								// не змінюючи розмір черги

		return first; // повертаємо збережений елемент
	}
}

bool Queue::IsEmpty() const
{
	// Порожня?
	return size == 0;
}

bool Queue::IsFull() const
{
	// Максимально заповнена?
	return size == maxSize;
}

int Queue::GetCount() const
{
	// Розмір черги
	return size;
}

void Queue::Clear()
{
	// Очистка черги
	size = 0;
}

void Queue::Show() const
{
	std::cout << "\n-----------------------------------\n";
	// Показ черги
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i][0] << "  ";
	}
	std::cout << "\n-----------------------------------\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i][1] << "  ";
	}
	std::cout << "\n-----------------------------------\n";
}
