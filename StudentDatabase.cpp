#include "StudentDatabase.h"
#include <iostream>


void StudentDatabase::AddStudent(const Student& student) {
	students.push_back(student);
	std::cout << student.FirstName << " " << student.LastName << " was added to the database.\n";
}

void StudentDatabase::RemoveStudent() {
	auto studentsSize = students.size();
	int InputUIN;

	std::cout << "------ Remove a Student ------\n";
	std::cout << "Enter the Student's UIN: ";
	std::cin >> InputUIN;
	//i've got no fucking clue what this line of code does
	students.erase(std::remove_if(students.begin(), students.end(), [InputUIN](const Student& student) {return student.UIN == InputUIN; }), students.end());
	if (students.size() < studentsSize)
		std::cout << "Student removed successfully.\n";
	else
		std::cout << "Student was not found.\n";
}


auto StudentDatabase::SizeStudents() {
	return students.size();
	//why did i make a dedicated function for this? 
	//just felt like it idk
}

Student StudentDatabase::GetStudent(int index) {
	if (index < 0 || index >= students.size()) {
		throw std::out_of_range("Index is out of range.");
	}
	return students[index];
}

Student* StudentDatabase::GetStudentByUIN(int UIN) {
	for (int i = 0; i < students.size(); ++i) {
		if (students[i].UIN == UIN) {
			return &students[i];
		}
	}
	return nullptr;
}

void StudentDatabase::PrintStudents() {
	if (students.empty()) {
		std::cout << "No students in the database.\n";
		return;
	}

	for (const auto& student : students) {
		std::cout << "Student Name: " << student.FirstName << " " << student.LastName << ", UIN: " << student.UIN << std::endl;
	}
}


void StudentDatabase::CreateStudent() {
	std::string stdFirstName, stdLastName;
	StudentClassification stdClassificationEnum = Freshman;
	int uin, graduationYear, classificationInput;
	float gpa;
	bool enrolled;
	Student tempStudent("", "", Freshman, 0, false, 0, 0.0); //Create a dummy student object
	std::cout << "------ Add a Student ------\n";

	std::cout << "First Name: ";
	std::cin >> stdFirstName;
	tempStudent.FirstName = stdFirstName;

	std::cout << "Last Name: ";
	std::cin >> stdLastName;
	tempStudent.LastName = stdLastName;

	std::cout << "Classification (Freshman = 1, Sophomore = 2, Junior = 3, Senior = 4, Graduated = 0): ";

	std::cin >> classificationInput;
	stdClassificationEnum = static_cast<StudentClassification>(classificationInput);
	tempStudent.Year = stdClassificationEnum;

	std::cout << "UIN: ";
	std::cin >> uin;
	tempStudent.UIN = uin;

	std::cout << "Currently Enrolled? (No = 0, Yes = 1): ";
	std::cin >> enrolled;
	tempStudent.CurrentlyEnrolled = enrolled;

	std::cout << "Graduation Year: ";
	std::cin >> graduationYear;
	tempStudent.GraduationYear = graduationYear;

	std::cout << "GPA: ";
	std::cin >> gpa;
	tempStudent.GPA = gpa;

	this->AddStudent(tempStudent); //Add the student to the database
}