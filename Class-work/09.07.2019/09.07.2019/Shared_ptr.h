#pragma once
template<typename T>
class Unique_ptr
{
	T *ptr;
public:
	template<typename T>
	Unique_ptr(T*ptr)
	{
		this->ptr=ptr;
	}
	template<typename T>
	Unique_ptr operator=(T*ptr)
	{

	}
	~Unique_ptr()
	{
		delete[] ptr;
	}
};

