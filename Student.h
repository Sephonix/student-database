#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

enum StudentClassification { Freshman, Sophomore, Junior, Senior, Graduated };
enum CourseSubject { MATH, CHEM, PHYS, HIST, ENGL, ENGN, ECE, CS, POLS };

class Student {
public:
	std::string FirstName;
	std::string LastName;
	StudentClassification Year;

	int UIN;
	bool CurrentlyEnrolled;
	int GraduationYear;

	float GPA;

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
	void RegisterClass();
	void DeregisterClass();
};


class Course {
public:
	CourseSubject Subject;
	int ID;
	std::string Name;
};

void LoadStudentInfo();
void SaveStudentInfo();

void CreateCourse(CourseSubject courseSubject, int courseID, std::string courseName);
void DeleteCourse(CourseSubject courseSubject, int courseID);

#endif // !STUDENT_
