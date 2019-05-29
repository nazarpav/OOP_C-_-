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
	this->specialization = new_specialization;
}
void GROUP::set_name(std::string new_name)
{
	this->name = new_name;
}

void GROUP::Students_who_have_a_higher_assessment(int assessment)
{
	for (int i = 0; i < count; i++)
	{
		if (STUDENT[i].get_assessment() >= assessment)
		{
			cout << endl;
			STUDENT[i].show_student("short");
			cout << endl;
		}
	}
}
void GROUP::AVG_ASSESSMENT_GROUP()
{
	float tmp = 0;
	for (unsigned short i = 0; i < count; i++)
	{
		tmp += STUDENT[i].get_assessment();
	}
	average_assessment = (tmp / count);
}
void GROUP::sort_assessment()
{
	student tmp;
	for (int i = 1; i < count; ++i)
	{
		for (int j = 0; j < count - i; j++)
		{
			if (STUDENT[j].get_assessment() < STUDENT[j + 1].get_assessment())
			{
				tmp = STUDENT[j];
				STUDENT[j] = STUDENT[j + 1];
				STUDENT[j + 1] = tmp;
			}
		}
	}
}
void GROUP::sort_quantity_skips()
{
	student tmp;
	for (int i = 1; i < count; ++i)
	{
		for (int j = 0; j < count - i; j++)
		{
			if (STUDENT[j].get_quantity_skips() < STUDENT[j + 1].get_quantity_skips())
			{
				tmp = STUDENT[j];
				STUDENT[j] = STUDENT[j + 1];
				STUDENT[j + 1] = tmp;
			}
		}
	}
}
void GROUP::show()const
{
	std::cout << "Name-> "<<name<<"\nAVG ASSESSMENT-> " << average_assessment << "\nQuantity student in group-> " << count << "\nSpecialization-> " << specialization << std::endl;
	cout << endl;
	for (int i = 0; i < count; i++)
	{
		STUDENT[i].show_student("short");
		cout << endl;
	}
}
GROUP GROUP::get_best_group(GROUP group_)
{
	if (group_.average_assessment > this->average_assessment)
	{
		return group_;
	}
	else
	{
		return *this;
	}

}

GROUP::GROUP(student *&arr, int &size):GROUP()
{
	this->STUDENT = new student[size];
	this->STUDENT = arr;
	this->count = size;
	this->AVG_ASSESSMENT_GROUP();
	this->specialization = "Empty!";
	this->name = "Empty!";
}

GROUP::GROUP(const GROUP &arr_)
{
	this->count = arr_.count;
	this->specialization = arr_.specialization;
	this->average_assessment = arr_.average_assessment;
	this->name = arr_.name;
	this->STUDENT = new student[count];
	for (int i = 0; i < arr_.count; i++)
	{
		this->STUDENT[i].set_name(arr_.STUDENT[i].get_name());
		this->STUDENT[i].set_surname(arr_.STUDENT[i].get_surname());
		this->STUDENT[i].set_age(arr_.STUDENT[i].get_age());
		this->STUDENT[i].set_assessment(arr_.STUDENT[i].get_assessment());
		this->STUDENT[i].set_quantity_skips(arr_.STUDENT[i].get_quantity_skips());
	}
}
GROUP::GROUP()
{
	this->STUDENT = nullptr;
	this->count = 0;
	this->specialization = "Empty!";
	this->average_assessment = 0;
	this->name = "Empty!";
}
GROUP::~GROUP()
{
	if (STUDENT != NULL||STUDENT!=nullptr)
	{
		delete[]STUDENT;
	}
}

