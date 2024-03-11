#include "Student.h"
#include <string>
#include <iostream>



void Student::PrintStudentInfo() {
	std::cout << Student::UIN << "\n";
	std::cout << "First Name: " << Student::FirstName << "\n";
	std::cout << "Last Name: " << Student::LastName << "\n";
	std::cout << "Year: " << Student::Year << "\n";
	std::cout << "Enrolled: " << Student::CurrentlyEnrolled << "\n";
	std::cout << "Graduation Year: " << Student::GraduationYear << "\n";
	std::cout << "GPA: " << Student::GPA << std::endl;
}

void Student::EnrollCourse(Course* course) {
	//Prompt the user for the course ID, semester, and year
	std::string courseID;
	std::string semester;
	int year;
	std::cout << "Enter the course ID: ";
	std::cin >> courseID;
	std::cout << "Enter the semester: ";
	std::cin >> semester;
	std::cout << "Enter the year: ";
	std::cin >> year;

	//Create a new enrollment and add it to the student's list of enrollments
	Enrollment newEnrollment;
	newEnrollment.student = this; //pointer to the current student object
	newEnrollment.course = course;
	newEnrollment.UIN = Student::UIN;
	newEnrollment.CourseID = courseID;
	newEnrollment.Semester = semester;
	newEnrollment.Year = year;
	Student::Enrollments.push_back(newEnrollment); 
	course->AddStudent(this);
}