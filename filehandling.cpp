#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

// Function to add student information to file
void addStudentInfo() {
    ofstream outFile("student_info.txt", ios::app);
    if (!outFile) {
        cerr << "Error: Unable to open file." << endl;
        exit(1);
    }

    Student newStudent;
    cout << "Enter Roll Number: ";
    cin >> newStudent.rollNumber;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newStudent.name);
    cout << "Enter Division: ";
    getline(cin, newStudent.division);
    cout << "Enter Address: ";
    getline(cin, newStudent.address);

    outFile << newStudent.rollNumber << ' '
            << newStudent.name << ' '
            << newStudent.division << ' '
            << newStudent.address << endl;

    outFile.close();
}

// Function to delete student information from file
void deleteStudentInfo(int rollNumber) {
    ifstream inFile("student_info.txt");
    ofstream tempFile("temp.txt");
    if (!inFile || !tempFile) {
        cerr << "Error: Unable to open file." << endl;
        exit(1);
    }

    Student tempStudent;
    bool found = false;

    while (inFile >> tempStudent.rollNumber >> tempStudent.name >> tempStudent.division >> tempStudent.address) {
        if (tempStudent.rollNumber != rollNumber) {
            tempFile << tempStudent.rollNumber << ' '
                     << tempStudent.name << ' '
                     << tempStudent.division << ' '
                     << tempStudent.address << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove("student_info.txt");
    rename("temp.txt", "student_info.txt");

    if (!found) {
        cout << "Student with Roll Number " << rollNumber << " not found." << endl;
    } else {
        cout << "Student with Roll Number " << rollNumber << " deleted successfully." << endl;
    }
}

// Function to display student information
void displayStudentInfo(int rollNumber) {
    ifstream inFile("student_info.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file." << endl;
        exit(1);
    }

    Student tempStudent;
    bool found = false;

    while (inFile >> tempStudent.rollNumber >> tempStudent.name >> tempStudent.division >> tempStudent.address) {
        if (tempStudent.rollNumber == rollNumber) {
            cout << "Roll Number: " << tempStudent.rollNumber << endl;
            cout << "Name: " << tempStudent.name << endl;
            cout << "Division: " << tempStudent.division << endl;
            cout << "Address: " << tempStudent.address << endl;
            found = true;
            break;
        }
    }

    inFile.close();

    if (!found) {
        cout << "Student with Roll Number " << rollNumber << " not found." << endl;
    }
}

int main() {
    int choice;
    int rollNumber;

    do {
        cout << "\n1. Add Student Information\n"
                "2. Delete Student Information\n"
                "3. Display Student Information\n"
                "4. Exit\n"
                "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudentInfo();
                break;
            case 2:
                cout << "Enter Roll Number of student to delete: ";
                cin >> rollNumber;
                deleteStudentInfo(rollNumber);
                break;
            case 3:
                cout << "Enter Roll Number of student to display: ";
                cin >> rollNumber;
                displayStudentInfo(rollNumber);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
