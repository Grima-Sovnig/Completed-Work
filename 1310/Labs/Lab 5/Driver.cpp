/* Author: Gabriel Snider
   Purpose: A program that creates a halloween linked list.
   Date: 10/3/2020
*/
#include <iostream>
#include <string>
#include "List.h"

using namespace std;

int main()
{
    LinkedList Monsters;
    cout <<"The linked list has been created." << endl;
    Monsters.appendNode("boogeyman");
    Monsters.appendNode("ghost");
    Monsters.appendNode("scarecrow");
    Monsters.appendNode("witch");
    Monsters.appendNode("zombie");

    cout << "\nAdding several strings to the list.\n";
    Monsters.displayList();
    Monsters.insertNode(3, "vampire");
    cout << "\nAdding vampire to the list.\n";
    Monsters.displayList();
    Monsters.deleteNode("ghost");
    cout << "\nDeleting ghost from the list.\n";
    Monsters.displayList();
}