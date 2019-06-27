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
		this->head = this->tail = newElement;
	else
	{
		this->tail->next = newElement;
		newElement->prev = tail;
		this->tail = newElement;
	}
	++size;
}
List List::operator+(const List &other)const
{
	List tmp1(*this);
	List tmp2(other);
	tmp1.tail->next = tmp2.head;
	tmp2.head->prev = tmp1.tail;
	return tmp1;
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

void List::Delete_list(List &obj)
{
	while (size!=0)
	{
		obj.DeleteHead();
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

List List::operator-()
{
	List tmp_(*this);
	Element *tmp = tmp_.head;
	Element *tmp2 = this->tail;
	for (int i = 0; tmp!=nullptr; i++)
	{
		tmp->num = tmp2->num;
		tmp = tmp->next;
		tmp2 = tmp2->prev;
	}
	return tmp_;
}

List& List::operator=(const List & other)
{
	Element *tmp = this->head;
	if (!this->IsEmpty())
	{
		this->Delete_list(*this);
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

List& List::operator=(List && other)
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
	for (Element * item = this->head; item != nullptr; item = item->next)
	{
		cout << "Element: " << item->num << endl;
	}

}