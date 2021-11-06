//Gabriel Snider 1310-001
#include <iostream>
#include <string>
#include <fstream>
#include "Creature.h"

using namespace std;

void Creature::printCreature()
{
    bool isDanger;
    string name, description;
    float cost;
    cost = getCost();
    name = getName();
    description = getDescription();
    cout << "---------Creature Information---------" << endl;
    cout << "Name: " << name << endl;
    cout << "Description: " << description << endl; 
    isDanger = getDangerous();
    if(isDanger == true)
    {
        cout <<"Dangerous? Yes" << endl;
    }
    else
    {
        cout <<"Dangerous? No" << endl;
    }
    cout << "Cost: " << cost << endl << endl;
}

void Creature::printCreatureToFile(string fileName)
{
    ofstream outFile;
    outFile.open(fileName.c_str());
    
    
    outFile << getName() << endl;
    outFile << getDescription() << endl;
    outFile << getDangerous() << endl;
    outFile << getCost();
    
    outFile.close();
}