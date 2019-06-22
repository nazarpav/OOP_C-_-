#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List obj;

	obj.AddToEnd(1);
	obj.AddToEnd(2);
	obj.AddToEnd(3);
	obj.AddToEnd(4);
	obj.AddToEnd(5);
	obj.AddToEnd(6);
	obj.AddToEnd(7);
	obj.AddToEnd(2);
	obj.AddToEnd(8);
	obj.AddToEnd(9);
	obj.AddToEnd(10);
	obj.ShowList();
	cout << "\n";

	/*cout<<obj.search_element(44);
	cout<<obj.search_element(4);
	cout<<obj.search_element(4);*/
	cout << obj.Replace_element(2,55);
	cout << obj.Replace_element(2,55);
	cout << obj.Replace_element(2,55);

	//obj.DeleteHead();
	//obj.DeleteHead();
	//obj.Delete_tail();
	//obj.Delete_tail();
	obj.ShowList();



	system("pause");
	return 0;
}