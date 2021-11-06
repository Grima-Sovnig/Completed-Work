/*
	Stack In-Class Practice
	File:  Driver.cpp
	Author:  April Crockett
	Date:  10/2/2020
*/
#include <iostream>
#include "StringStack.h"
using namespace std;

int main()
{
	// Define a StringStack object.
	StringStack stack;
	string animal, lastAnimal;
	
	//get input from user and push to the stack
	cout << "\n\nWhat did the old lady eat first?	";
	getline(cin, animal);
	stack.push(animal);
	for(int x=0; x < 6; x++)
	{
		cout << "\nWhat did she eat next?	";
		getline(cin, animal);
		stack.push(animal);
	}
	cout << "\nWhat did she eat last?	";
	getline(cin, animal);
	stack.push(animal);
	
	//start popping from stack and print results
	lastAnimal = stack.pop();
	animal = stack.pop();
	cout << "\n\nShe swallowed the " << animal << " to catch the ";
	animal = stack.pop();
	cout << animal << ",\nShe swallowed the " << animal << " to catch the ";
	animal = stack.pop();
	cout << animal << ",\nShe swallowed the " << animal << " to catch the ";
	animal = stack.pop();
	cout << animal << ",\nShe swallowed the " << animal << " to catch the ";
	animal = stack.pop();
	cout << animal << ",\nShe swallowed the " << animal << " to catch the ";
	animal = stack.pop();
	cout << animal << "\nThat wriggled and jiggled and tickled inside her!\n";
	cout << "She swallowed the " << animal << " to catch the ";
	animal = stack.pop();
	cout << animal << ";\nI don\'t know why she swallowed a " << animal;
	cout << " - Perhaps she\'ll die!\n\n";
	
	cout << "There was an old lady who swallowed a " << lastAnimal;
	cout << ";\n...She\'s dead, of course!\n\n";
	return 0;
}