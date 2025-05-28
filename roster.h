//roster.h
//
//

#pragma once

#include "student.h"

// Requirement F: create a roster class
class Roster {
private:
    static const int MAX_STUDENTS = 5;
    Student* classRosterArray[MAX_STUDENTS];
    int lastIndex = -1;

public:
    // F2a: parse and add to roster
    void parse(const string& row);
    
    // F3a: add student record
    void add(string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram degreeProgram);

    // F3b: remove student record
    void remove(string studentID);

    // F3c: print all student records
    void printAll() const;

    // F3d: print the average days in course
    void printAverageDaysInCourse(string studentID) const;

    // F3e: print all invalid email addresses
    void printInvalidEmails() const;

    // F3f: print students by degree program
    void printByDegreeProgram(DegreeProgram degreeProgram) const;

    // F3g: destructor to release memory
    ~Roster();
};
