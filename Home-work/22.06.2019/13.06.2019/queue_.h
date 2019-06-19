#pragma once
class queue_
{
	short size;
	char arr [10];
public:
	void push(char elem)
	{
		if (size >= 10)
		{
			return;
		}
		size++;
		this->arr[size - 1] = elem;
	}
	char pop()
	{
		if (size == 0)
		{
			return NULL;
		}
		size--;
		char tmp=arr[0];
		for (int i = 0; i < size; i++)
		{
			arr[i] = arr[i + 1];
		}
		return tmp;
	}
	queue_()
	{
		size = 0;
	};
};

