#ifndef List_H
#define List_H

#include <iostream>
#include <string>
using namespace std;

class LinkedList
{
    private:
        struct ListNode
        {
            string monster;
            struct ListNode *next;
        };
        ListNode *head;
        ListNode *tail;
    public:
        // Default Constructor
        LinkedList()
        {
            head = NULL;
            tail = NULL;
        }
        // Deconstructor
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
        //Adds strings to the list.
        void appendNode(string m)
        {
            ListNode *newNode;
            newNode = new ListNode;
            newNode->monster = m;
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
        // Prints the list to the string.
        void displayList() const
        {
            ListNode *nodePtr;

            if(head != NULL)
            {
                nodePtr = head;
                while(nodePtr)
                {
                    cout << nodePtr->monster << endl;
                    nodePtr = nodePtr->next;
                }
            }
            else
            {
                cout <<"\nThere are no nodes in the list.\n\n";
            }
            
        }
        // Inserts a string in the desired position.
        void insertNode(int position, string mon)
        {
            ListNode *nodePtr;
            ListNode *newNode;
            
            newNode = new ListNode;
            newNode->monster = mon;

            if(!head)
            {
                if(position != 0)
                {
                    cout <<"\n\nUnable to insert a node at position " << position << " because there are currently no nodes in the list. I am going to insert this node at position 0.\n\n"; 
                }
                head = newNode;
                tail = newNode;
            }
            else
            {
                nodePtr = head;
                int nodeCount = 0;
                if(position == 0)
                {
                    newNode->next = head->next;
                    head = newNode;
                }
                while(nodePtr != tail && nodeCount < position)
                {
                    nodeCount++;
                    if(nodeCount == position)
                        break;
                    nodePtr = nodePtr->next;
                }

                if(nodePtr->next == NULL)
                {
                    tail = newNode;
                }
                newNode->next = nodePtr->next;
                nodePtr->next = newNode;

            }
            
        }
        // Delets the specified node.
        void deleteNode(string mon)
        {
            ListNode *nodePtr;
            ListNode *previousNode;

            if(!head)
                return;
            if(head->monster == mon)
            {
                nodePtr = head->next;
                delete head;
                head = nodePtr;
            }
            else
            {
                nodePtr = head;

                while(nodePtr != NULL && nodePtr->monster != mon)
                {
                    previousNode = nodePtr;
                    nodePtr = nodePtr->next;
                }

                if(nodePtr)
                {
                    if(nodePtr == tail)
                    {
                        tail = previousNode;
                    }
                    previousNode->next = nodePtr->next;
                    delete nodePtr;
                }
            }
            
        }
    
};




#endif