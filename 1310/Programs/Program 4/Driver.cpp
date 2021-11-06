#include <iostream>
#include <fstream>
#include "AVLTree.h"
#include "Professor.h"

using namespace std;

void readFromFile(AVLTree *professorData);

int main()
{
    AVLTree professorData;
    char runAgain;
    string professorName;
    readFromFile(&professorData);
    do
    {
        cout << "\n\nWhich Computer Science professor do you want details about?" << endl;
        professorData.displayInOrder();
        getline(cin, professorName);
        cout << professorName;
        if(professorData.searchNode(professorName) != NULL)
        {
            cout << *(professorData.searchNode(professorName))<< endl;
        }
        else
        {
            cout << "\n That professor is not in the AVL Tree. " << endl;
        }
        cout << "\n Would you like to search another? (y/n): ";
        cin >> runAgain;
        cin.ignore();

    } while (runAgain != 'n');
    
}

void readFromFile(AVLTree *professorData)
{
    fstream infile;
    string pName, course;
    string temp;
    Professor* newProfessor;
    bool clearGrading, goodFeedback, caring, reachable, toughGrader, lectureHeavy, attendance;
    int count = 0;

    infile.open("ProfessorData.txt");
    if(!infile)
    {
        cout << "\nSorry! Can't read professor data from file!";
    }
    else
    {
        while(getline(infile, pName, '$'))
        {
            getline(infile, course, '$');
            getline(infile, temp, '$'); clearGrading = temp[0]-48;
            getline(infile, temp, '$'); goodFeedback = temp[0]-48;
            getline(infile, temp, '$'); caring = temp[0]-48;
            getline(infile, temp, '$'); reachable = temp[0]-48;
            getline(infile, temp, '$'); toughGrader = temp[0]-48;
            getline(infile, temp, '$'); lectureHeavy = temp[0]-48;
            getline(infile, temp, '$'); attendance = temp[0]-48;
            newProfessor = new Professor(pName, course, clearGrading, goodFeedback, caring, reachable, toughGrader, lectureHeavy, attendance);
            professorData->insertNode(pName,newProfessor); 
            count++;
        }
    }

    cout << "There were " << count << " professors added from the file." << endl;
    infile.close();
}