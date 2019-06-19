#include<iostream>
#include"queue.h"
using namespace std;

int main()
{
	queue<int> obj;
	obj.add(1);
	obj.add(2);
	obj.add(3);
	obj.show();

	system("pause");
	return 0;
}