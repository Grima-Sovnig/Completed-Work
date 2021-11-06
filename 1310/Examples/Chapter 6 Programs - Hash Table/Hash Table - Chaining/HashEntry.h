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
		HashEntry* next;
		
	public:
		HashEntry(int k, int v)
		{
			this->key = k;
			this->value = v;
			this->next = NULL;
		}
		
		int getKey()
		{
			return key;
		}
		int getValue()
		{
			return value;
		}
		HashEntry* getNext()
		{
			return next;
		}
		void setNext(HashEntry *next)
		{
			this->next = next;
		}
		void setValue(int v)
		{
			value = v;
		}
};

#endif