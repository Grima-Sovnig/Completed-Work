#ifndef LinkedList_H
#define LinkedList_H
#include <iostream>
#include <string>
using namespace std;
class LinkedList
{
    private:
        struct ListNode
        {
            string dogBreed;
            struct ListNode *next;
        };
        ListNode *head;
        ListNode *tail;
    public:
        LinkedList()
        {
            head = NULL;
            tail = NULL;
        }

        ~LinkedList()
        {
            ListNode *nodePtr;
            ListNode *nextNode;

            nodePtr = head;
            
            while(nodePtr != NULL)
            {
                nextNode = nodePtr->next;
                delete nodePtr;
                nodePtr = nextNode;
            }
        }
        void appendNode(string dog)
        {
            ListNode *newNode;
            newNode = new ListNode;
            newNode->dogBreed = dog;
            newNode->next = NULL;

            if(!head)
            {
            head = newNode;
            tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
        void displayList() const
        {
            ListNode *nodePtr;

            if(head != NULL)
            {
                nodePtr = head;
                while(nodePtr)
                {
                    cout << nodePtr->dogBreed << endl;
                    nodePtr = nodePtr->next;
                }
            }
            else
            {
                cout << "\nThere are no nodes in the list.\n\n";
            }
            
        }

};
#endif