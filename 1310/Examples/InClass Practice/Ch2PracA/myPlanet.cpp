#include "Planet.h"
#include "Planet.cpp"
#include <iostream>
using namespace std;

int main()
{   
    Planet TestPlanet;

    TestPlanet.setMinSurfaceTemp(-56.7);
    TestPlanet.setMaxSurfaceTemp(566.7);
    TestPlanet.setSize(1024.42);
    cout << "Minimum Surface Temp is: " << TestPlanet.getMinSurfaceTemp() << endl;
    cout << "Maximum Surface Temp is: " << TestPlanet.getMaxSurfaceTemp() << endl;
    cout << "The radius of the planet is: "<< TestPlanet.getSize() << endl;

    return 0;
}