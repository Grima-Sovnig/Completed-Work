#ifndef DYNSTACK_H
#define DYNSTACK_H
#include <iostream>
using namespace std;

template <typename T>
class DynamicStack
{
    private:
        struct StackNode
        {
            T value;
            StackNode *next;
        };
        StackNode *top;
    public:
        DynamicStack()
        {
            top = NULL;
        }
        ~DynamicStack();

        void push(T);
        void pop(T &);
        bool isEmpty();

};

template <typename T>
DynamicStack<T>::~DynamicStack()
{
    StackNode *nodePtr, *nextNode;

    nodePtr = top;

    while(nodePtr != NULL)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

template <typename T>
void DynamicStack<T>::push(T item)
{
    StackNode *newNode = NULL;

    newNode = new StackNode;
    newNode->value = item;

    if (isEmpty())
    {
        top = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
    
}

template <typename T>
void DynamicStack<T>::pop(T &item)
{
    StackNode *temp = NULL;

    if (isEmpty())
    {
        cout << "The stack is empty.\n";
    }
    else
    {
        item = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
    
}

template <typename T>
bool DynamicStack<T>::isEmpty()
{
    bool status;

    if(!top)
        status = true;
    else
        status = false;
        
    return status;    
}
#endif