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
}

void List::DeleteHead()
{
	if (!IsEmpty())
	{
		Element * temp = head;
		head = head->next;
		delete temp;
	}
}

//void List::AddToHead(int data)
//{
//	Element * newElement = new Element;
//	newElement->num = data;
//	newElement->next = this->head->next;
//}
//
//void List::AddToTail(int data)
//{
//	Element * newElement = new Element;
//	newElement->num = data;
//	this->tail->next= newElement;
//	newElement->next = nullptr;
//}

void List::DeleteFromTail()
{
	if (tail == nullptr)
	{
		return;
	}
	Element * current = head;
	while (current->next != tail)
	{
		current = current->next;
	}
	current->next = nullptr;
	delete[] this->tail;
	this->tail = current;
}

void List::DeleteAll()
{
	while (IsEmpty())
	{
		DeleteFromTail();
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
}