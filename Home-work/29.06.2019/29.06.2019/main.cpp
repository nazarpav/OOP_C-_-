#include "List.h"
#include <iostream>
using namespace std;

int main()
{
	List list;

	list.AddTail(44);
	list.AddTail(10);
	List list2(list);
	list.AddTail(12);
	list.AddTail(20);
	list.AddTail(223);
	list.AddTail(221);
	list.AddTail(220);
	list.AddTail(24);
	list.AddTail(54);
	list.AddTail(54);
	list.ShowList();
	cout << "--------------------\n";
	//list2 = move(list);
	list=list.sort_list(list.Descending);
	list.ShowList();
	cout << "--------------------\n";
	system("pause");
	return 0;
}