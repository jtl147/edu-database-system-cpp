//roster.cpp
//
//

#include "roster.h"
#include <iostream>
using std::cout;
using std::endl;
#include <sstream>

// F2a: parse student datatable and forward each object to add()
void Roster::parse(const string& row) {
    // track the start and end of comma-delimited field
    size_t fieldStart = 0;
    size_t fieldEnd = row.find(',', fieldStart);

    // student ID
    string studentID = row.substr(fieldStart, fieldEnd - fieldStart);

    // first name
    fieldStart = fieldEnd + 1;
    fieldEnd = row.find(',', fieldStart);
    string firstName = row.substr(fieldStart, fieldEnd - fieldStart);

    // last name
    fieldStart = fieldEnd + 1;
    fieldEnd = row.find(',', fieldStart);
    string lastName = row.substr(fieldStart, fieldEnd - fieldStart);

    // email address
    fieldStart = fieldEnd + 1;
    fieldEnd = row.find(',', fieldStart);
    string emailAddress = row.substr(fieldStart, fieldEnd - fieldStart);

    // age
    fieldStart = fieldEnd + 1;
    fieldEnd = row.find(',', fieldStart);
    int age = stoi(row.substr(fieldStart, fieldEnd - fieldStart));

    // days in course #1
    fieldStart = fieldEnd + 1;
    fieldEnd = row.find(',', fieldStart);
    int d1 = stoi(row.substr(fieldStart, fieldEnd - fieldStart));

    // days in course #2
    fieldStart = fieldEnd + 1;
    fieldEnd = row.find(',', fieldStart);
    int d2 = stoi(row.substr(fieldStart, fieldEnd - fieldStart));

    // days in course #3
    fieldStart = fieldEnd + 1;
    fieldEnd = row.find(',', fieldStart);
    int d3 = stoi(row.substr(fieldStart, fieldEnd - fieldStart));

    // degree program
    fieldStart = fieldEnd + 1;
    string dpStr = row.substr(fieldStart);
    DegreeProgram dp;
    if (dpStr == "SECURITY") {
        dp = SECURITY;
    }
    else if (dpStr == "NETWORK") {
        dp = NETWORK;
    }
    else {
        dp = SOFTWARE;
    }

    // forward all fields into add()
    add(studentID, firstName, lastName, emailAddress,
        age, d1, d2, d3, dp);
}

// F3a: add student to roster
void Roster::add(string studentID, string firstName, string lastName,
    string emailAddress, int age,
    int daysInCourse1, int daysInCourse2, int daysInCourse3,
    DegreeProgram degreeProgram) {
    if (lastIndex < MAX_STUDENTS - 1) {
        lastIndex = lastIndex + 1;

        classRosterArray[lastIndex] = new Student(
            studentID,
            firstName,
            lastName,
            emailAddress,
            age,
            daysInCourse1,
            daysInCourse2,
            daysInCourse3,
            degreeProgram
        );
    }
    else {
        cout << "Error: roster is full, cannot add student "
            << studentID << endl;
    }
}

// F3b: remove student by id
void Roster::remove(string studentID) {
    bool found = false;

    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            found = true;

            delete classRosterArray[i];

            for (int j = i; j < lastIndex; ++j) {
                classRosterArray[j] = classRosterArray[j + 1];
            }

            classRosterArray[lastIndex] = nullptr;
            lastIndex--;

            cout << "Student " << studentID << " removed from roster." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Error: Student ID " << studentID << " not found." << endl;
    }
}

// F3c: loop through array and call print on every student
void Roster::printAll() const {
    for (int i = 0; i <= lastIndex; ++i) {
        classRosterArray[i]->print();
    }
}

// F3d print average days in course by student id
void Roster::printAverageDaysInCourse(string studentID) const {
    static bool headerDone = false;
    if (!headerDone) {
        cout << "Average Days in Course" << endl;
        headerDone = true;
    }
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            const int* days = classRosterArray[i]->getDaysInCourse();
            double average = (days[0] + days[1] + days[2]) / 3.0;
            cout << studentID << "\t" << average << endl;
            return;
        }
    }
    // error if studentID not found
    cout << "Error: Student ID " << studentID << " not found." << endl;
}

// F3e: identify invalid emails
void Roster::printInvalidEmails() const {
    cout << "Invalid emails:" << endl;
    for (int i = 0; i <= lastIndex; ++i) {
        string email = classRosterArray[i]->getEmailAddress();
        if (email.find('@') == string::npos ||
            email.find('.') == string::npos ||
            email.find(' ') != string::npos) {
            cout << email << endl;
        }
    }
    cout << endl;
}

// F3f: print all students in specified degree
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

// F3g: roster destructor
Roster::~Roster() {
    for (int i = 0; i <= lastIndex; ++i) {
        delete classRosterArray[i];
    }
    cout << "Roster Deleted." << endl;
}
