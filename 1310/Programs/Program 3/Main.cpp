/* Author: Gabriel Snider
   Title: Main.cpp
   Purpose: A driver for the program, and allows them to access and interact with hash tables.
   Date: 10/13/2020
*/
#include <iostream>
#include <string>
#include <fstream>
#include "HashTable.h"
#include "Champions.h"

using namespace std;

void addFromFile(HashTable<Champion*> *myTable);
void addManual(HashTable<Champion*> *myTable);
void searchChampion(HashTable<Champion*> *myTable);
void deleteChampion(HashTable<Champion*> *myTable);
void printHashTable(HashTable<Champion*> *myTable);


int main()
{
   int userChoice;
   HashTable<Champion*> *myTable = new HashTable<Champion*>(10);

   do{

   cout << "---League of Legends Champion Info Management---" << endl;
   cout << "1.\t Add Champions from File" << endl;
   cout << "2.\t Add Champion Manually" << endl;
   cout << "3.\t Search for Champion" << endl;
   cout << "4.\t Delete Champion" << endl;
   cout << "5.\t Print Hash Table" << endl;
   cout << "6.\t End Program" << endl;
   cout << "CHOOSE 1-6: " << endl;
   cin >> userChoice;
   if(userChoice < 1 || userChoice > 6)
   {
      cout << "Please enter a value 1-6." << endl;
      cout << "CHOOSE 1-6: " << endl;
      cin >> userChoice;
   }

   switch(userChoice)
   {
      case 1: addFromFile(myTable);
               break;
      case 2: addManual(myTable);
               break;
      case 3: searchChampion(myTable);
               break;
      case 4: deleteChampion(myTable);
               break;
      case 5: printHashTable(myTable);
               break;
      case 6: 
         cout << "Goodbye!";
         break;
   
   }


   }while(userChoice != 6);
   return 0;
}
/*
Function Name: addFromFile
Purpose: Add list of champion objects from file.
*/
void addFromFile(HashTable<Champion*> *myTable)
{
   ifstream infile;
   string filename;
   string name, role, lane;
   int baseHp, idNum;
   int counter;
   
   filename = "championFile.txt";

   infile.open(filename.c_str());

   if(infile.fail())
   {
      cout << "File could not be opened, please try again with the file championFile.txt present." << endl;
      return;
   }

   while(!infile.eof())
   {
      getline(infile, name);
      getline(infile, role);
      getline(infile, lane);
      infile >> baseHp;
      infile >> idNum;
      infile.ignore();
      Champion* champion = new Champion(name, role, lane, baseHp, idNum);
      myTable->putValue(idNum, champion);
      cout << "Entering Champion with ID: " << idNum << " and name " << name << endl;
      counter++;
   }
   cout << counter << " champions from championFile.txt have been added to the hash table." << endl;
   infile.close();
}
/*
Function Name: addManual
Purpose: Lets the user add a champion manually to the hash table.
*/
void addManual(HashTable<Champion*> *myTable)
{
   string name, role, lane;
   int baseHp, idNum;
   cout <<"KEY: ";
   cin >> idNum;
   if(!cin)
   {
      cout << "Key must be a integer try again." << endl;
      cout << "KEY: ";
      cin >> idNum;
   }
   cin.ignore();
   cout <<"NAME: ";
   getline(cin, name);
   cout <<"ROLE: ";
   getline(cin, role);
   cout <<"LANE: ";
   getline(cin, lane);
   cout <<"BASE HP: ";
   cin >> baseHp;

   Champion* champion = new Champion (name, role, lane, baseHp, idNum);
   myTable->putValue(idNum, champion);
}
/*
Function Name: searchChampion
Purpose: Allows the user to search for a desired champion based on the champions key.
*/
void searchChampion(HashTable<Champion*> *myTable)
{
   int searchKey;
   
   cout << "What is the key of the champion you are searching for? ";
   cin >> searchKey;
   Champion *temp;
   temp = myTable->getValue(searchKey);
   if(temp != NULL)
   {
      temp->printChampion();
   }
   else
   {
      cout << "There are no champions with that key in the table." << endl;
   }
   
}
/*
Function Name: deleteChampion
Purpose: Lets the user delete the desired champion by inputting the key of the champion they wish to delete.
*/
void deleteChampion(HashTable<Champion*> *myTable)
{
   int deleteKey;
   cout << "The following is a list of all champions: " << endl;
   myTable->printHashTable();
   cout << "What is the ID of the champion you wish to remove?" << endl;
   cout << "Champion ID: ";
   cin >> deleteKey;
   myTable->removeValue(deleteKey);
}
/*
Function Name: printHashTable
Purpose: Allows the user to print the current hash table.
*/
void printHashTable(HashTable<Champion*> *myTable)
{
   myTable->printHashTable();
}


