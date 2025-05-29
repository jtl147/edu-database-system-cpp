#include "student.h"
#include <iostream>
using std::cout;
using std::endl;

// E2c: constructor
Student::Student(string studentID,
    string firstName,
    string lastName,
    string emailAddress,
    int age,
    int daysInCourse1,
    int daysInCourse2,
    int daysInCourse3,
    DegreeProgram degreeProgram)
    : studentID(studentID),
    firstName(firstName),
    lastName(lastName),
    emailAddress(emailAddress),
    age(age),
    degreeProgram(degreeProgram)
{
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
}

// E2a: getters
string Student::getStudentID()    const { return studentID; }
string Student::getFirstName()   const { return firstName; }
string Student::getLastName()    const { return lastName; }
string Student::getEmailAddress()const { return emailAddress; }
int    Student::getAge()         const { return age; }
const int* Student::getDaysInCourse() const { return daysInCourse; }
DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }

// E2b: setters
void Student::setStudentID(const string& id) { studentID = id; }
void Student::setFirstName(const string& fn) { firstName = fn; }
void Student::setLastName(const string& ln) { lastName = ln; }
void Student::setEmailAddress(const string& email) { emailAddress = email; }
void Student::setAge(int a) { age = a; }
void Student::setDaysInCourse(int d1, int d2, int d3) {
    daysInCourse[0] = d1;
    daysInCourse[1] = d2;
    daysInCourse[2] = d3;
}
void Student::setDegreeProgram(DegreeProgram dp) { degreeProgram = dp; }

// E2d: print 
void Student::print() const {
    cout << studentID << "\t";
    cout << "First Name: " << firstName << "\t";
    cout << "Last Name: " << lastName << "\t";
    cout << "Email: " << emailAddress << "\t";
    cout << "Age: " << age << "\t";
    cout << "daysInCourse: {"
        << daysInCourse[0] << ", "
        << daysInCourse[1] << ", "
        << daysInCourse[2] << "}\t";

    if (degreeProgram == SECURITY)       cout << "Degree Program: SECURITY";
    else if (degreeProgram == NETWORK)   cout << "Degree Program: NETWORK";
    else                                 cout << "Degree Program: SOFTWARE";

    cout << endl;
}