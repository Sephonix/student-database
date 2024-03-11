#include <iostream>
#include "Course.h"
#include "Student.h"
#include "Enrollment.h"


void Course::PrintCourses() {
	std::cout << "------ Courses ------\n";
	for (int i = 0; i < courses.size(); i++) {
		std::cout << courses[i].Subject << " " << courses[i].ID << " " << courses[i].Semester << " " << courses[i].Year << "\n";
	}
}

void Course::CreateCourse() {
	std::string subject;
	std::string id;
	std::string semester;
	int year;
	Course tempCourse("", "", "", 0); //Create a dummy course object
	std::cout << "------ Create a Course ------\n";

	std::cout << "Enter the subject: ";
	std::cin >> subject;
	tempCourse.Subject = subject;

	std::cout << "Enter the course ID: ";
	std::cin >> id;
	tempCourse.ID = id;

	std::cout << "Enter the semester: ";
	std::cin >> semester;
	tempCourse.Semester = semester;

	std::cout << "Enter the year: ";
	std::cin >> year;
	tempCourse.Year = year;


	courses.push_back(tempCourse); //Add the course to the database
	std::cout << "Course " << tempCourse.Subject << " " << tempCourse.ID << " was added to the database.\n";
}

void Course::AddStudent(Student* student) {
	Enrollment newEnrollment;
	newEnrollment.student = student;
	newEnrollment.course = this; //Pointer to the current course object
	newEnrollment.UIN = student->UIN;
	newEnrollment.CourseID = ID;
	newEnrollment.Semester = Semester;
	newEnrollment.Year = Year;
	student->Enrollments.push_back(newEnrollment);
	EnrolledStudents.push_back(newEnrollment);
}