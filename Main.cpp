#include <iostream>
#include <string>
#include <limits>

#include "Student.h"
#include "StudentDatabase.h"
#include "Course.h"


void ClearInputStream();
void PrintStudentMenu(StudentDatabase db);
void PrintCourseMenu(StudentDatabase db);
void ClearConsole();


using namespace std;
int main() {
    //Create student database
    int ProgramState = -1;
    StudentDatabase db;


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
            PrintStudentMenu(db);
            break;
        case 2:
            ClearConsole();
            PrintCourseMenu(db);
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

void PrintStudentMenu(StudentDatabase db) {
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
            db.CreateStudent();
            break;
        case 2:
            ClearConsole();
            db.RemoveStudent();
            break;
        case 3:
            ClearConsole();
            db.PrintStudents();
            break;
        default:
            cout << "Invalid choice\n";
        }
    }
}
void PrintCourseMenu(StudentDatabase db) {
    int choice = -1;
    while (choice != 0) {
        ClearConsole();
        cout << "------ Course Database ------\n";
        cout << "(0) <--- Go back\n";
        cout << "(1) Create a Course    (WIP)\n";
        cout << "(2) Remove a Course    (WIP)\n";
        cout << "(3) List Courses       (WIP)\n";
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
            cout << "Creating a course\n";
            //TODO: Implement course creation
            //course.CreateCourse();
            break;
        case 2:
            cout << "Removing a course\n";
            break;
        case 3:
            ClearConsole();
            break;
        case 4:
			cout << "Enrolling a student\n";         
			break;

        default:
            cout << "Invalid choice\n";
        }
    }
}

void ClearConsole() {
    system("cls");
}