/*
    Title: Planet.h
    Author: Gabriel Snider
    Date: 9/16/2020
    Purpose: Header file for the myPlanet.cpp
*/
#ifndef PLANET_H
#define PLANET_H

#include <iostream>
using namespace std;

class Planet
{
    public:
        double getMinSurfaceTemp() const;
    
        double getMaxSurfaceTemp() const;
        
        double getSize() const;
        
        void setMinSurfaceTemp(double temp);
        
        void setMaxSurfaceTemp(double temp);
        
        void setSize(double temp);

        Planet()
        {
            cout << "Creating a Planet!\n";
        }
        ~Planet()
        {
            cout << "Destroying the Planet object!\n";
        }

    private:
        double minSurfaceTemp;
        double maxSurfaceTemp;
        double size;

};

#endif