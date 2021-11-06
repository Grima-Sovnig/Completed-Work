/* Gabriel Snider, Week 7 In-Class Practice */
#ifndef StringStack_H
#define StringStack_H
#include <iostream>
#include <string>

using namespace std;

class StringStack
{
    private:
        struct ListNode
        {
            string value;
            struct ListNode *next;
        };

        ListNode *top;
    
    public:
        StringStack()
        {
            top = NULL;
        }

        ~StringStack()
        {
            ListNode *nodePtr;
            ListNode *nextNode;

            nodePtr = top;

            while(nodePtr)
            {
                nextNode = nodePtr->next;
                delete nodePtr;
                nodePtr = nextNode;
            }
            cout <<"\n\nDeleted all the nodes in the stack!!\n\n";
        }
        
        void push(string val)
        {
            ListNode *newNode;
            newNode = new ListNode;
            newNode->value = val;
            if(!top)
            {
                newNode->next = NULL;
            }
            else
            {
                newNode->next = top;
            }
            top = newNode;
            
        }
        string pop()
        {
            ListNode *nodePtr;
            string temp;

            if(!top)
            {
                cout <<"\n\n The stack is empty.\n\n";
            }
            else
            {
                nodePtr = top;
                if(top->next != NULL)
                {
                    top = top->next;
                }
                else
                {
                    top = NULL;
                }
                temp = nodePtr->value;
                delete nodePtr;
                return temp;
            }
            
        }

};






#endif