#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList dogBreeds;

    dogBreeds.appendNode("Corgi");
    dogBreeds.appendNode("English Bulldog");
    dogBreeds.appendNode("Dalmatian");
    dogBreeds.appendNode("German Shepard");
    dogBreeds.appendNode("Poodle");

    dogBreeds.displayList();

    cout << "\n Goodbye!\n";
}