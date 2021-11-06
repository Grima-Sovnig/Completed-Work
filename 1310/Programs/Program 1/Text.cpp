/*
	Title:  Text.cpp
	Author: Gabriel Snider
	Date:  9/24/2020
	About:  A structure version of the C++ string class
*/

#include "Text.h"

using namespace std;
/*
	Function Name:  Text()
	Parameters:  Send a pointer to a constant character array or a string literal to this function
	Returns:  A pointer to a new Text variable, which contains the c-string & the length of the string
	Purpose:  To create a new Text variable
*/
Text::Text(const char* a)
{
	textLength =strlen(a);
	char* tempTextArray = new char[textLength+1];
	strcpy(tempTextArray, a);
	textArray = tempTextArray;
}
/*
	Function Name:  ~Text
	Parameters:  none
	Returns:  nothing (void)
	Purpose:  release dynamically allocated memory that the pointer is pointing to.
*/
Text::~Text()
{
	delete []textArray;
}
/*
	Function Name:  displayText()
	Parameters:  none
	Returns:  nothing (void)
	Purpose:  prints out the string (character array)
*/
void Text::displayText()
{
	//print out the c-string
	cout << textArray;
}
/*
	Function Name:  getText()
	Parameters:  none
	Returns:  pointer to a constant character array
*/
const char* Text::getText()
{
	return textArray;
}
/*
	Function Name:  getLength()
	Parameters:  none
	Returns:  the length of the string 
*/
int Text::getLength()
{
	return textLength;
}
/*
	Function Name:  editText()
	Parameters:  A char* pointer to a variable.
	Returns:  Deletes the previous created Text* array and creates a new one using the parameter.
*/
void Text::editText(char* n)
{
	delete [] textArray;
	textLength = strlen(n);
	char* newArray = new char[textLength+1];
	strcpy(newArray, n);
	textArray = newArray;
}
