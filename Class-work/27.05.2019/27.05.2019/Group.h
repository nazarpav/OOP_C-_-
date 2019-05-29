#pragma once
#include <string>
#include "Student.h"

class GROUP
{
public:
	GROUP(student *&arr, int &size);
	GROUP();
	~GROUP();
	void add_student(const student & arr);

	void show() const;

	void set_specialization(std::string new_specialization);

	const GROUP get_best_group(const GROUP &group);
private:
	
	void AVG_ASSESSMENT_GROUP()
	{
		float tmp=0;
		for (unsigned short i = 0; i < count; i++)
		{
			tmp += STUDENT[i].get_assessment();
		}
		average_assessment=(tmp/count);
	}
	student *STUDENT;
	unsigned short count;
	float average_assessment;
	std::string specialization;
};

