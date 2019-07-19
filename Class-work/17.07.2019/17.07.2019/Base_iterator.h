#pragma once
template <class T>
class base_iterator
{
protected:
	T* data;
public:
	base_iterator() {}
	base_iterator(T* data) : data(data) {}
	virtual base_iterator& operator ++ () = 0;
	virtual base_iterator& operator ++ (int) = 0;
	virtual base_iterator& operator -- () = 0;
	virtual base_iterator& operator -- (int) = 0;
	virtual T operator * () const
	{
		return *data;
	}
};

template <typename T>
void Show_base_iterator(base_iterator<T>& iterBegin, base_iterator<T>& iterEnd)
{
	for (base_iterator<T> i = iterBegin; i != iterEnd; ++i)
	{
		cout << "Element: " << *i << endl;
	}
}