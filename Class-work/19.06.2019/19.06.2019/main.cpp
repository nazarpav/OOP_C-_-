#include "List.h"
#include <iostream>
using namespace std;

void main()
{
	List list;

	list.AddTail(44);
	list.AddTail(10);
	list.AddTail(12);
	list.AddTail(20);
	list.AddTail(223);
	list.AddTail(221);
	list.AddTail(220);
	list.AddTail(24);
	list.AddTail(54);
	list.ShowList();
	cout << "--------------------\n";

	/*list.Add(1, 3);
	list.ShowList();
	cout << "--------------------\n";

	list.Add(2, 9);
	list.ShowList();
	cout << "--------------------\n";*/

	list.Add(40, 29);
	list.ShowList();
	cout << "--------------------\n";
	/*list.delete_element_index(2);
	list.delete_element_index(2);
	list.delete_element_index(3);
*/
	//list.delete_element_index(1);
	//list.delete_element_index(2);
	//list.delete_element_index(1);
	cout << list.search_elem(23);
	list.sort_list();
	list.ShowList();
	cout << "--------------------\n";
	system("pause");
}