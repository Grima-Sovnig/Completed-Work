/* Author: Gabriel Snider
   Title: Program 5
   Purpose: Star Wars Imperial Mechanic Data Program, using structures.
   Date: 4/27/20
*/

#include "prog5.h"
#include "functions.cpp"

int main()
{
    int userChoice;
    int numVehicles;
    char saveFile;
    string fileName;
    ofstream outfile;
    Vehicles vehicles[100];
    do {
    cout << "What would you like to do?" << endl;
    cout <<"1.\t Enter Some Vehicles" << endl;
    cout <<"2.\t Delete a Vehicle" << endl;
    cout <<"3.\t List/Print Vehicles" << endl;
    cout <<"4.\t Print statistics on Vehicle Cost" << endl;
    cout <<"5.\t End Program." << endl;
    cout <<"Enter 1, 2, 3, 4, or, 5." << endl;
    cout <<"CHOICE: ";
    cin >> userChoice;

    while(userChoice < 1 || userChoice > 5)
    {
        cout <<"Please enter a number between 1 and 5." << endl;
        cout <<"Choice: ";
        cin >> userChoice;
    }
    if(userChoice == 1)
    {
        numVehicles = enterVehicles(numVehicles, vehicles);
    }
    else if(userChoice == 2)
    {
        numVehicles = deleteVehicles(numVehicles, vehicles);
    }
    else if(userChoice == 3)
    {
        printVehicles(numVehicles, vehicles);
    }
    else if(userChoice == 4)
    {
        printStatistics(numVehicles, vehicles);
    }

    }while(userChoice != 5);
    cout << endl << "Would you like to save your Vehicle list to a file? (y or n) ";
    cin >> saveFile;
    if (saveFile == 'y')
    {
        saveVehiclesToFile(numVehicles, vehicles);
    }
    return 0;
}
