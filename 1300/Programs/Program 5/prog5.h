#ifndef _PROG5_H
#define _PROG5_H


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;



struct Cost
{
    float repairHours;
    float costPerHour;
    float costOfParts;
    float costOfMaterials;
};

struct Vehicles
{
    string vehicleName;
    string vehicleDescription;
    bool vehicleWeapons;
    Cost vehicleCosts;
};

int enterVehicles(int numVehicles, Vehicles vehicles[100]);
int deleteVehicles(int numVehicles, Vehicles vehicles[100]);
bool moveArrayElements(string name, int numVehicles, Vehicles vehicles[100]);
void printVehicles(int numVehicles, Vehicles vehicles[100]);
void printStatistics(int numVehicles, Vehicles vehicles[100]);
void saveVehiclesToFile(int numVehicles, Vehicles vehicles[100]);
float convertToFloat(string s);




#endif