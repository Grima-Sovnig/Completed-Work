/* Author: Gabriel Snider
   Title: Champions.h
   Purpose: A header file the holds the data for the Champions Class.
   Date: 10/13/2020
*/
#ifndef CHAMPIONS_H
#define CHAMPIONS_H

#include <iostream>
#include <string>
using namespace std;

class Champion
{
   private:
      string name, role, lane;
      int baseHp, idNum;
   public:
      Champion()
      {
      }
      Champion(string n, string r, string l, int b, int k)
      {
         this->name = n;
         this->role = r;
         this->lane = l;
         this->baseHp = b;
         this->idNum = k;
      }
      string getName();
      string getRole();
      string getLane();
      int getbaseHp();
      int getIdNum();
      void setName(string n);
      void setRole(string r);
      void setLane(string l);
      void setBaseHp(int b);
      void setIdNum(int k);
      void printChampion();
      friend ostream & operator << (ostream & os, Champion & champions)
      {
         os << " Key: " << champions.getIdNum();
         os << " Name: " << champions.getName();
         /*os << " Role: " << champions.getRole();
         os << " Lane: " << champions.getLane();
         os << " Base Hp: " << champions.getbaseHp(); */
         return os;
      }
};


#endif 