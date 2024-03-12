#include <iostream>
#include <string>
#include <limits>

#include "Student.h"
#include "StudentDatabase.h"
#include "Course.h"
#include "CourseDatabase.h"


void ClearInputStream();
void PrintStudentMenu(StudentDatabase studentDatabase);
void PrintCourseMenu(CourseDatabase courseDatabase);
void ClearConsole();


using namespace std;
int main() {
    //Create student database
    int ProgramState = -1;
    StudentDatabase sdb;
    CourseDatabase cdb;

    //TODO: Load Databases from CSV

    //Begin the main program loop
    while (ProgramState != 0) {
        cout << "----- Main Menu -----\n";
        cout << "(1) Edit Student Database\n";
        cout << "(2) Edit Course Database\n";
        cout << "(0) Quit\n";
        cout << "Enter your choice: ";

        if (!(cin >> ProgramState)) {
            ClearInputStream();
            cout << "Please enter a valid integer.\n";
            continue;
        }

        switch (ProgramState) {
        case 0:
            cout << "Goodbye!\n";
            break;
        case 1:
            ClearConsole();
            PrintStudentMenu(sdb);
            break;
        case 2:
            ClearConsole();
            PrintCourseMenu(cdb);
            break;
        default:
            cout << "Invalid Choice\n";
            break;
        }
    }
    return 0;
}

//Clear error flags and discards the input buffer
void ClearInputStream() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void PrintStudentMenu(StudentDatabase studentDatabase) {
    int choice = -1;
    while (choice != 0) {
        cout << "------ Student Database ------\n";
        cout << "(0) <--- Go back\n";
        cout << "(1) Create a Student\n";
        cout << "(2) Remove a Student\n";
        cout << "(3) List Students\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            ClearInputStream();
            cout << "Please enter a valid integer.\n";
            continue; //restart the loop
        }

        switch (choice) {
        case 0:
            ClearConsole();
            break;
        case 1:
            ClearConsole();
            studentDatabase.CreateStudent();

            //TODO: Figure out a better way to handle writing to CSV
            studentDatabase.WriteToCSV("student_database.csv");
            break;
        case 2:
            ClearConsole();
            studentDatabase.RemoveStudent();
            break;
        case 3:
            ClearConsole();
            studentDatabase.PrintStudents();
            break;
        default:
            cout << "Invalid choice\n";
        }
    }
}

void PrintCourseMenu(CourseDatabase courseDatabase) {

    int choice = -1;
    while (choice != 0) {
        cout << "------ Course Database ------\n";
        cout << "(0) <--- Go back\n";
        cout << "(1) Create a Course\n";
        cout << "(2) Remove a Course\n";
        cout << "(3) List Courses\n";
        cout << "(4) Enroll Student     (WIP)\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            ClearInputStream();
            cout << "Please enter a valid integer.\n";
            continue; //restart the loop
        }

        switch (choice) {
        case 0:
            ClearConsole();
            break;
        case 1:
            ClearConsole();
            courseDatabase.CreateCourse();

            //TODO: Figure out a better way to handle writing to CSV
            courseDatabase.WriteToCSV("course_database.csv");
            break;
        case 2:
            ClearConsole();
            courseDatabase.RemoveCourse();
            break;
        case 3:
            ClearConsole();
            courseDatabase.PrintCourses();
            break;
        case 4:
            ClearConsole();
			cout << "Enrolling a student\n";
            //TODO: Figure out how to enroll students in a course
			break;
        default:
            cout << "Invalid choice\n";
        }
    }
}

void ClearConsole() {
    system("cls");
}