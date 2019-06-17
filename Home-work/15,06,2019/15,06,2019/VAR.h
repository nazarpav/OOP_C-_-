//#pragma once
//#include <iostream>
//#include <string>
//using namespace std;
//
//template < typename T >
//class VAR
//{
//public:
//	VAR(T var);
//	VAR();
//	VAR(const VAR<T>&);
//	void show();
//	VAR operator+(const VAR&other)const;
//	VAR operator=(const VAR&other)const;
//private:
//	
//	T var;
//	/*std::string var;
//	int var;
//	double var;*/
//};
//
//template<typename T>
//VAR<T>::VAR(T var)
//{
//	this->var = var;
//}
//
//template<typename T>
//VAR<T>::VAR()
//{
//}
//
//template<typename T>
//VAR<T>::VAR(const VAR<T>&other)
//{
//	this->var = other.var;
//}
//
//template<typename T>
//void VAR<T>::show()
//{
//	cout << var << endl;
//}
//
//template<typename T>
//VAR<T> VAR<T>::operator+(const VAR & other) const
//{
//	VAR obj;
//	obj.var = this->var + other.var;
//	return obj;
//}
//
//template<typename T>
//VAR<T> VAR<T>::operator=(const VAR & other) const
//{
//	VAR<T> obj;
//	obj = this->var + other.var;
//	return obj;
//}
//
