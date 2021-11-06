/*
	Title: functions.cpp
	Author: Gabriel Snider
	Purpose: A program that contains all the necessary functions for the Driver.cpp
	Date: 8/26/2020
*/

#include "circle.h"
#include <iostream>
using namespace std;

int howManyCircles()
{
	int numCircles;
	cout << "\n\nHow many circles do you have?";
	cin >> numCircles;
	return numCircles;
}