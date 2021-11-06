#ifndef STRINGQUEUE_H
#define STRINGQUEUE_H

#include <iostream>
#include <string>

using namespace std;

class StringQueue
{
    private:
        struct QueueNode
        {
            string value;
            QueueNode *next;
        };

        QueueNode *front;
        QueueNode *rear;
        int numItems;
    public:
        StringQueue()
        {
            front = NULL;
            rear = NULL;
            numItems = 0;
        }
        void push_back(string v)
        {
            QueueNode *newNode = NULL;

            newNode = new QueueNode;
            newNode->value = v;
            newNode->next = NULL;

            if(isEmpty())
            {
                front = newNode;
                rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
            }
            numItems++;           
        }
        string pop_front()
        {
            QueueNode *nodePtr;
            string temp;
            if(!isEmpty())
            {
                nodePtr = front;
                front = front->next;
                temp = nodePtr->value;
                delete nodePtr;
                return temp;
            }
                     
        }
        bool isEmpty() const
        {
            bool status;
            if(numItems > 0)
                status = false;
            else
                status = true;
            return status;
        }

};


#endif
