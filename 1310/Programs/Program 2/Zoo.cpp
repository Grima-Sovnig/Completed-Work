//Gabriel Snider 1310-001
#include <string>
#include <fstream>
#include <iostream>
#include "LinkedList.h"
#include "Creature.h"

using namespace std;

void enterMagicalCreature(LinkedList<Creature> *l);
void enterMagicalCreatureFromFile(LinkedList<Creature> *l);
void deleteCreature(LinkedList<Creature> *list);
void saveCreaturesToFile(LinkedList<Creature> *list);
void printCreatures(LinkedList<Creature> *list);

int main()
{
    int userChoice, userChoice2;
    //int creaturePosition;
    char yesOrno;
    LinkedList<Creature> *list = new LinkedList<Creature>;

    do{ 
        cout << "What would you like to do?\n";
        cout << "\t1. Enter Magical Creature\n";
        cout << "\t2. Delete Magical Creature\n";
        cout << "\t3. List/Print Creatures\n";
        cout << "\t4. End Program.\n";
        cout << "\tEnter 1, 2, 3, or 4.\n";
        cout << "CHOICE: ";
        cin >> userChoice;
        if(userChoice > 4 || userChoice < 1)
        {
            cout << "Your choice was invalid. Choose a number 1 through 4.\n";
            cout << "CHOICE: ";
            cin >> userChoice;
        }

        switch(userChoice)
        {
            case 1: cout << "Do you want to enter the creature (s)\n";
                    cout << "\t 1. Manually?\n";
                    cout << "\t 2. From a file?\n";
                    cout << "ENTER 1 or 2: ";
                    cin >> userChoice2;
                    if(userChoice2 == 1)
                    {
                        enterMagicalCreature(list);
                        
                    }
                    else if(userChoice2 == 2)
                    {
                        enterMagicalCreatureFromFile(list);
                    }
                    break;
            case 2: deleteCreature(list);
                    break;
            case 3: printCreatures(list);
                    break;
            case 4: cout <<"Would you like to save your creature list to a file? (y or n): ";
                    cin >> yesOrno;
                    if(yesOrno == 'y' || yesOrno == 'Y')
                    {

                        saveCreaturesToFile(list);
                        cout << "Goodbye!\n";
                        break;
                    }
                    else
                    {
                        cout <<"Goodbye!\n\n";
                    }

        }

    }while(userChoice != 4);
    return 0;    
}

void enterMagicalCreature(LinkedList<Creature> *list)
{
    
    char runAgain = 'n';
    do
    {
        string name, description;
        char dangerChoice;
        bool Dangerous;
        float cost;

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Description: ";
        getline(cin, description);

        cout << "Is it dangerous (y/n) ";
        cin >> dangerChoice;
        if(dangerChoice == 'y')
        {
            Dangerous = true;
        }
        else if(dangerChoice == 'n')
        {
            Dangerous = false;
        }

        cout <<"Enter its maintenance cost: ";
        cin >> cost;

        Creature creature = Creature(name, description, Dangerous, cost);
        list->appendNode(creature);
        cout << name << " has been added to the Zoo" << endl << "Wanna add more(y/n)";
        cin >>runAgain;
    }while(runAgain == 'y' || runAgain == 'Y');
}

void enterMagicalCreatureFromFile(LinkedList<Creature> *list)
{
    ifstream infile;
    string filename;
    string name, description;
    bool dangerous;
    float cost;
    cout << "What is the name of the file you want to read from?\n";
    cout << "FILENAME: ";
    cin >>filename;
    infile.open(filename.c_str());

    if(infile.fail())
    {
        cout << "File does not exist. Either add creatures to Zoo and save to file, or try another file.";
        return;
    }
    
    
    while(!infile.eof())
    {
        getline(infile, name);
        getline(infile, description);
        infile >> dangerous;
        infile >> cost;
        infile.ignore();
        Creature creature = Creature(name, description, dangerous, cost);
        list->appendNode(creature);
    }


    infile.close();
}

void deleteCreature(LinkedList<Creature> *list)
{
    int creatureNumber;
    int length;
    length = list->getLength();
    cout << "The following is a list of all the creatures you take care of:\n\n";
    for(int i=0; i<= length -1; i++)
    {
        cout << i+1 <<") " << list->getNodeValue(i).getName() << endl;
    }
        cout <<"\n What creature do you wish to remove?\n\n";
        cout << "Creature Number: ";
        cin >> creatureNumber;
        list->deleteNode(creatureNumber - 1);
        cout << "\n\n You have removed the creature.\n\n";
}

void saveCreaturesToFile(LinkedList<Creature> *list)
{
    int i = 0;
    int length;
    length = list->getLength();
    string fileName;
    cout << "What do you want the filename to be?" << endl;
    cout << "FILENAME: ";
    cin >> fileName;
    
    if(list->getLength() == 0)
    {
        cout << "THERE ARE NO CREATURES AT YOUR ZOO!" << endl;
        return;
    }
    for(int i=0; i<=length -1; i++)
    {
        list->getNodeValue(i).printCreatureToFile(fileName);
    }
    
}

void printCreatures(LinkedList<Creature> *list)
{
    if(list->getLength() == 0)
    {
        cout << "NO CREATURES AT YOUR ZOO!" << endl;
        return;
    }
    int i = 0;
    while(i <= list->getLength()-1)
    {
        list->getNodeValue(i).printCreature();
        i++;
    }

}

