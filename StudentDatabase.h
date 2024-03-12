#pragma once

#include <vector>
#include "Student.h"

class StudentDatabase {
private:
	std::vector<Student> students;

public:
	void CreateStudent();
	void AddStudent(const Student& student);
	void RemoveStudent();
	void PrintStudents();
	Student GetStudent(int index);
	Student* GetStudentByUIN(int UIN);
	auto SizeStudents();

	void WriteToCSV(const std::string& fileName) const;
	void LoadFromCSV(const std::string& fileName);
};