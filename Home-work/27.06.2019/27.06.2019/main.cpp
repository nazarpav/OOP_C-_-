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
	obj.ShowList();
	cout << "\n";
	obj.add_elem_ind(55, 2);
	obj.add_elem_ind(55, 1);
	//obj.add_elem_ind(55, 3);
	//obj.Delete_tail();
	//obj.Delete_tail();
	obj.ShowList();



	system("pause");
	return 0;
}