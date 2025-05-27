//student.h
//
//

#pragma once

#include <string>
#include "degree.h"
using std::string;

// Requirement E: Defining the Student class
class Student {
private:
    // E1: private variables
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;

public:
    // E2c: constructor
    Student(string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram degreeProgram);

    // E2a: getter
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    const int* getDaysInCourse() const;
    DegreeProgram getDegreeProgram() const;

    // E2b: setter
    void setStudentID(const string& studentID);
    void setFirstName(const string& firstName);
    void setLastName(const string& lastName);
    void setEmailAddress(const string& emailAddress);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegreeProgram(DegreeProgram degreeProgram);

    // E2d: print() function
    void print() const;
};
