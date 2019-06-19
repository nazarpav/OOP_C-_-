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
		tail = tail;
		temp = nullptr;
	size--;
	}
}
void List::add_elem_ind(int data,int ind)
{
	Element * newElement = new Element;
	newElement->num = data;
	newElement->next = nullptr;
	Element * temp = head;
	cout << temp<<" _ " << head<<endl;
	size++;
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
			newElement->next = temp->next->next;
			temp->next = newElement;
			break;
		}
		temp = temp->next;
		temp = nullptr;
		cout << temp << " _ " << head << endl;
	}
}
void List::ShowList() const
{
	if (IsEmpty())
	{
		cout << "List is empty!\n";
		return;
	}

	/*Element * current = head;
	do
	{
		cout << "Element: " << current->num << endl;
		current = current->next;
	} while (current->next != nullptr);*/

	Element * current = head;
	while (current != nullptr)
	{
		cout << "Element: " << current->num << endl;
		current = current->next;
	}
	//cout << "Element: " << tail->num << endl;
	cout << "Element*: " << tail->next << endl;
}