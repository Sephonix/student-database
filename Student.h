#pragma once

#include <iostream>
#include <string>
#include "Course.h"

enum StudentClassification { Freshman, Sophomore, Junior, Senior, Graduated };

class Student {
private:
	std::string FirstName;
	std::string LastName;
	StudentClassification Year;
	int UIN;
	bool CurrentlyEnrolled;
	int GraduationYear;
	float GPA;
	//std::vector<Enrollment> Enrollments; //List of courses the student is enrolled in

public:
	//Constructors
	Student() : Year(Freshman), UIN(0), CurrentlyEnrolled(false), GraduationYear(0), GPA(0.0f) {}
	Student(const std::string& firstName, const std::string& lastName, StudentClassification year,
			int uin, bool enrolled, int gradYear, float gpa) :
		FirstName(firstName),
		LastName(lastName),
		Year(year),
		UIN(uin),
		CurrentlyEnrolled(enrolled),
		GraduationYear(gradYear),
		GPA(gpa) {}	

	//Getters
	std::string GetFirstName() const { return FirstName; }
	std::string GetLastName() const { return LastName; }
	StudentClassification GetYear() const { return Year; }
	int GetUIN() const { return UIN; }
	bool GetEnrollment() const { return CurrentlyEnrolled; }
	int GetGraduationYear() const { return GraduationYear; }
	float getGPA() const { return GPA; }

	//Setters
	void SetFirstName(const std::string& firstName) { FirstName = firstName; }
	void SetLastName(const std::string& lastName) { LastName = lastName; }
	void SetYear(StudentClassification year) { Year = year; }
	void SetUIN(int uin) { UIN = uin; }
	void SetEnrollment(bool enrolled) { CurrentlyEnrolled = enrolled; }
	void SetGraduationYear(int gradYear) { GraduationYear = gradYear; }
	void SetGPA(float gpa) { GPA = gpa; }



	void PrintStudentInfo() const {
		std::cout << UIN << "\n";
		std::cout << "First Name: " << FirstName << "\n";
		std::cout << "Last Name: " << LastName << "\n";
		std::cout << "Year: " << Year << "\n";
		std::cout << "Enrolled: " << CurrentlyEnrolled << "\n";
		std::cout << "Graduation Year: " << GraduationYear << "\n";
		std::cout << "GPA: " << GPA << "\n";
	}
	void EnrollCourse(Course* course);
};