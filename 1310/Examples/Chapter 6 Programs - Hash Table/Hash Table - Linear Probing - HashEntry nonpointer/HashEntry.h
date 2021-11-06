/*
	Title:  HashEntry.h
	Author:	April Crockett
	Purpose:  	Hash Table Implementation
				Values					-	integers
				Hash Function			-	modulus operator
				Collision resolution	-	linear probing
				
*/

#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <iostream>
using namespace std;

class HashEntry
{
	private:
		int key;
		int value;
		
	public:
		HashEntry()
		{
		}
		HashEntry(int k, int v)
		{
			this->key = k;
			this->value = v;
		}
		
		int getKey()
		{
			return key;
		}
		int getValue()
		{
			return value;
		}
};

#endif