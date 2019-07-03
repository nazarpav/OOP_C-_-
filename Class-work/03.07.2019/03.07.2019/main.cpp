#include<iostream>
#include"List.h"
#include"List_2.h"
#include"Queue.h"
using namespace std;

int main()
{
	List::List obj_list;
	obj_list.AddToBegin(11);
	obj_list.ShowList();
	List2::List obj_list2;
	obj_list2.AddTail(14);
	obj_list2.ShowList();
	Queue::Queue obj_queue(10);
	obj_queue.Add(12,100);
	obj_queue.Show();
	system("pause");
	return 0;
}