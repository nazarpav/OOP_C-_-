#include "Group.h"
#include <iostream>
#include <string>
void GROUP::add_student(const student &arr)
{
	count++;
	student *tmp_arr = new student[count];
	for (int i = 0; i < count-1; i++)
	{
		tmp_arr[i] = STUDENT[i];
	}
	tmp_arr[count - 1] = arr;
	delete[]STUDENT;
	STUDENT = tmp_arr;
	AVG_ASSESSMENT_GROUP();
}
void GROUP::set_specialization(std::string new_specialization)
{
	specialization = new_specialization;
}
void GROUP::show()const
{
	std::cout << "AVG ASSESSMENT-> " << average_assessment << "\nQuantity student in group-> " << count << "\nSpecialization-> " << specialization << std::endl;
}
const GROUP GROUP::get_best_group(const GROUP &group)
{
	if (group.average_assessment > this->average_assessment)
	{
		return group;
	}
	else
	{
		return *this;
	}

}

GROUP::GROUP(student *&arr, int &size)
{
	STUDENT = new student[size];
	STUDENT = arr;
	count = size;
	AVG_ASSESSMENT_GROUP();
	this->specialization = "Empty!";
}
GROUP::GROUP()
{
	STUDENT = nullptr;
	count = 0;
}
GROUP::~GROUP()
{
}

