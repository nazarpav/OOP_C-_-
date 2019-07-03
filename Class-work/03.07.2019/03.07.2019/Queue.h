#pragma once

// Черга - динамічна структура даних, що представляє із
// себе упорядкований набір елементів, в якій діє принцип
// FIFO (First In First Out) або «перший прийшов перший пішов»
namespace Queue
{
	class Queue
	{
		// Черга
		int ** data;
		// Максимальний розмір черги
		int maxSize;
		// Теперішній розмір черги
		int size;

	public:
		friend void print(Queue& q, int i);
		// Конструктор
		Queue(int maxSize);
		Queue(const Queue&);
		// Деструктор
		~Queue();

		void sort();

		// Добавлення елемента в чергу
		void Add(int elem, int priority);
		// Вилучення елемента з черги
		int Extract();
		// Перевірка чи черга є порожньою
		bool IsEmpty() const;
		// Перевірка чи черга є повна
		bool IsFull() const;
		// Кількість елементів в черзі
		int GetCount() const;
		// Очистка черги
		void Clear();
		// Показ елементів в черзі
		void Show() const;
	};
}