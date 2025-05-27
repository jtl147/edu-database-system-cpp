//student.cpp
//
//

#include "student.h"

// E2c: stub constructor
Student::Student(string studentID, string firstName, string lastName,
    string emailAddress, int age,
    int daysInCourse1, int daysInCourse2, int daysInCourse3,
    DegreeProgram degreeProgram) {}

// E2a: stub getters
string Student::getStudentID() const { return ""; }
string Student::getFirstName() const { return ""; }
string Student::getLastName() const { return ""; }
string Student::getEmailAddress() const { return ""; }
int    Student::getAge() const { return 0; }
const int* Student::getDaysInCourse() const { return nullptr; }
DegreeProgram Student::getDegreeProgram() const { return SECURITY; }

// E2b: stub setters
void Student::setStudentID(const string& studentID) {}
void Student::setFirstName(const string& firstName) {}
void Student::setLastName(const string& lastName) {}
void Student::setEmailAddress(const string& emailAddress) {}
void Student::setAge(int age) {}
void Student::setDaysInCourse(int d1, int d2, int d3) {}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {}

// E2d: stub print
void Student::print() const {}
