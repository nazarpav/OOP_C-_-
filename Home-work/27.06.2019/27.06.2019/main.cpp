#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List obj;

	obj.AddToBegin(1);
	obj.AddToBegin(2);
	obj.AddToBegin(3);
	obj.AddToBegin(4);
	obj.AddToBegin(5);
	obj.AddToBegin(6);
	obj.AddToBegin(7);
	obj.AddToBegin(8);
	obj.AddToBegin(9);
	obj.AddToBegin(10);
	obj.ShowList();
	cout << "\n";

	obj.add_elem_ind(55, 2);
	obj.add_elem_ind(55, 2);
	obj.del_elem_ind(2);
	obj.del_elem_ind(2);
	obj.del_elem_ind(0);


	//obj.DeleteHead();
	//obj.DeleteHead();
	//obj.Delete_tail();
	//obj.Delete_tail();
	obj.ShowList();



	system("pause");
	return 0;
}