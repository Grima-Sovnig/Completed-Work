//Gabriel Snider 1310-001

#include <iostream>
#include <string>


using namespace std;


template<typename ItemType>
class LinkedList
{
    private:
    struct ListNode
    {
        ItemType node;
        ListNode *next;
    
    };
    ListNode *head;
    ListNode *tail;
    int nodes;
    public:
        LinkedList<ItemType>()
        {
            head = NULL;
            tail = NULL;
            nodes = 0;
        }

        ~LinkedList()
        {
            while(getLength() > 0)
            {
                deleteNode(1);
            }
        }

        int getLength()
        {
            return nodes;
        }
        ItemType getNodeValue(int n)
        {
            ListNode *nodePtr;

            if (!head)   
            {
                ItemType null;
                return null;
            }
            nodePtr = head;
            for (int i = 0; i < n; i++)
            {
                nodePtr = nodePtr->next;
            }
            return nodePtr->node;
        }
        void appendNode(ItemType val)
        {
            ListNode *newNode;
            newNode = new ListNode;

            newNode->node = val;
            newNode->next = NULL;
            if (!head)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
               tail->next = newNode;
               tail = newNode;
            }
            nodes++;
        }
        void deleteNode(int n)
        {
            ListNode *nodePtr = head;
            ListNode *previousNode = NULL;

            if (!head)
                return;

            if (n >= nodes)
                return;

            if (n == 0)   
            {
                nodePtr = head->next;
                delete head;
                head = nodePtr;
                nodes--;
            }

            else
            {
                for (int i=0; i < n; i++)   
                {
                    previousNode = nodePtr;
                    nodePtr = nodePtr->next;
                }

                if (nodePtr)   
                {
                    if (nodePtr == tail)
                    tail = previousNode;
                    previousNode->next = nodePtr->next;
                    delete nodePtr;
                    nodes--;
                }
            }
}
};
