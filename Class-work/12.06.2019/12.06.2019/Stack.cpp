#include "Stack.h"

bool Stack::Push(char elem)
{
	if (!IsFull())
	{	
		data[++topIndex] = elem;
		return true;
	}
	return false;
}


char Stack::Pop()
{
	if (!IsEmpty())
		return data[topIndex--];

	return 0;
}

int Stack::GetCount() const
{
	return topIndex + 1;
}

bool Stack::IsEmpty() const
{
	return topIndex == EMPTY;
}

bool Stack::IsFull() const
{
	return topIndex == FULL;
}

void Stack::Clear()
{
	topIndex = EMPTY;
}
