#pragma once

#ifndef STUDENTDATABASE_H
#define STUDENTDATABASE_H


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
	auto SizeStudents();
};

#endif // !STUDENTDATABASE_H