#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;


class BinaryTree
{
	private:
		struct TreeNode
		{
			string name;
			int krabbyPatty;
			TreeNode* left;
			TreeNode* right;
		};
		
		TreeNode* root;
		
		// Private member functions
		void insert(TreeNode *&, TreeNode *&);
		void destroySubTree(TreeNode *);
		//void deleteNode(string n, TreeNode *&);
		//void makeDeletion(TreeNode *&);
		void displayInOrder(TreeNode *) const;
		void display(TreeNode *ptr, int level);
		void getTotal(TreeNode *nodePtr, int &total);
		void getMost(TreeNode *nodePtr, string& n, int& mostPatties);
		void getLeast(TreeNode *nodePtr, string& n, int& leastPatties);
		TreeNode* balance(TreeNode *temp)
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
				if(diff(temp->right) > 0)
				{
					temp = rl_rotation(temp);
				}
				else
				{
					temp = l_rotation(temp);
				}
			}
			return temp;
		}
		int height(TreeNode *temp)
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
		int diff(TreeNode *temp)
		{
			int l_height = height(temp->left);
			int r_height = height(temp->right);
			int b_factor = l_height - r_height;
			return b_factor;
		}
		// I cannot for the life of me figure out what im supposed to use instead of the setRight and setLeft.
		// These rotation functions are basically what I used on the inclass practice and are from the examples.
		// I guess im just missing for the equilavent functions are for this program;
		TreeNode *r_rotation(TreeNode *parent)
		{
			TreeNode *temp;
			temp = parent->left;
			parent->setRight(temp->left);
			temp->setLeft(parent);
			return temp;
		}
		TreeNode *l_rotation(TreeNode *parent)
		{
			TreeNode *temp;
    		temp = parent->getRight();
    		parent->setRight(temp->getLeft());
    		temp->setLeft(parent);
			return temp;
		}
		TreeNode *lr_rotation(TreeNode *parent)
		{
			TreeNode *temp;
    		temp = parent->getLeft();
    		parent->setLeft(l_rotation(temp));
    		return r_rotation(parent);
		}
		TreeNode *rl_rotation(TreeNode *parent)
		{
    		TreeNode *temp;
    		temp = parent->getRight();
    		parent->setRight(r_rotation(temp));
    		return l_rotation(parent);
		}
		


	public:
		// Constructor
		BinaryTree()
		{ 
			root = NULL; 
		}

		// Destructor
		~BinaryTree()
		{ 
			destroySubTree(root); 
		}

		// Binary tree operations
		void insertNode(string, int);
		int searchNode(string);
		//void remove(string);

		void displayInOrder() const
		{  
			displayInOrder(root); 
		}
		
		void getLeastNumPatties(string&, int&);
		void getMostNumPatties(string&, int&);
		int getTotalNumPatties();
		void displayTree();

};


#endif