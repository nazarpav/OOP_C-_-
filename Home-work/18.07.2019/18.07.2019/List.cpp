#include <iostream>
#include <string>
#include "List.h"
using namespace std;

void List::AddTail(string firm_name,string owner,string tel_num,string addres,string firm_activity)
{
	Element * newElement = new Element;
	newElement->firm_name = firm_name;
	newElement->owner = owner;
	newElement->tel_num = tel_num;
	newElement->addres = addres;
	newElement->firm_activity = firm_activity;
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

void List::AddTail(Element other)
{
	AddTail(other.firm_name, other.owner, other.tel_num, other.addres, other.firm_activity);
}

void List::AddHead(string firm_name, string owner, string tel_num, string addres, string firm_activity)
{
	Element * newElement = new Element;
	newElement->firm_name = firm_name;
	newElement->owner = owner;
	newElement->tel_num = tel_num;
	newElement->addres = addres;
	newElement->firm_activity = firm_activity;
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

void List::Add(int pos, string firm_name, string owner, string tel_num, string addres, string firm_activity)
{
	if (pos > size + 1 || pos <= 0)
		return;

	if (pos == 1)
	{
		AddHead(firm_name, owner, tel_num, addres, firm_activity);
		return;
	}
	if (pos == size + 1)
	{
		AddTail(firm_name, owner, tel_num, addres, firm_activity);
		return;
	}

	Element * newElem = new Element;
	newElem->firm_name = firm_name;
	newElem->owner = owner;
	newElem->tel_num = tel_num;
	newElem->addres = addres;
	newElem->firm_activity = firm_activity;

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

	for (Element * item = head; item != nullptr; item = item->next)
	{
		cout << "Element: " <<endl<< *item << endl<<endl;
	}
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
		this->AddTail(tmp_other->firm_name, tmp_other->owner, tmp_other->tel_num, tmp_other->addres, tmp_other->firm_activity);
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
		this->AddTail(tmp->firm_name, tmp->owner, tmp->tel_num, tmp->addres, tmp->firm_activity);
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
	Element buf;
	if (sort_by == Ascending)
	{
		for (int j = 0; j < size; j++)
		{
			for (int i = 0; i < size - 1 - j; i++)
			{
				if (temp> temp->next)
				{
					buf = *temp->next;
					*temp->next = *temp;
					*temp = buf;
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
				if (temp < temp->next)
				{
					buf = *temp->next;
					*temp->next = *temp;
					*temp = buf;
				}
				temp = temp->next;
			}
			temp = buf_.head;
		}
	}
	return buf_;
}
/*
string firm_name;
string owner;
string tel_num;
string addres;
string firm_activity;
		*/
int List::search_firm_name(string data)
{
	Element * temp = this->head;
	for (int i = 0; i < size; i++)
	{
		if (temp->firm_name == data)
		{
			return i + 1;
		}
		temp = temp->next;
	}
	return NULL;
}
int List::search_owner(string data)
{
	Element * temp = this->head;
	for (int i = 0; i < size; i++)
	{
		if (temp->owner == data)
		{
			return i + 1;
		}
		temp = temp->next;
	}
	return NULL;
}
int List::search_tel_num(string data)
{
	Element * temp = this->head;
	for (int i = 0; i < size; i++)
	{
		if (temp->tel_num == data)
		{
			return i + 1;
		}
		temp = temp->next;
	}
	return NULL;
}
int List::search_addres(string data)
{
	Element * temp = this->head;
	for (int i = 0; i < size; i++)
	{
		if (temp->addres == data)
		{
			return i + 1;
		}
		temp = temp->next;
	}
	return NULL;
}
int List::search_firm_activity(string data)
{
	Element * temp = this->head;
	for (int i = 0; i < size; i++)
	{
		if (temp->firm_activity == data)
		{
			return i + 1;
		}
		temp = temp->next;
	}
	return NULL;
}

std::ostream& operator<< (std::ostream &out, const List &point)
{
	out << *point.head<<endl;
	return out;
}
std::istream& operator>> (std::istream &in, List &point)
{
	Element tmp;
	in >> tmp;
	point.AddTail(tmp);
	return in;
}