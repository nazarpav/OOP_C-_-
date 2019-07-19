#pragma once
#include<iostream> 
template<typename T_>
class Shared_ptr
{
	T_ *ptr;
	short counter;
public:
	template<typename T>
	friend std::ostream& operator<< (std::ostream &out, const Shared_ptr<T> &point);
	template<typename T>
	friend std::istream& operator>> (std::istream &in, Shared_ptr<T> &point);
	template<typename T>
	Shared_ptr(T*ptr)
	{
		counter = 0;
		this->ptr = ptr;
	}
	template<typename T>
	Shared_ptr* operator=(T*&&ptr)
	{
		this->ptr = ptr;
		ptr = nullptr;
		return this;
	}
	template<typename T>
	T make_shared()
	{
		counter++;
		return *this;
	}
	template<typename T>
	T* Release()
	{
		T *tmp = this->ptr;
		this->ptr = nullptr;
		return tmp;
	}
	template<typename T>
	void Reset(T*& ptr)
	{
		delete[] this->ptr;
		this->ptr = ptr;
	}
	template<typename T>
	void Swap(T & ptr_u)
	{
		T* tmp = ptr_u;
		ptr_u = this;
		this = tmp;
	}
	template<typename T>
	T operator*()
	{
		return *this->ptr;
	}
	template<typename T>
	T* operator->()
	{
		return this->ptr;
	}
	template<typename T>
	T operator[](int ind)
	{
		sizeof(T);
		return *this->ptr[ind];
	}
	//template<typename T>
	T_* Get()
	{
		return this->ptr;
	}
	explicit operator bool()
	{
		return this->ptr == nullptr;
	}
	~Shared_ptr()
	{
		if (this->counter == 1)
			delete[] ptr;
		else
			this->counter--;
	}
	bool operator<(Shared_ptr & other)
	{
		return *this->ptr < other.ptr;
	}
	bool operator>(Shared_ptr & other)
	{
		return !(*this < other);
	}
	bool operator==(Shared_ptr & other)
	{
		return this->ptr == other.ptr;
	}
	bool operator!=(Shared_ptr & other)
	{
		return !(*this == other);
	}
	bool operator<=(Shared_ptr & other)
	{
		return *this->ptr <= other.ptr;
	}
	bool operator>=(Shared_ptr & other)
	{
		return *this->ptr >= other.ptr;
	}
};
template<typename T>
std::ostream& operator<< (std::ostream &out, const Shared_ptr<T> &point)
{
	out << *point.ptr;
	return out;
}
template<typename T>
std::istream& operator>> (std::istream &in, Shared_ptr<T> &point)
{
	in >> *point.ptr;
	return in;
}
