#pragma once
#include<iostream> 
template<typename T_>
class Unique_ptr
{
	T_ *ptr;
public:
	template<typename T>
	friend std::ostream& operator<< (std::ostream &out, const Unique_ptr<T> &point);
	template<typename T>
	friend std::istream& operator>> (std::istream &in, Unique_ptr<T> &point);
	template<typename T>
	Unique_ptr(T*ptr)
	{
		this->ptr = ptr;
	}
	template<typename T>
	Unique_ptr* operator=(T*&&ptr)
	{
		this->ptr = ptr;
		ptr = nullptr;
		return this;
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
	void Swap(Unique_ptr & ptr_u)
	{
		Unique_ptr* tmp = ptr_u;
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
	~Unique_ptr()
	{
		delete[] ptr;
	}
	template<typename T>
	bool operator<(T & other)
	{
		return *this->ptr < other.ptr;
	}
	template<typename T>
	bool operator>(T & other)
	{
		return !(*this<other);
	}
	template<typename T>
	bool operator==(T & other)
	{
		return this->ptr == other.ptr;
	}
	template<typename T>
	bool operator!=(T & other)
	{
		return !(*this==other);
	}
	template<typename T>
	bool operator<=(T & other)
	{
		return *this->ptr <= other.ptr;
	}
	template<typename T>
	bool operator>=(T & other)
	{
		return *this->ptr >= other.ptr;
	}
};
template<class T>
std::ostream& operator<< (std::ostream &out, const Unique_ptr<T>&point)
{
	out << point.ptr;
	return out;
}
template<class T>
std::istream& operator>> (std::istream &in, Unique_ptr < T> &point)
{
	in >> point.ptr;
	return in;
}