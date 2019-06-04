#include<iostream>
#include"time.h"
using namespace std;
TIME operator++(TIME&other)
{
	other.time++;
	other.to_time(other.time);
	return other;
}
TIME operator--(TIME&other)
{
	other.time--;
	other.to_time(other.time);
	return other.time;
}
bool operator==(const TIME & obj1,const TIME & obj2)
{
	return obj1.time == obj2.time;
}
bool operator >(TIME & obj1,TIME & obj2)
{
	return obj1.get_time() > obj2.get_time();
}
bool operator <(TIME & obj1, TIME & obj2)
{
	return obj1.get_time() < obj2.get_time();
}
TIME operator--(TIME&other2,int tmp)
{
	TIME tmp_(other2);
	other2.set_time(1,TIME::SUB);
	other2.to_time(other2.get_time());
	return tmp_;
}
int main()
{

	TIME obj(111);
	TIME obj2(112);
	obj.show();
	if (obj2 == obj)
	{
		cout << "==" << endl;
	}
	else
	{
		cout << "!=" << endl;
	}
	obj.show();
	obj--;
	//obj(1,2,3);
	obj.show();
	system("pause");
	return 0;
}