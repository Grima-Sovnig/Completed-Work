/* Author: Gabriel Snider
   Title: Champions.cpp
   Purpose: A cpp file the holds the functions for the Champions Class.
   Date: 10/13/2020
*/
#include <iostream>
#include <string>
#include "Champions.h"

using namespace std;

string Champion::getName()
{
    return name;
}
string Champion::getRole()
{
    return role;
}
string Champion::getLane()
{
    return lane;
}
int Champion::getbaseHp()
{
    return baseHp;
}
int Champion::getIdNum()
{
    return idNum;
}
void Champion::setName(string n)
{
    this->name = n;
}
void Champion::setRole(string r)
{
    this->role = r;
}
void Champion::setLane(string l)
{
    this->lane = l;
}
void Champion::setBaseHp(int b)
{
    this->baseHp = b;
}
void Champion::setIdNum(int k)
{
    this->idNum = k;
}
void Champion::printChampion()
{
    name=getName();
    role=getRole();
    lane=getLane();
    baseHp=getbaseHp();
    idNum=getIdNum();

    cout << "ID: " << idNum << endl;
    cout << "NAME: " << name << endl;
    cout << "ROLE: " << role << endl;
    cout << "LANE: " << lane << endl;
    cout << "BASE HP: " << baseHp << endl;
}