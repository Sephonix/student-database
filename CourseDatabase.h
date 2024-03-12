#pragma once

#include "Course.h"

class CourseDatabase {
private:
	std::vector<Course> courses;
public:
	void CreateCourse();
	void RemoveCourse();
	void PrintCourses() const;
	void WriteToCSV(const std::string& fileName) const;
};

