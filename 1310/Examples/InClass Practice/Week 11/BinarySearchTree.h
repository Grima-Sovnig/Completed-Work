#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
using namespace std;

class BinarySearchTree
{
    private:
        struct TreeNode
        {
            int item;
            TreeNode *left;
            TreeNode *right;
        };

        TreeNode *root;

        void _deleteTree(TreeNode *curr)
        {
            _deleteTree(curr->left);

            _deleteTree(curr->right);
            delete curr;
        }
        void _displayTree(TreeNode *curr) const
        {
            if (curr)
            {
                _displayTree(curr->left);
                cout << curr->item << endl;
                _displayTree(curr->right);
            }
        }

    public:
        BinarySearchTree()
        {
            root = NULL;
        }
        ~BinarySearchTree()
        {
            _deleteTree(root);
        }
        void insert(TreeNode *&nodePtr, TreeNode *&newNode)
        {
            if(nodePtr == nullptr)
                nodePtr = newNode;
            else if (newNode->item < nodePtr->item)
                insert(nodePtr->left, newNode);
            else
                insert(nodePtr->right, newNode);
            
        }
        bool search(int item)
        {
            TreeNode *nodePtr = root;

            while (nodePtr)
            {
                if(nodePtr->item == item)
                    return true;
                else if (item < nodePtr->item)
                    nodePtr = nodePtr->left;
                else
                    nodePtr = nodePtr->right;
            }
            return false;
        }
        void displayTree()
        {
            _displayTree(root);
        }
        void insertNode(int num)
        {
            TreeNode *newNode = NULL;
            newNode = new TreeNode;
            newNode->item = num;
            newNode->left = newNode->right = NULL;

            insert(root, newNode);
        }

};


#endif