#pragma once
template<typename T>
class Unique_ptr
{
	T *ptr;
public:
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
	T* operator->()
	{
		return this->ptr;
	}
	T operator[](int ind)
	{
		sizeof(T);
		return *this->ptr[ind];
	}
	template<typename T>
	T Get()
	{
		return this->ptr;
	}
	explicit bool operator bool()
	{
		return this->ptr == nullptr;
	}
	~Unique_ptr()
	{
		delete[] ptr;
	}
};
