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