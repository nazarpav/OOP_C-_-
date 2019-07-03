#include<iostream>
#include"List.h"
#include"List_2.h"
#include"Queue.h"
#include"Stack.h"
#include"Queue_priority.h"
using namespace std;

int main()
{
	Dynamic_data_struct::List::List obj_list;
	obj_list.AddToBegin(11);
	obj_list.ShowList();
	Dynamic_data_struct::List2::List obj_list2;
	obj_list2.AddTail(14);
	obj_list2.ShowList();
	Dynamic_data_struct::Queue::Queue obj_queue(10);
	obj_queue.Add(12,100);
	obj_queue.Show();
	Dynamic_data_struct::Stack::Stack obj_stack(2);
	obj_stack.Stack_show();
	Dynamic_data_struct::Queue_priority::Queue_priority obj_priotity(223);
	obj_priotity.Show();
	system("pause");
	return 0;
}