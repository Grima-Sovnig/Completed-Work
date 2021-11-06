#include <iostream>
#include <string>
#include "AVLTree.h"

using namespace std;

void AVLTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if (nodePtr == nullptr)
    {
        nodePtr = newNode;
    }
    else if(newNode->prof < nodePtr->prof)
    {
        insert(nodePtr->left, newNode);
        balance(nodePtr);
    }
    else
    {
        insert(nodePtr->right, newNode);
        balance(nodePtr);
    }
    
}

void AVLTree::destroySubTree(TreeNode *nodePtr)
{
    if(nodePtr)
    {
        if(nodePtr->left)
            destroySubTree(nodePtr->left);
        if(nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

void AVLTree::displayInOrder(TreeNode *nodePtr) const
{
    if(nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->name << endl;
        displayInOrder(nodePtr->right);
    }
}

int AVLTree::height(TreeNode *temp)
{
    int h = 0;
    if(temp != NULL)
    {
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

int AVLTree::diff(TreeNode *temp)
{
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int b_factor = l_height - r_height;
    return b_factor;
}

void AVLTree::balance(TreeNode *&temp)
{
    int bal_factor = diff(temp);
    if (bal_factor > 1)
    {
        if(diff(temp->left) > 0)
        {
            temp = r_rotation(temp);
        }
        else
        {
            temp = lr_rotation(temp);
        }        
    }
    else if (bal_factor < -1)
    {
        if (diff(temp->right) > 0)
        {
            temp = rl_rotation(temp);
        }
        else
        {
            temp = l_rotation(temp);
        }
    }
}



Professor* AVLTree::searchNode(string n)
{
   TreeNode *nodePtr = root;

   while(nodePtr)
   {
       if(nodePtr->name == n)
       {
           return nodePtr->prof;
       }
       else if (n < nodePtr-> name)
       {
           nodePtr = nodePtr->left;
       }
       else
       {
           nodePtr = nodePtr->right;
       }
   }
   
   return NULL;
}

void AVLTree::insertNode(string n, Professor* t)
{
    TreeNode *newNode = NULL;

    newNode = new TreeNode;
    newNode->name = n;
    newNode->prof = t;
    newNode->left = newNode->right = NULL;

    insert(root, newNode);
}
