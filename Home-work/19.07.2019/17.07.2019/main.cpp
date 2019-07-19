#include<iostream>
#include"Unique_ptr.h"
#include"Shared_ptr.h"
#include<string>
using namespace std;



int main()
{
	Unique_ptr<int> obj_u = (new int);
	int * data = new int;
	*data = 78;
	obj_u.Reset(data);
	cout<<*obj_u.Get()<<endl;
	cout << obj_u;
	//cin >> obj;
	//cout << *obj.Get();
	Shared_ptr<int> obj_s = (new int);
	*data = 879;
	obj_s.Reset(data);
	cout << *obj_s.Get() << endl;
	cout << obj_s<<endl;
	Shared_ptr<int>obj_s2 = obj_s;
	cout<<obj_s.Get()<<" "<<
	obj_s2.Get()<<endl;

	system("pause");
	return 0;
}