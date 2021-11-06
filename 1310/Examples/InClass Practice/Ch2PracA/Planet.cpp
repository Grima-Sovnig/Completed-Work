#include "Planet.h"
#include <iostream>
using namespace std;

double Planet::getMinSurfaceTemp() const
{
    return this->minSurfaceTemp;
}

double Planet::getMaxSurfaceTemp() const
{
    return this->maxSurfaceTemp;
}

double Planet::getSize() const
{
    return this->size;
}

void Planet::setMinSurfaceTemp(double temp)
{
    this->minSurfaceTemp = temp;
} 

void Planet::setMaxSurfaceTemp(double temp)
{
    this->maxSurfaceTemp = temp;
}

void Planet::setSize(double temp)
{
    this->size = temp;
}      