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
    // E2c: a constructor using all the input parameters provided
    Student(string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram degreeProgram);

    // E2a: an accessor (i.e., getter) for each instance variable
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    const int* getDaysInCourse() const;
    DegreeProgram getDegreeProgram() const;

    // E2b: a mutator (i.e., setter) for each instance variable
    void setStudentID(const string& studentID);
    void setFirstName(const string& firstName);
    void setLastName(const string& lastName);
    void setEmailAddress(const string& emailAddress);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegreeProgram(DegreeProgram degreeProgram);

    // E2d: a print() function to print specific student data in the required format:
    void print() const;
};
