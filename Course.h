#pragma once

#include <string>
#include <vector>

class Course {
private:
	std::string Subject;
	std::string ID;
	std::string Semester;
	int Year;

public:
	//Constructors
	Course() : Year(0) {}
	Course(const std::string& subject,const std::string& id,const std::string& semester, int year) :
		Subject(subject),
		ID(id),
		Semester(semester),
		Year(year) {}


	//Getters
	std::string GetSubject() const { return Subject; }
	std::string GetID() const { return ID; }
	std::string GetSemester() const { return Semester; }
	int GetYear() const { return Year; }

	//Setters
	void SetSubject(const std::string& subject) { Subject = subject; }
	void SetID(const std::string& id) { ID = id; }
	void SetSemester(const std::string& semester) { Semester = semester; }
	void SetYear(int year) { Year = year; }


	void PrintCourseInfo() const {
		std::cout << "Course: " << Subject << " " << ID << " " << Semester << " " << Year << "\n";
	}
};