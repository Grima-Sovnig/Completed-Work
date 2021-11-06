/*  Title: program4.cpp
    Author: Gabriel Snider
    Date:   4/10/2020
    Purpose: Madlibs Game, using arrays, file input/output, and dynamic memory allocation.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int showMenuGetChoice();
string *createStringArray(int);
void getInfoFromUser(string *QuestionArray, string *AnswerArray, int size);
void printStory(int uC, string *AnswerArray, int size);

// Calls all the other functions to make a working Madlibs game. 
int main ()
{
    int UserChoice;
    
    ifstream QuestionFile;
    ifstream TextFile;
    string *QuestionArray;
    string *AnswerArray;
    int arraySize;
    do {

    UserChoice=showMenuGetChoice();

    if (UserChoice == 1)
    {
        ifstream QuestionFile;
        QuestionFile.open("starWars.txt");
        QuestionFile >> arraySize;
        QuestionArray=createStringArray(arraySize);
        AnswerArray=createStringArray(arraySize);
        if(QuestionFile.is_open())
        {
            QuestionFile.ignore();
            for(int i=0; i < arraySize; i++)
            {
                getline(QuestionFile, *(QuestionArray+i));
            }
        }

        getInfoFromUser(QuestionArray, AnswerArray, arraySize);
        printStory(UserChoice, AnswerArray, arraySize);
        
        QuestionFile.close();
        
    }

    else if(UserChoice == 2)
    {
        ifstream QuestionFile;
        QuestionFile.open("dog.txt");
        QuestionFile >> arraySize;

        QuestionArray=createStringArray(arraySize);
        AnswerArray=createStringArray(arraySize);
        
        if(QuestionFile.is_open())
        {
            QuestionFile.ignore();
            for(int i=0; i < arraySize; i++)
            {
                getline(QuestionFile, *(QuestionArray+i));
            }
        }

        getInfoFromUser(QuestionArray, AnswerArray, arraySize);
        printStory(UserChoice, AnswerArray, arraySize);
        
        QuestionFile.close();
    }

    else if(UserChoice == 3)
    {
        ifstream QuestionFile;
        QuestionFile.open("pirate.txt");
        QuestionFile >> arraySize;

        QuestionArray=createStringArray(arraySize);
        AnswerArray=createStringArray(arraySize);
        
        if(QuestionFile.is_open())
        {
            QuestionFile.ignore();
            for(int i=0; i < arraySize; i++)
            {
                getline(QuestionFile, *(QuestionArray+i));
            }
        }

        getInfoFromUser(QuestionArray, AnswerArray, arraySize);
        printStory(UserChoice, AnswerArray, arraySize);
        
        QuestionFile.close();
    }
    
    } while(UserChoice != 4);

    
    delete QuestionArray;
    delete AnswerArray;

    return 0;
}


// Shows the user the menu, and allows them to make decisions. The user's choice is returned from this function.
int showMenuGetChoice()
{
    int UserChoice;
    cout <<"\nLet's Play some Madlibs!!" << endl << endl;
    cout <<"Choose a MAD LIBS game:"<< endl;
    cout <<"1. The Power of the Force (Star Wars Mad Libs)" << endl;
    cout <<"2. Dog Days (Dog Ate My Mad Libs)" << endl;
    cout <<"3. Talk Like a Pirate (Pirates Mad Libs)" << endl;
    cout <<"4. END GAME" << endl;

    cout <<"CHOOSE 1-4: ";

    cin >> UserChoice;
    while(UserChoice < 1 || UserChoice > 4)
    {
        cout <<"Please enter a number between 1-4." << endl;
        cin >> UserChoice;
    }

    return UserChoice;
}


// Takes in a integer and creates a array of that size. Dynamically allocates the array and returns a point to this array.
string *createStringArray(int size)
{
    string*QuestionArray;
    QuestionArray = new string[size];

    return QuestionArray;
}


// Takes in a pointer to the question array, pointer to answer array, and the array size. Displays to the user the questions from prompt and allows them to input a answer.
void getInfoFromUser(string *QuestionArray, string *AnswerArray, int size)
{
    cout << "Please give a response to each request.\n" << endl;
    cin.ignore();
    for(int i = 0; i < size; i++)
    {
        cout << QuestionArray[i] <<": ";
        getline(cin, AnswerArray[i]);
    }

}


// Takes in the user choice of which file to open, the answer array, and the array size. It then opens the file if its there, parses it, and prints out answers from the answer array.
void printStory(int uC, string *AnswerArray, int size)
{
    if(uC == 1)
    {
        ifstream TextFile;
        string line;
        TextFile.open("starWarsText.txt");
        if (TextFile.is_open())
        {
            for (int i = 0; i < size; i++)
            {
                getline (TextFile, line);
                
                cout << line << AnswerArray[i];
                
            }
            
        }
        TextFile.close();
    }

    else if (uC == 2)
    {
        ifstream TextFile;
        string line;
        TextFile.open("dogText.txt");
        if (TextFile.is_open())
        {
             for (int i = 0; i < size; i++)
            {
                getline (TextFile, line);
                
                cout << line << AnswerArray[i];
                
            }
            
        }
        TextFile.close();
    }

    else if (uC == 3)
    {
        ifstream TextFile;
        string line;
        TextFile.open("pirateText.txt");
        if (TextFile.is_open())
        {
            for (int i = 0; i < size; i++)
            {
                getline (TextFile, line);
                
                cout << line << AnswerArray[i];
                
            }
            
        }
        TextFile.close();
    }
}




