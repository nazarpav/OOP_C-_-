#include "List.h"
#include <iostream>
using namespace std;

int main()
{
	List list;
	List list2;
	list.AddTail(4);
	//list.AddTail(10);
	//list.AddTail(30);
	//list.AddTail(30);
	//list.AddTail(30);
	//list.AddTail(30);
	list2.AddTail(44);
	//list2.AddTail(110);
	//list2.AddTail(310);
	//list2.AddTail(310);
	//list2.AddTail(310);
	//list2.AddTail(310);
//	List list2(list);
	list = list2;
	list2.ShowList();

	list.ShowList();
	cout << "--------------------\n";

	/*list.Add(1, 3);
	list.ShowList();
	cout << "--------------------\n";

	list.Add(2, 9);
	list.ShowList();
	cout << "--------------------\n";*/

	//list2.AddTail(40);
	//list2.ShowList();
	//cout << "--------------------\n";

	system("pause");
	return 0;
}