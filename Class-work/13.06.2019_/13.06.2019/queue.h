#pragma once
template<typename T>
class queue
{
	const int max_size = 10;
	T queue_[max_size];
	int queue_priority[max_size];
	int size;
public:
	bool IsEmpty()
	{
		return size == 0;
	}
	bool IsFull()
	{
		return size == max_size;
	}
	void PullHighestPriorityElement();
	void InsertWithPriority(T elem, int priority);
	queue();
	~queue();
};

template<typename T>
void queue<T>::PullHighestPriorityElement()
{
	int pr=0;
	T buf_arr[this->max_size];
	int ind = 0;
	for (int i = 0; i < length; i++)
	{
		if (queue_priority > pr)
		{
			pr = queue_priority;
			ind = i;
		}
	}

}

template<typename T>
void queue<T>::InsertWithPriority(T elem, int priority)
{
	if (this->IsFull() == true)
		return;
	this->queue_[this->size] = elem;
	this->queue_priority[this->size] = priority;
}

template<typename T>
queue<T>::queue()
{
}

template<typename T>
queue<T>::~queue()
{
}
