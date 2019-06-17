#include <iostream>
#include"List.h"
using namespace std;

int main()
{
	List obj;
	obj.AddToBegin(1);
	obj.AddToBegin(2);
	obj.AddToBegin(3);
	obj.AddToBegin(4);
	obj.ShowList();

	obj.DeleteAll();
	obj.DeleteFromTail();
	obj.DeleteFromTail();
	obj.DeleteFromTail();
	obj.DeleteFromTail();
	//obj.DeleteFromTail();
	obj.ShowList();

	system("pause");
	return 0;
}