//  main.cpp
//  C867 PRFA — JYM2 Task 1: Class Roster
//
// Created by Jedi Lee 5/24/2025

#include <iostream>
#include <string>
using namespace std;
#include "roster.h"

int main() {
    // B: student data table
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jedi,Lee,jlee1146@wgu.edu,34,7,2,14,SOFTWARE"
    };

    // F1: print course header
    cout << "C867 Scripting and Programming - Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "WGU Student ID: jlee1146" << endl;
    cout << "Name: Jedi Lee" << endl;
    cout << endl;

    // F2: instantiate roster object
    Roster classRoster;

    // F2a: parse student data into roster
    for (int i = 0; i < 5; ++i) {
        classRoster.parse(studentData[i]);
    }

	return 0;
}