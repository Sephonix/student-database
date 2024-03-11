#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Enrollment.h"

enum StudentClassification { Freshman, Sophomore, Junior, Senior, Graduated };

class Student {
public:
	std::string FirstName;
	std::string LastName;
	StudentClassification Year;
	int UIN;
	bool CurrentlyEnrolled;
	int GraduationYear;
	float GPA;

	std::vector<Enrollment> Enrollments; //List of courses the student is enrolled in

	//constructors
	Student();
	Student(const std::string& firstName, const std::string& lastName, StudentClassification year,
		int uin, bool enrolled, int gradYear, float gpa) {
		FirstName = firstName;
		LastName = lastName;
		Year = year;
		UIN = uin;
		CurrentlyEnrolled = enrolled;
		GraduationYear = gradYear;
		GPA = gpa;
	}

	void PrintStudentInfo();
	void EnrollCourse(Course* course);
};

#endif // !STUDENT_
