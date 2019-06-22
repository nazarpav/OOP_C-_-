#include "List.h"
#include <iostream>
using std::cout;
using std::endl;

void List::AddToEnd(int data)
{
	Element * newElement = new Element;
	newElement->num = data;
	newElement->next = nullptr;

	if (head == nullptr)
	{
		head = tail = newElement;
	}
	else
	{
		tail->next = newElement;
		tail = newElement;
	}
	size++;
}

void List::AddToBegin(int data)
{
	Element * newElement = new Element;
	newElement->num = data;
	newElement->next = nullptr;

	if (head == nullptr)
		head = tail = newElement;
	else
	{
		newElement->next = head;
		head = newElement;
	}
	size++;
}
int List::Replace_element(int Replaceable_element/*елемент для заміни*/,int exchangeable/*новий елемент*/)
{
	Element * temp = head;
	int counter = 0;
	for (int i = 0; temp->next != nullptr; i++)
	{
		if (temp->num == Replaceable_element)
		{
			counter++;
			temp->num = exchangeable;
		}
		temp = temp->next;
	}
	if(counter==0)
	return -1;
	return counter;
	/*temp = nullptr;
	newElement = nullptr;*/
}
int List::search_element(int elem)
{
	Element * temp = head;
	for (int i = 0; temp->next!=nullptr; i++)
	{
		if (temp->num==elem)
		{
			return i;
		}
		temp = temp->next;
	}
	return NULL;
	/*temp = nullptr;
	newElement = nullptr;*/
}
void List::DeleteHead()
{
	if (this->size != 0)
	{
		Element * temp = head;
		head = head->next;
		delete temp;
	size--;
	}
}
void List::Delete_tail()
{
	if (this->size!=0)
	{
		Element * temp = head;
		while(temp->next!=this->tail)
		{
			temp = temp->next;
		}
		delete tail->next;
		delete tail;
		temp->next = nullptr;
		tail = temp;
		temp = nullptr;
	size--;
	}
}
void List::del_elem_ind(int ind)
{
	if (ind<0 || ind>size - 1)
	{
		return;
	}
	Element * temp = head;
	Element * temp2 = head;
	if (ind == 0)
	{
		this->DeleteHead();
		return;
	}
	else if (ind == size - 1)
	{
		this->Delete_tail();
		return;
	}
	for (int i = 0; true; i++)
	{
		if (i == ind - 1)
		{
			temp2 = temp->next;
			temp->next=temp->next->next;
			delete temp2;
			break;
		}
		temp = temp->next;
	}
	/*temp = nullptr;
	newElement = nullptr;*/
	size--;
}
void List::add_elem_ind(int data,int ind)
{
	if (ind<0 || ind>size - 1)
	{
		return;
	}
	Element * newElement = new Element;
	newElement->num = data;
	newElement->next = nullptr;
	Element * temp = head;
	if (ind == 0)
	{
		AddToBegin(data);
		return;
	}
	else if (ind == size - 1)
	{
		AddToEnd(data);
		return;
	}
	for (int i = 0; true; i++)
	{
		if (i == ind-1)
		{
			newElement->next = temp->next;
			temp->next = newElement;
			break;
		}
		temp = temp->next;
	}
		/*temp = nullptr;
		newElement = nullptr;*/
	size++;
}
void List::ShowList() const
{
	if (IsEmpty())
	{
		cout << "List is empty!\n";
		return;
	}

	Element * current = head;
	while (current != nullptr)
	{
		cout << "Element: " << current->num << endl;
		current = current->next;
	}
}