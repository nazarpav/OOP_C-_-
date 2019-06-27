#include "List.h"
#include <iostream>
using namespace std;

int main()
{
	List list;
	List list2;
	list.AddTail(4);
	list.AddTail(6);
	list.AddTail(7);
	list.AddTail(8);

	list2.AddTail(44);
	list2.AddTail(44);
	list2.AddTail(44);


	list2.ShowList();
	cout << endl;
	list.ShowList();

	cout << endl;
	list= (-list);
	list.ShowList();
	cout << "--------------------\n";



	system("pause");
	return 0;
}