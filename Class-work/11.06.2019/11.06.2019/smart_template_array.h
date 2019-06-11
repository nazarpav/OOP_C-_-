#pragma once
#include<ctime>
#include <iostream>
using namespace std;
template <typename T>
class S_T_A
{
public:
	S_T_A(T elem, int size);
	~S_T_A();
	void add_elem(T elem);
	void insert_elem(T elem, int index);
	void delete_head();
	void fill();
	void show();
	int get_apper_bound();
	S_T_A<T> operator+(S_T_A & other);
private:
	void resize();
	T *arr;
	int size;
	int max_size;
const	int GROW = 5;
};


template <typename T>
S_T_A<T>::S_T_A(T elem,int size)
{
	this->max_size = size + this->GROW;
	this->size = size;
	this->arr = new T[this->max_size];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = elem;
	}
}

template <typename T>
S_T_A<T>::~S_T_A()
{
	delete[]this->arr;
}

template<typename T>
 void S_T_A<T>::add_elem(T elem)
{
	size++;
	if (this->size <= max_size)
	{
		this->resize();
	}
	this->arr[size-1] = elem;

}

template<typename T>
 void S_T_A<T>::insert_elem(T elem, int index)
{
	 this->size++;
	 T buf;
	 int j=0;
	 if (this->size >= max_size)
	 {
		 this->resize();
	 }
	 for (int i = 0; i < size; i++)
	 {
		 if (i == index)
		 {
			 buf = this->arr[i];
			 this->arr[i] = elem;
			 continue;
		 }
		 else if(i > index&&i!=size-1)
		 {
			 this->arr[this->size - j-1]=this->arr[this->size - j - 2];
			 cout << this->arr[this->size - j]<<endl;
			 cout << this->arr[this->size - j-1] << endl;
			 j++;
			 continue;
		 }
		 else if(i==size-1)
		 {
		 this->arr[this->size - j - 1] = buf;
		 }
	 }
}

template<typename T>
 void S_T_A<T>::delete_head()
{
	 this->size --;
}

template<typename T>
 void S_T_A<T>::fill()
{
	 for (int i = 0; i < size; i++)
	 {
		 cin>>this->arr[i];
	 }
}

 template<typename T>
 void S_T_A<T>::show()
 {
	 for (int i = 0; i < this->size; i++)
	 {
		 cout << this->arr[i]<<" ";
	 }
	 cout << endl;
 }

template<typename T>
 int S_T_A<T>::get_apper_bound()
{
	return this->size-1;
}

 template<typename T>
 S_T_A<T> S_T_A<T>::operator+(S_T_A & other)
 {
	 int j = 0;
	 S_T_A obj(this->arr[0], this->size + other.size);
	 j++;
	 obj.size = this->size + other.size;
	 for (int i = 0; i < this->size; i++)
	 {
		 obj.arr[j] = this->arr[i];
		 j++;
	 }
	 for (int i = 0; i < this->size; i++)
	 {
		 obj.arr[j] = other.arr[i];
		 j++;
	 }
	 return obj;
 }

template<typename T>
 void S_T_A<T>::resize()
{
	T *buf = new T [this->size + (this->GROW * 2)];
	
	for (int i = 0; i < this->size; i++)
	{
		buf[i] = this->arr[i];
	}
	delete[]arr;
	arr = buf;
	this->max_size = this->size + (this->GROW *2);
}
