//Створити клас SmartArray, який буде представляти масив з методами добавити / видалити елемент, переглянути масив.
//
//Клас буде містити в собі дані для представлення масиву :
//int * arr;
//int size;
//
//Та методи :
//Добавити елемент в масив(передається новий елемент)
//Видалити елемент(передається індекс елемента для видалення)
//Вивести масив на екран
//
//В класі повинні буди реалізовані наступні конструктори :
//Конструктор по замовчуванню - він буде встановлювати початкові дані(arr = nullptr, size = 0)
//Параметризовані конструктори :
//1 - Конструткор який приймає значення(int value) та кількість(int size) - створює масив з елементів кількості size та заповнює їх значенням value
//2 - Конструктор який приймає масив(int* array) та його розмір(int size) - створює масив розміром size та копіює всі дані з переданого масиву array
#include <iostream>
#include <string>
#include "smart_array.h"
using namespace std;

int main()
{
	SMART_CLASS obj(5,4);
	while (true)
	{
		//system("cls");
		int choise = 0;
		
		cout << "1- Show arr\n2- add elem\n3- del elem\n0- Exit\n";
		cin >> choise;
		switch (choise)
		{
		case 1:
			obj.show_arr();
			system("pause");
			break;
		case 2:
			obj.add_elem();
			break;
		case 3:
			obj.del_elem();
			break;
		case 0:
			return 0;
			break;
		default:
			cout << "Error!\n";
			break;
		}
	}
	return 0;
}