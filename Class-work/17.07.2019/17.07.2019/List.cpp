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

void List::DeleteHead()
{
	if (!IsEmpty())
	{
		Element * temp = head;
		head = head->next;
		head->prev = nullptr;
		delete temp;

		if (head == nullptr)
			tail = nullptr;

		--size;
	}
}

void List::DeleteTail()
{
	if (!IsEmpty())
	{
		Element * temp = head;
		head = tail->prev;
		head->next = nullptr;
		delete temp;

		if (head == nullptr)
			tail = nullptr;

		--size;
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

	for (Element * item = head; item != nullptr; item = item->next)
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

void List::Delete_list(List &obj)
{
	while (size != 0)
	{
		obj.DeleteHead();
	}
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
	Element *tmp_other = other.head;
	while (tmp_other != nullptr)
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
void List::delete_element_index(int index_)
{
	if (IsEmpty())
	{
		return;
	}
	if (index_ > size || index_ < 0)
	{
		return;
	}
	if (index_ == 0)
	{
		this->DeleteHead();
		return;
	}
	if (index_ == this->size)
	{
		this->DeleteTail();
		return;
	}
		Element * temp = this->head;
		for (int i = 0; i < size; i++)
		{
			if (i == index_)
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				break;
			}
			temp =temp->next;
		}
		delete temp;

		--size;
}
List List::sort_list(sort_ sort_by = Ascending)
{
	List buf_(*this);
	Element * temp = buf_.head;
	int buf = 0;
	if (sort_by == Ascending)
	{
		for (int j = 0; j < size; j++)
		{
			for (int i = 0; i < size - 1 - j; i++)
			{
				if (temp->num > temp->next->num)
				{
					buf = temp->next->num;
					temp->next->num = temp->num;
					temp->num = buf;
				}
				temp = temp->next;
			}
			temp = buf_.head;
		}
	}
	else
	{
		for (int j = 0; j < size; j++)
		{
			for (int i = 0; i < size - 1 - j; i++)
			{
				if (temp->num < temp->next->num)
				{
					buf = temp->next->num;
					temp->next->num = temp->num;
					temp->num = buf;
				}
				temp = temp->next;
			}
			temp = buf_.head;
		}
	}
	return buf_;
}
int List::search_elem(int elem)
{
	Element * temp = this->head;
	for (int i = 0; i < size; i++)
	{
		if (temp->num == elem)
		{
			return i + 1;
		}
		temp = temp->next;
	}
	return NULL;
}

