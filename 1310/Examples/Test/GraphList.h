
/*
	GraphList class file for Program 4 
    GraphList.h - CSC 1310 
	David Haleman 
	4/29/2020
*/
#ifndef GRAPHLIST_H
#define GRAPHLIST_H
#include <iostream>
using namespace std;
class GraphList
{
    private:
        struct ListNode
        {
            int value;
            ListNode* next;
        };
        ListNode ** headArray;
        int numVertices;
        int numEdges;
    public:
    GraphList(int v)//constructor
    {
        this->numVertices = v;
        headArray = new ListNode*[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            headArray[i] = NULL;
        }
    }
    ~GraphList()
    {
        ListNode *nodePrev;
        ListNode *nodeCurr;
        cout << "Deleting List" << endl;
        for (int i = 0; i <numVertices; i++)
        {
            if (headArray[i] != NULL)
            {
                headArray[i] = nodeCurr;
                while(nodeCurr->next != NULL)
                {
                    nodePrev = nodeCurr;
                    nodeCurr = nodeCurr->next;
                    delete nodePrev;
                }
            }
        }
 
    }
    void addEdge(int node1, int node2)
    {
        ListNode* firstPtr;
        ListNode* secondPtr;
        ListNode *nodeCurr;
        cout <<"Adding an edge from " << node1 << " to " << node2 << endl;
        numEdges += 1;
        if (headArray[node1] == NULL)
        {
        firstPtr = new ListNode;
        firstPtr->value = node2;
        firstPtr->next = NULL;
        }
        else
        {
        secondPtr = new ListNode;
        secondPtr->value = node2;
        secondPtr->next = NULL;
        nodeCurr = headArray[node1];
        while (nodeCurr->next != NULL)
        {
            nodeCurr = nodeCurr->next;
        }
        nodeCurr->next = secondPtr;
        }

    }
    void printGraph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            cout << i;
            if (headArray[i] != NULL)
            {
                ListNode* nodeCurr;
                nodeCurr = headArray[i];
                while (nodeCurr != NULL)
                {
                cout <<"---> " << nodeCurr->value;
                nodeCurr = nodeCurr->next;
                }
            }
            cout << "--->NULL" << endl;
        } 
    }

};
#endif