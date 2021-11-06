#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include "HashEntry.h"

using namespace std;

class HashTable
{
    private:
        int tableSize;
        HashEntry** hashArray;
    public:
        HashTable(int size)
        {
            tableSize = size;
            hashArray = new HashEntry*[tableSize];
            for(int i=0; i<tableSize; i++)
                hashArray[i] = NULL;
        }
        ~HashTable()
        {
            for(int i=0; i<tableSize; i++)
            {
                if(hashArray[i] != NULL)
                {
                    HashEntry *prevEntry = NULL;
                    HashEntry *entry = hashArray[i];
                    while(entry != NULL)
                    {
                        prevEntry = entry;
                        entry = entry->getNext();
                        delete prevEntry;
                    }
                }
            }
            delete [] hashArray;
        }
        int convertToInt(string value)
        {
            for (int i=0; i<value.length(); i++)
            {
                char x = value.at(i);
                return int(x);
            }
        }
        void putValue(string value)
        {
            int key = convertToInt(value);
            int bucketIndex = key % tableSize;
            cout << "BUCKET " << bucketIndex << endl;

            if(hashArray[bucketIndex] == NULL)
            {
                hashArray[bucketIndex] = new HashEntry(key, value);
            }
            else
            {
                HashEntry* entry = hashArray[bucketIndex];
                while(entry->getNext() != NULL)
                    entry = entry->getNext();
                if(entry->getKey() == key)
                    entry->setValue(value);
                else
                    entry->setNext(new HashEntry(key, value));
            }
        }
        void printHashTable()
        {
            cout << "HERE IS THE TABLE:" << endl;
            cout << "----------\n";

            for(int i=0; i<tableSize; i++)
            {
                if(hashArray[i] != NULL)
                {
                    HashEntry* entry = hashArray[i];
                    while(entry->getNext() != NULL)
                    {
                        cout << "---->" << setw(8) << entry->getValue();
                        entry = entry->getNext();
                    }
                    cout << "---->" << setw(8) << entry->getValue();
                    cout << endl;

                }
                else
                {
                    cout << setw(8) << "empty" << "\n";
                }
                
            }
            cout << "----------\n\n";
        }
};


#endif