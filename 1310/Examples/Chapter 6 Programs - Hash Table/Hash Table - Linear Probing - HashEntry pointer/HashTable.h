/*
	Title:  HashTable.h
	Author:	April Crockett
	Purpose:  	Hash Table Implementation
				Values					-	integers
				Hash Function			-	modulus operator
				Collision resolution	-	linear probing
				
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iomanip>
#include "HashEntry.h"
using namespace std;

class HashTable
{
	private:
		int tableSize;
		HashEntry** hashArray;
		
	public:
		HashTable(int size){
			tableSize = size;
			hashArray = new HashEntry*[tableSize];
			for(int i=0; i<tableSize; i++)
			{
				hashArray[i] = NULL;
			}
		}
		~HashTable()
		{
			for(int i=0; i<tableSize; i++)
			{
				if(hashArray[i] != NULL)
					delete hashArray[i];
			}
			delete [] hashArray;
		}
		
		int getValue(int key)
		{
			int bucketIndex = key % tableSize;
			while(hashArray[bucketIndex] != NULL && hashArray[bucketIndex]->getKey() != key)
			{
				bucketIndex = (bucketIndex+1) % tableSize;
			}
			if(hashArray[bucketIndex] == NULL)
				return -1;
			else
				return hashArray[bucketIndex]->getValue();
		}
		
		void putValue(int key, int value)
		{
			int bucketIndex = key % tableSize;
			cout << "BUCKET " << bucketIndex << endl;
			
			//while there is something already in this bucket and it is a different value
			//note that duplicate values get overwritten but non duplicates get pushed into further buckets
			while(hashArray[bucketIndex] != NULL && hashArray[bucketIndex]->getKey() != key)
			{
				bucketIndex = (bucketIndex+1) % tableSize;
				cout << "BUCKET " << bucketIndex << endl;
			}
				
			hashArray[bucketIndex] = new HashEntry(key, value);
		}
		
		void printHashTable()
		{
			cout << "----------\n";
			
			for(int i=0; i<tableSize; i++)
			{
				if(hashArray[i] != NULL)
					cout << "|" << setw(8) << hashArray[i]->getValue() << "|\n";
				else
					cout << "|" << setw(8) << -1 << "|\n";
			}
			cout << "----------\n\n";
		}
	
};


#endif