//roster.cpp
//
//

#include "roster.h"
#include <iostream>
using std::cout;
using std::endl;
#include <sstream>

// F2a stub: parse student datatable and forward each object to add()
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

// F3a stub
void Roster::add(string studentID, string firstName, string lastName,
    string emailAddress, int age,
    int daysInCourse1, int daysInCourse2, int daysInCourse3,
    DegreeProgram degreeProgram)
{
    // to be implemented
}

// F3b stub
void Roster::remove(string studentID)
{
    // to be implemented
}

// F3c stub
void Roster::printAll() const
{
    // to be implemented
}

// F3d stub
void Roster::printAverageDaysInCourse(string studentID) const
{
    // to be implemented
}

// F3e stub
void Roster::printInvalidEmails() const
{
    // to be implemented
}

// F3f stub
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const
{
    // to be implemented
}

// F3g stub
Roster::~Roster()
{
    // to be implemented
}
