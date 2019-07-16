#include<iostream>
#include<vector>
#include<string>
#include"my_time.h"
#include"Station.h"

using namespace std;

int main()
{
	Station obj;
	MyTime time_;
	time_.seconds = 12;
	time_.minutes = 12;
	time_.hours = 12;
	MyTime time2_;
	time2_.seconds = 22;
	time2_.minutes = 32;
	time2_.hours = 2;
	obj.Add_train(121,time_,"rovno");
	obj.Add_train(122,time2_,"kiev");
	obj.Add_train(312,time_,"lviv");
	obj.Add_train(132,time2_,"kharkiv");
	//obj.Red_time_departure(12, time2_);
	//obj.to_vector("data.txt");
	//obj.to_file("data.txt");
	obj.Show();
	obj.Sort_trains();
	cout << endl << endl;
	obj.Show();


	system("pause");
	return 0;
}