/*
    Title: course.h
    Author: Gabriel Snider
    Date: 8/26/2020
    Purpose: This program uses a function to return a structure.
*/

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
using namespace std;

struct Course
{
    string Name;
    string Location;
    string* Sections;
    int NumberOfSections;
    int NumberOfCreditHours;

};

Course* createCourse(string, string, int, int);
void printCourse(Course* myCourse);
void destroyCourse(Course* myCourse);






#endif