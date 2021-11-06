/*
	Title:  Text.h
	Author:  Gabriel Snider
	Date:  9/24/2020
	About:  A structure version of the C++ string class
*/

#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Text
{
private:
	const char* textArray;
	int textLength;
public:
	void destroyText();
	void displayText();
	const char* getText();
	int getLength();
	void editText(char*);
	Text(const char*);
	~Text();
};

#endif