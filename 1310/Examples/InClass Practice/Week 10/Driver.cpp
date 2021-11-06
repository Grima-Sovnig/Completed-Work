#include <iostream>
#include "HashTable.h"
using namespace std;

int main()
{
	int size;
	string value;
	
	cout << "\nHello.\n\n";
	
	cout <<"What size is the table?   ";
	cin >> size;
	cin.ignore();
	
	//create a Hash Table
	HashTable myHashTable(size);
	
	//add some keys and values
	cout << "\nEnter a value:  ";
	getline(cin,value);
	myHashTable.putValue(value);
	
	cout << "\nEnter a value:  ";
	getline(cin,value);
	myHashTable.putValue(value);
	
	cout << "\nEnter a value:  ";
	getline(cin,value);
	myHashTable.putValue(value);
	
	cout << "\nEnter a value:  ";
	getline(cin,value);
	myHashTable.putValue(value);
	
	cout << "\n\nHERE IS THE TABLE:\n\n";
	myHashTable.printHashTable();
	cout << endl << endl;
	
	
	
}