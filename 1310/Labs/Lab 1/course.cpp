#include "course.h"

Course* createCourse(string n, string l, int s, int h)
{
    Course* temp = new Course;
    temp->Name = n;
    temp->Location = l;
    temp->NumberOfSections = s;
    temp->NumberOfCreditHours = h;
    temp->Sections = new string [s];

    return temp;
}

void printCourse(Course* myCourse)
{
    cout << "COURSE NAME: \t" << myCourse->Name << endl;
    cout << "COURSE LOCATION: \t" << myCourse->Location << endl;
    cout << "COURSE HOURS: \t" << myCourse->NumberOfCreditHours << endl;
    cout << "COURSE SECTIONS:\t" << endl;
    for (int i=0; i < myCourse->NumberOfSections; i++)
    {
        cout << myCourse->Sections[i] << endl;
    }

}

void destroyCourse (Course* myCourse)
{
   delete [] myCourse;
}