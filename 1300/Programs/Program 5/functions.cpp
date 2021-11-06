#include "prog5.h"
// This function allows the user to grab vehicles from a file, create a new list of vehicles. numVehicles is returned from this function.
int enterVehicles(int numVehicles, Vehicles vehicles[100])
{
    int i=0;
    int userChoice;
    char runAgain;
    ifstream infile;
    string fileName;
    string weapons;
    string repairHours;
    string costHours;
    string costParts;
    string costMaterials;
    


    if (numVehicles >= 100)
    {
        cout << "Garage already at full capacity!" << endl;
        return numVehicles;
    }
    
    cout << "What do you want to do?" << endl;
    cout << "   1. Load my vehicle from a file." << endl;
    cout << "   2. Enter one vehicle manually." << endl;
    cout << " Choose 1 or 2." << endl;
    cin >> userChoice;
    while (userChoice < 1 || userChoice > 2)
    {
        cout << "Out of Bounds" << endl;
        cin >> userChoice;
    }
    
    if (userChoice == 1)
    {
        cout << "what is the name of the file with your list of vehicles? (ex: filename.txt)" << endl;
        cout << "FILENAME: ";
        cin >> fileName;
        infile.open(fileName.c_str());
        if (infile) 
        {
            cout << setprecision(2) << fixed;
            getline(infile, vehicles[i].vehicleName, '#');
            while (!infile.eof())
            {
                getline(infile, vehicles[i].vehicleDescription, '#');
                getline(infile, weapons, '#');
                vehicles[i].vehicleWeapons = convertToFloat(weapons);
                getline(infile, repairHours, '#');
                vehicles[i].vehicleCosts.repairHours = convertToFloat(repairHours);
                getline(infile, costHours, '#');
                vehicles[i].vehicleCosts.costPerHour = convertToFloat(costHours);
                getline(infile, costParts, '#');
                vehicles[i].vehicleCosts.costOfParts = convertToFloat(costParts);
                getline(infile, costMaterials, '#');
                vehicles[i].vehicleCosts.costOfParts = convertToFloat(costMaterials);
                i++;
                numVehicles++;
                getline(infile, vehicles[i].vehicleName, '#');
            }
            infile.close();
            cout << "Success!" << endl;
        }
        else
        {
            cout <<"\n\n The file was unable to be opened.\n\n";
        } 
    }
    else if(userChoice == 2)
    {
        do
        {
            cin.ignore();
            cout << "\n\nNAME: ";
            getline(cin, vehicles[i].vehicleName);
            cout << "\n\nDESCRIPTION: ";
            getline(cin, vehicles[i].vehicleDescription);
            cout << "\n\nDOES THIS VEHICLE HAVE WEAPONS? (1 for yes or 0 for no): ";
            cin >> vehicles[i].vehicleWeapons;
            cout << "\n\nHow many hours do you spend repairing the " << vehicles[i].vehicleName << "?" << endl;
            cout << "NUM HOURS: ";
            cin >> vehicles[i].vehicleCosts.repairHours;
            cout << "\n\nWhat is the cost per hour of repairing the " << vehicles[i].vehicleName << "?" << endl;
            cout << "COST PER HOUR: ";
            cin >> vehicles[i].vehicleCosts.costPerHour;
            cout << "\n\nHow much money do you spend on parts for the " << vehicles[i].vehicleName << "?" << endl;
            cout << "PART COST: ";
            cin >> vehicles[i].vehicleCosts.costOfParts;
            cout << "\n\nHow much money do you spend on supplies for the " << vehicles[i].vehicleName << "?" << endl;
            cout << "SUPPLY COST: ";
            cin >> vehicles[i].vehicleCosts.costOfMaterials;
            i++;
            numVehicles++;
            cout << "The " << vehicles[i].vehicleName << "has been added." << endl << endl;
            cout << "Do you want to add more vehicles? (y or n) ";
            cin >> runAgain;

        } while (runAgain == 'y');
        
    }
    return numVehicles;
}
// This function deletes the vehicles that the user wants to. This function also returns numVehicles.
int deleteVehicles(int numVehicles, Vehicles vehicles[100])
{
    string name;
    bool removed;

    cout << "The following is a list of all the vehicles you take care of: " << endl;
    for(int i=0; i < numVehicles; i++)
    {
        cout << vehicles[i].vehicleName << endl;
    }
    cout << "What vehcile do you wish to remove?" << endl << "Vehicle Name: ";
    cin.ignore();
    getline(cin, name);
    removed = moveArrayElements(name, numVehicles, vehicles);
    if (removed == true)
    {
        cout << "You have removed " << name << "." << endl;
    }
    if (removed == false)
    {
        cout << "Name not found." << endl;
    }

    return numVehicles;
}
// This function works in part with the deleteVehicles function it returns true if the user is gone, or false if its not.
bool moveArrayElements(string name, int numVehicles, Vehicles vehicles[100])
{
    for (int i=0; i < numVehicles; i++)
    {
        if (name == vehicles[i].vehicleName)
        {
            for (int x = i; x < numVehicles; x++)
            {
                vehicles[x] = vehicles[x+1];
            }
            return true;
        }
        else
            return false;
    
        
    }
    return 0;
}
// This function prints out vehicles to the screen if the user chooses 1 or the file if they press 2.
void printVehicles(int numVehicles, Vehicles vehicles[100])
{
    int userChoice;
    string fileName;
    ofstream outfile;
    
    cout << "1. Print Vehicles to the Screen." << endl;
    cout << "2. Print Vehicles to a File." << endl;
    cin >> userChoice;
    while (userChoice < 2 || userChoice > 2)
    {
        cout << "Invaild Choice" << endl;
        cin >> userChoice;
    }

    if (userChoice == 1)
    {
        for (int i=0; i < numVehicles; i++)
        {
            cout << "--------------------------------------" << endl;
            cout << "VEHICLE " << i + 1 << ":" << endl;
            cout << "NAME:\t" << vehicles[i].vehicleName << endl;
            cout << "DESCRIPTION: " << endl;
            cout << "   " << vehicles[i].vehicleDescription << endl;
            cout << "Has Weapons?\t";
            if (vehicles[i].vehicleWeapons == 0)
                cout << "no" << endl;
            else
                cout << "yes" << endl;
            cout << "Number of hours to repair the Vehicle:\t" << vehicles[i].vehicleCosts.repairHours << endl;
            cout << "Cost Per Hour:\t" << vehicles[i].vehicleCosts.costPerHour << endl;
            cout << "Cost for Parts:\t" << vehicles[i].vehicleCosts.costOfParts << endl;
            cout << "Supplies Cost:\t" << vehicles[i].vehicleCosts.costOfMaterials << endl;
            cout << "--------------------------------------" << endl;
        }
    }
    else if (userChoice == 2)
    {
        cout <<"What is the name of the file that you wish to open?" << endl;
        cin.ignore();
        getline(cin, fileName);
        outfile.open(fileName.c_str());
        for (int i=0; i < numVehicles; i++)
        {
            outfile << "VEHICLE " << i+1 << ":" << endl;
            outfile << "Name: \t" << vehicles[i].vehicleName << endl;
            outfile << "Description: " << endl;
            outfile << vehicles[i].vehicleDescription;
            outfile << "Has Weapons?\t" << vehicles[i].vehicleWeapons << endl;
            outfile << "Number of hours to repair the Vehicle: " << vehicles[i].vehicleCosts.repairHours << endl;
            outfile << "Cost Per Hour: " << vehicles[i].vehicleCosts.costPerHour << endl;
            outfile << "Cost for Parts: " << vehicles[i].vehicleCosts.costOfParts << endl;
            outfile << "Supplies Costs:" << vehicles[i].vehicleCosts.costOfMaterials << endl; 
        }
        outfile.close();
    }
}
// This function saves the users vehicle list to a file, it is called when the user chooses to end the program.
void saveVehiclesToFile(int numVehicles, Vehicles vehicles[100])
{
    string fileName;
    ofstream outfile;

    cout << "What is the name of the file you want to save your creatures to?" << endl;

    cin.ignore();
    getline(cin, fileName);
    outfile.open(fileName.c_str());

    for (int i=0; i < numVehicles; i++)
    {
        outfile << vehicles[i].vehicleName << "#";
        outfile << vehicles[i].vehicleDescription << "#";
        if (vehicles[i].vehicleWeapons == 1)
        {
            outfile << "yes #";
        }
        else if (vehicles[i].vehicleWeapons == 0)
        {
            outfile << "no #";
        }
        outfile << vehicles[i].vehicleCosts.repairHours << "#";
        outfile << vehicles[i].vehicleCosts.costPerHour << "#";
        outfile << vehicles[i].vehicleCosts.costOfParts << "#";
        outfile << vehicles[i].vehicleCosts.costOfMaterials << "#";
    }
    outfile.close();
    cout << "Your vehicles were sucessfully saved to the " << fileName << "file." << endl;
}

void printStatistics(int numVehicles, Vehicles vehicles[100])
{
    int Cost;
    int totalCost = 0;

    cout << "Cost of Each Vehicle: " << endl;
    for (int i=0; i < numVehicles; i++)
    {
        Cost = vehicles[i].vehicleCosts.repairHours * vehicles[i].vehicleCosts.costPerHour + vehicles[i].vehicleCosts.costOfParts + vehicles[i].vehicleCosts.costOfMaterials;
        totalCost += Cost;
        cout << vehicles[i].vehicleName << "        $       " << Cost << endl;
    }
    cout << "\n Total Cost:         $          " << totalCost << endl;
}
// This function is given to us.
float convertToFloat (string s)
{
    istringstream i(s);
    float x;
    if(!(i>>x))
        x=0;
    return x;
}