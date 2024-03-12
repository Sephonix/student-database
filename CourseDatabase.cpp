#include <iostream>

#include "CourseDatabase.h"
#include "StudentDatabase.h"
#include <fstream>

void CourseDatabase::PrintCourses() const{
	if (courses.empty()) {
		std::cout << "No courses in the database.\n";
		return;
	}

	for (const auto& course : courses) {
		std::cout << "Course: " << course.GetSemester() << " " << course.GetYear()<< " " << course.GetSubject() << " " << course.GetID() << std::endl;
	}
}

void CourseDatabase::RemoveCourse() {
	const size_t coursesSize = courses.size();
	std::string InputSubject;
	std::string InputID;
	std::string InputSemester;
	int InputYear;

	std::cout << "------ Remove a Course ------\n";
	std::cout << "Enter the Course Subject: ";
	std::cin >> InputSubject;
	std::cout << "Enter the Course ID: ";
	std::cin >> InputID;
	std::cout << "Enter the Course Semester: ";
	std::cin >> InputSemester;
	std::cout << "Enter the Course Year: ";
	std::cin >> InputYear;

	//i've got no fucking clue what this line of code does
	courses.erase(std::remove_if(courses.begin(), courses.end(),
		[InputSubject, InputID, InputSemester, InputYear](const Course& course) {
			return course.GetSubject() == InputSubject &&
				course.GetID() == InputID &&
				course.GetSemester() == InputSemester &&
				course.GetYear() == InputYear;
		}), courses.end());

	if (courses.size() < coursesSize)
		std::cout << "Course removed successfully.\n";
	else
		std::cout << "Course was not found.\n";
}

void CourseDatabase::CreateCourse() {
	std::string subject;
	std::string id;
	std::string semester;
	int year;
	Course tempCourse("", "", "", 0); //Create a dummy course object
	std::cout << "------ Create a Course ------\n";

	std::cout << "Enter the subject: ";
	std::cin >> subject;
	tempCourse.SetSubject(subject);

	std::cout << "Enter the course ID: ";
	std::cin >> id;
	tempCourse.SetID(id);

	std::cout << "Enter the semester: ";
	std::cin >> semester;
	tempCourse.SetSemester(semester);

	std::cout << "Enter the year: ";
	std::cin >> year;
	tempCourse.SetYear(year);

	courses.push_back(tempCourse); //Add the course to the database
	std::cout << "Course " << tempCourse.GetSubject() << " " << tempCourse.GetID() << " was added to the database.\n";
}

void CourseDatabase::WriteToCSV(const std::string& fileName) const {
	std::ofstream file(fileName);

	//check if the file is open
	if (!file.is_open()) {
		std::cerr << "Error opening file.\n";
		return;
	}
	//write the data to the file
	//format: Subject,ID,Semester,Year

	for (const auto& course : courses) {
		file << course.GetSubject() << ","
			<< course.GetID() << ","
			<< course.GetSemester() << ","
			<< course.GetYear() << "\n";
	}
	file.close();
}
