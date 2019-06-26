#include "List.h"
#include <iostream>
using std::cout;
using std::endl;

void List::AddTail(int data)
{
	Element * newElement = new Element;
	newElement->num = data;
	newElement->next = nullptr;
	newElement->prev = nullptr;

	if (head == nullptr)
		head = tail = newElement;
	else
	{
		tail->next = newElement;
		newElement->prev = tail;
		tail = newElement;
	}
	++size;
}
List::List(const List& other)
{
	this->size = other.size;
	Element *tmp_other=other.head;
	while (tmp_other!=nullptr)
	{
		this->AddTail(tmp_other->num);
		tmp_other = tmp_other->next;
	}
}
List::List(List&& other)
{
	this->size = other.size;
	this->head = other.head;
	this->tail = other.tail;
	other.head = nullptr;
	other.tail = nullptr;
	other.size = 0;
}
void List::AddHead(int data)
{
	Element * newElement = new Element;
	newElement->num = data;
	newElement->prev = nullptr;
	newElement->next = nullptr;

	if (head == nullptr)
		head = tail = newElement;
	else
	{
		newElement->next = head;
		head->prev = newElement;
		head = newElement;
	}
	++size;
}

void List::Add(int pos, int data)
{
	if (pos > size + 1 || pos <= 0)
		return;

	if (pos == 1)
	{
		AddHead(data);
		return;
	}
	if (pos == size + 1)
	{
		AddTail(data);
		return;
	}

	Element * newElem = new Element;
	newElem->num = data;

	Element * temp = head;
	/*int counter = 0;
	while (temp != nullptr && counter != pos - 2)
	{
		temp = temp->next;
		++counter;
	}*/

	for (int p = 1; p != pos; ++p)
		temp = temp->next;

	newElem->next = temp;
	newElem->prev = temp->prev;
	temp->prev->next = newElem;
	temp->prev = newElem;

	++size;
}

void List::delete_list()
{
	while (size!=0)
	{
		DeleteHead();
	}
}

void List::DeleteHead()
{
	if (!IsEmpty())
	{
		Element * temp = head;
		head = head->next;
		if(head!= nullptr)
		head->prev = nullptr;
		delete temp;

		if (head == nullptr)
			tail = nullptr;

		--size;
	}
}

List List::operator=(const List & other)
{
	Element *tmp = this->head;
	if (!this->IsEmpty())
	{
		this->delete_list();
	}
	this->size = other.size;
	tmp = other.head;
	while (tmp != nullptr)
	{
		this->AddTail(tmp->num);
		tmp = tmp->next;
	}
	return *this;
}

List List::operator=(List && other)
{
	this->size = other.size;
	this->head = other.head;
	this->tail = other.tail;
	other.head = nullptr;
	other.tail = nullptr;
	other.size = 0;
	return *this;
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
	for (Element * item = this->head; item != nullptr; item = item->next)
	{
		cout << "Element: " << item->num << endl;
	}

	/*Element * current = head;
	while (current != nullptr)
	{
		cout << "Element: " << current->num << endl;
		current = current->next;
	}*/
}