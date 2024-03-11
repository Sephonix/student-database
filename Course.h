#pragma once
#include <string>
#include <vector>

class Course {
private:
	std::vector<Course> courses;

public:
	std::vector<Enrollment> EnrolledStudents;
	std::string Subject;
	std::string ID;
	std::string Semester;
	int Year;
	Course();
	Course(std::string subject, std::string id, std::string semester, int year) {
		Subject = subject;
		ID = id;
		Semester = semester;
		Year = year;
	}
	void CreateCourse();
	void RemoveCourse();
	void PrintCourses();
	void PrintCourseInfo();
	void AddStudent(Student* student);
};

