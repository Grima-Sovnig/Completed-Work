#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

template <typename T>
class BinaryTree
{
    private:
        struct TreeNode
        {
            T value;
            TreeNode *left;
            TreeNode *right;
        };
        TreeNode *root;
        void insert(TreeNode *&, TreeNode *&);
        void destroySubTree(TreeNode *);
        void displayInOrder(TreeNode *) const;
        void displayPreOrder(TreeNode *) const;
        void displayPostOrder(TreeNode *) const;
    
    public:
        BinaryTree()
        {
            root = NULL;
        }
        ~BinaryTree()
        {
            destroySubTree(root);
        }
        void insertNode(T);
        void displayInOrder() const
        {
            displayInOrder(root);
        }
        void displayPreOrder() const
        {
           displayPreOrder(root); 
        }
        void displayPostOrder() const
        {
            displayPostOrder(root);
        }

};

template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if (nodePtr == nullptr)
    {
        nodePtr = newNode;
    }
    else if (newNode->value < nodePtr->value)
    {
        insert(nodePtr->left, newNode);
    }
    else
    {
        insert(nodePtr->right, newNode);
    }
}

template <class T>
void BinaryTree<T>::insertNode(T item)
{
    TreeNode *newNode = nullptr;
    newNode = new TreeNode;
    newNode->value = item;
    newNode->left = newNode->right = nullptr;

    insert(root, newNode);
}

template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)
{
    if(nodePtr)
    {
        if (nodePtr->left)
            destroySubTree(nodePtr->left);
        if (nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }
}

template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        cout << nodePtr->value << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << endl;
    }
}

#endif