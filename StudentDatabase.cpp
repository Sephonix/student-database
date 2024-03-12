#include "StudentDatabase.h"
#include <iostream>
#include <fstream>
#include <sstream>>

void StudentDatabase::AddStudent(const Student& student) {
	students.push_back(student);
	std::cout << student.GetFirstName() << " " << student.GetLastName() << " was added to the database.\n";
}

void StudentDatabase::RemoveStudent() {
	const size_t studentsSize = students.size();
	int InputUIN;

	std::cout << "------ Remove a Student ------\n";
	std::cout << "Enter the Student's UIN: ";
	std::cin >> InputUIN;
	//i've got no fucking clue what this line of code does
	students.erase(std::remove_if(students.begin(), students.end(), [InputUIN](const Student& student) {return student.GetUIN() == InputUIN; }), students.end());
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
	for (auto& student : students) {
		if (student.GetUIN() == UIN) {
			return &student;
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
		std::cout << "Student Name: " << student.GetUIN() << " " << student.GetLastName() << ", UIN: " << student.GetUIN() << std::endl;
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
	tempStudent.SetFirstName(stdFirstName);

	std::cout << "Last Name: ";
	std::cin >> stdLastName;
	tempStudent.SetLastName(stdLastName);
	std::cout << "Classification (Freshman = 1, Sophomore = 2, Junior = 3, Senior = 4, Graduated = 0): ";

	std::cin >> classificationInput;
	stdClassificationEnum = static_cast<StudentClassification>(classificationInput);
	tempStudent.SetYear(stdClassificationEnum);
	std::cout << "UIN: ";
	std::cin >> uin;
	tempStudent.SetUIN(uin);

	std::cout << "Currently Enrolled? (No = 0, Yes = 1): ";
	std::cin >> enrolled;
	tempStudent.SetEnrollment(enrolled);

	std::cout << "Graduation Year: ";
	std::cin >> graduationYear;
	tempStudent.SetGraduationYear(graduationYear);

	std::cout << "GPA: ";
	std::cin >> gpa;
	tempStudent.SetGPA(gpa);

	this->AddStudent(tempStudent); //Add the student to the database
}

void StudentDatabase::WriteToCSV(const std::string& fileName) const{
	std::ofstream file(fileName);

	//check if the file is open
	if (!file.is_open()) {
		std::cerr << "Error opening file.\n";
		return;
	}
	//write the data to the file
	//format: FirstName,LastName,Year,UIN,Enrollment,GraduationYear,GPA

	for (const auto& student : students) {
		file << student.GetFirstName() << ","
		<< student.GetLastName() << ","
		<< student.GetYear() << ","
		<< student.GetUIN() << ","
		<< student.GetEnrollment() << ","
		<< student.GetGraduationYear() << ","
		<< student.getGPA() << "\n";
	}
	file.close();
}
void StudentDatabase::LoadFromCSV(const std::string& fileName) {
	std::ifstream file(fileName);
	std::string line;
	std::string firstName, lastName;
	StudentClassification year;
	int uin, gradYear;
	bool enrolled;
	float gpa;

	//check if the file is open
	if (!file.is_open())
	{
				std::cerr << "Error opening file.\n";
		return;
	}
	//read the data from the file
	//format: FirstName,LastName,Year,UIN,Enrollment,GraduationYear,GPA
	while (std::getline(file, line)) {
		std::istringstream linestream(line);
		std::getline(linestream, firstName, ',');
		std::getline(linestream, lastName, ',');
		std::getline(linestream, line, ',');
		year = static_cast<StudentClassification>(std::stoi(line));
		std::getline(linestream, line, ',');
		uin = std::stoi(line);
		std::getline(linestream, line, ',');
		enrolled = std::stoi(line);
		std::getline(linestream, line, ',');
		gradYear = std::stoi(line);
		std::getline(linestream, line, ',');
		gpa = std::stof(line);

		Student tempStudent(firstName, lastName, year, uin, enrolled, gradYear, gpa);
		this->AddStudent(tempStudent);
	}
	file.close();
}