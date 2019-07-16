#pragma once
#include<vector>
using namespace std;
// Черга - динамічна структура даних, що представляє із
// себе упорядкований набір елементів, в якій діє принцип
// FIFO (First In First Out) або «перший прийшов перший пішов»
//enum sign_operation { plus = 1, minus = -1, mult = 2, div = -2, null_ = 0 };

class My_vector
{
public:
	My_vector()
	{
		this->left = 0;
		this->right = 0;
		this->priority = 0;
		this->sop = null_;
	};
	My_vector()
	{
		this->left = 0;
		this->right = 0;
		this->priority = 0;
		this->sop = null_;
	};
	My_vector(My_vector &other)
	{
		this->left = other.left;
		this->right = other.right;
		this->priority = other.priority;
		this->sop = other.sop;
	};
	void operator=(const My_vector&other)
	{
		this->left = other.left;
		this->right = other.right;
		this->priority = other.priority;
		this->sop = other.sop;
	}
	~My_vector()
	{

	};
	void Priority_left_plus()
	{
		this->priority++;
	}
	int left;
	int right;
	int priority;
	sign_operation sop;
};

class Queue
{
	// Черга
	/*vector < vector <int> > a(n, vector < pair<int, std::string>(4));*/
	// Максимальний розмір черги
	vector<My_vector> data;
	// Теперішній розмір черги
public:
	// Конструктор
	Queue();
	Queue(const Queue&);
	// Деструктор
	~Queue();

	void sort();

	// Добавлення елемента в чергу
	void Add(int left, int right, int priority, sign_operation sing_operation);
	// Вилучення елемента з черги
	int Extract();
	// Перевірка чи черга є порожньою
	bool IsEmpty() const;
	// Кількість елементів в черзі
	int GetCount() const;
	// Очистка черги
	void Clear();
};