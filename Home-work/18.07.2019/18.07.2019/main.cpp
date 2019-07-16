#include<iostream>
#include<string>
#include <fstream>
#include"List.h"
using namespace std;

int main()
{
	ofstream ofile("data.txt", ios_base::out | ios_base::app);
	//ofile.close();
//	ifstream ifile("data.txt", ios_base::in | ios_base::app);
	List obj;
//	ifile >> obj;
	obj.AddTail("122","qwe","311","rr5","345e");
	obj.AddTail("s12","qswe","31s1","rrs5","34sad5e");
	obj.AddTail("1adad2","qadsadwe","3adsad11","rradsa5","34asd5e");
	obj.AddTail("12","122222","12222","1222","122");
	obj.ShowList();
	/*string firm_name, string owner, string tel_num, string addres, string firm_activity*/
	cout<<obj.search_firm_name("12");
	cout<<obj.search_addres("1222");
	cout<<obj.search_firm_activity("122");
	cout<<obj.search_owner("1222322");
	cout<<obj.search_tel_num("12222");
//	ofile << obj;
	system("pause");
	return 0;
}