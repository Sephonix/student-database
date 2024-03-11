#pragma once

#include <string>
#include "Student.h"
#include "Course.h"
#include "GradeBook.h"


class Enrollment {
public:
	Student* student;
	Course* course;
	std::vector<GradeBook> Grades;

	int UIN;
	std::string CourseID;
	std::string Semester;
	int Year;
	float Grade;
	bool Passed;
	bool InProgress;
	bool Completed;
	bool Dropped;
	bool Withdrawn;
	bool Enrolled;
	bool Registered;
	bool Waitlisted;
	bool Denied;
	bool Approved;
	bool Pending;
	bool Cancelled;
	bool Rejected;
	bool Failed;

	bool PassedWithA;
	bool PassedWithB;
	bool PassedWithC;
	bool PassedWithD;
	bool PassedWithP;
	bool PassedWithF;
	bool PassedWithCR;
};

