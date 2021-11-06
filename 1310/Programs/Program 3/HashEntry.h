
/* Author: Gabriel Snider
   Title: HashEntry.h
   Purpose: A header file to allow entry to the Hash Table
   Date: 10/13/2020
*/
#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <iostream>
using namespace std;

template<typename T>
class HashEntry
{
   private:
      int key;
      T value;
      HashEntry* next;
   public:
      HashEntry(int k, T v)
      {
         this->key = k;
         this->value = v;
         this->next = NULL;
      }

      int getKey()
      {
         return key;
      }
      T getValue()
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
      void setValue(T v)
      {
         value = v;
      }
      
};

#endif 