#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree bst;
    bool rootFound = false;

    bst.insertNode(5);
    bst.insertNode(8);
    bst.insertNode(6);
    bst.insertNode(7);
    bst.insertNode(2);
    bst.insertNode(4);
    bst.insertNode(1);
    bst.insertNode(3);
    bst.insertNode(10);
    bst.insertNode(9);

    bst.displayTree();

    rootFound = bst.search(5);

    if (rootFound)
    {
        cout << "Found Root: 5" << endl;
    }

}