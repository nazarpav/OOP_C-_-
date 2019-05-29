#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
#include "Group.h"
using namespace std;

int main()
{
	srand(unsigned(time(NULL)));
	student student1("bill", "jhfg", 12, 2, 23);
	student student3("mark", "asdf", 2, 22,24);
	student student4("anne", "dfgh", 9, 32, 64);
	student student5("jon", "ytui", 42, 2, 33);
	student student6("ron", "lfjy", 23, 12, 34);
	student student7("louise", "gats", 11, 13, 73);
	student student8("roon", "lfjy", 13, 12, 13);
	student student9("loouise", "gats", 9, 23, 43);

	int size_ = 8;
	student *student2=new student[size_];
	for (int i = 0; i < size_; i++)
	{
		student2[i].set_age(rand() % 50 + 1);
		student2[i].set_assessment(rand() % 30 + 1);
		student2[i].set_name(to_string(rand() % 10000 + 100));
		student2[i].set_surname(to_string(rand() % 10000 + 100));
		student2[i].set_quantity_skips(rand() % 10 + 1);
	}
	GROUP group;
	for (int i = 0; i < size_; i++)
	{
		cout << student2[i].get_age()<<endl;
		cout << student2[i].get_name() << endl;
	}
	GROUP group2(student2,size_);
	///////////////////////////////////////////////////////////////////////////////

	cout << student1.get_successful_student(student3).get_assessment()<<endl;

	group.add_student(student1);
	group.add_student(student3);
	group.add_student(student4);
	student1.show_student();//show

	group.set_specialization("math");
	group.set_name("group1");
	group2.set_name("group2");
	group2.set_specialization("physics");

	group.show();				//sort v
	group.sort_assessment();
	group.show();
	group.sort_quantity_skips();
	group.show();

	group.Students_who_have_a_higher_assessment(5);

	group.get_best_group(group2).show();//the best group

	cout << "==========================>\n";

	group2.Students_who_have_a_higher_assessment(5);

	group2.show();
	group2.sort_assessment();//sort v
	group2.show();
	group2.sort_quantity_skips();
	group2.show();
	system("pause");
	return 0;
}
