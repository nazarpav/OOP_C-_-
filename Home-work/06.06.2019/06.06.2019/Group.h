#pragma once
#include <string>
#include "Student.h"

class GROUP
{
public:
	GROUP(student *&arr, int &size);
	GROUP(const GROUP & arr_);
	GROUP();
	~GROUP();
	void add_student(const student & arr);

	void show() const;

	void set_specialization(std::string new_specialization);

	void set_name(std::string new_name);

	void Students_who_have_a_higher_assessment(int assessment);

	 GROUP get_best_group( GROUP group);
	
	void sort_assessment();
	void sort_quantity_skips();
private:
	
	void AVG_ASSESSMENT_GROUP();
	student *STUDENT;
	unsigned short count;
	float average_assessment;
	std::string specialization;
	std::string name;
};

