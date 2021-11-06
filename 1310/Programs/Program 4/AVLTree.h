#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <string>
#include "Professor.h"

using namespace std;

class AVLTree
{
    private:
        struct TreeNode
        {
            string name;
            Professor *prof;
            TreeNode *left;
            TreeNode *right;
        };

        TreeNode *root;

        void insert(TreeNode *&, TreeNode *&);
        void destroySubTree(TreeNode *nodePtr);
        void displayInOrder(TreeNode *nodePtr) const;
        int height(TreeNode *temp);
        int diff(TreeNode *);
        void balance(TreeNode *&);
        TreeNode* l_rotation(TreeNode *parent)
        {
            TreeNode *temp;
            temp = parent->right;

            parent->right = temp->left;
            temp->left = parent;
            return temp;
            
        }
        TreeNode* r_rotation(TreeNode *parent)
        {
            TreeNode *temp;
            temp = parent->left;
            parent->left = temp->right;
            temp->right = parent;
            return temp;
        }
        TreeNode* lr_rotation(TreeNode *parent)
        {
            TreeNode *temp;
            temp = parent->left;
            parent->left = l_rotation(temp);
            return r_rotation(parent);
        }
        TreeNode* rl_rotation(TreeNode *parent)
        {
            TreeNode *temp;
            temp = parent->right;
            parent->left = r_rotation(temp);
            return l_rotation(parent);
        }
    
    public:
        AVLTree()
        {
            root = NULL;
        }
        ~AVLTree()
        {
            destroySubTree(root);
        }
        void insertNode(string, Professor*);
        Professor* searchNode(string);
        void displayInOrder() const
        {
            displayInOrder(root);
        }
};



#endif