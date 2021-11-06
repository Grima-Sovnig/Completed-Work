#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iomanip>
#include "HashEntry.h"

using namespace std;

template <typename T>
class HashTable
{
    private:
        int tableSize;
        HashEntry<T>** hashArray;
    public:
        HashTable(int size)
        {
            tableSize = size;
            hashArray = new HashEntry<T>*[tableSize];
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
                {
                    HashEntry<T> *prevEntry = NULL;
                    HashEntry<T> *entry = hashArray[i];
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

        T getValue(int key)
        {
            int bucketIndex = key % tableSize;
            if(hashArray[bucketIndex] == NULL)
            {
                return NULL;
            }
            else
            {
                HashEntry<T> *entry = hashArray[bucketIndex];
                while(entry != NULL && entry->getKey() != key)
                {
                    entry = entry->getNext();
                }
                if(entry == NULL)
                {
                    return NULL;
                }
                else
                {
                    return entry->getValue();
                }
            }
        }

        void putValue(int key, T value)
        {
            int bucketIndex = key % tableSize;

            if(hashArray[bucketIndex] == NULL)
            {
                hashArray[bucketIndex] = new HashEntry<T>(key, value);
            }
            else
            {
                HashEntry<T>* entry = hashArray[bucketIndex];
                while(entry->getNext() != NULL)
                {
                    entry = entry->getNext();
                }
                if(entry->getKey() == key)
                {
                    entry->setValue(value);
                }
                else
                {
                    entry->setNext(new HashEntry<T>(key, value));
                }
            }
        }
        
        void removeValue(int key)
        {
            HashEntry<T> *entry;
            HashEntry<T> *prevEntry;
            int bucketIndex = key % tableSize;
            if(hashArray[bucketIndex] != NULL)
            {
                prevEntry = NULL;
                entry = hashArray[bucketIndex];
                while(entry->getNext() != NULL && entry->getKey() != key)
                {
                    prevEntry = entry;
                    entry = entry->getNext();
                }
                if(entry->getKey() == key)
                {
                    if(prevEntry == NULL)
                    {
                        HashEntry<T> *nextEntry = entry->getNext();
                        delete entry;
                        //prevEntry->setNext(nextEntry);
                        hashArray[bucketIndex] = nextEntry;
                    }
                }
                else
                {
                    HashEntry<T> *next = entry->getNext();
                    delete entry;
                    prevEntry->setNext(next);
                }
                
            }
        }

        void printHashTable()
        {
            cout << "----------\n";

            for(int i=0; i<tableSize; i++)
            {
                if(hashArray[i] != NULL)
                {
                    HashEntry<T> *entry = hashArray[i];
                    while(entry->getNext() != NULL)
                    {
                        cout << "---->" << setw(8) << *entry->getValue();
                        entry = entry->getNext();
                    }
                    cout << "---->" << setw(8) << *entry->getValue();
                    cout << "\n";
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