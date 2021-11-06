/*
	Title:  Driver.cpp
	Author:  April R Crockett and Gabriel Snider
	Date:  10/20/2020
	Purpose:  Creates and uses a StringQueue object
*/
#include <iostream>
#include "StringQueue.h"
using namespace std;

int main()
{
	const int MAX_VALUES = 10;

	//create the queue
	StringQueue myQueue;
	string candy;

	cout << "\n\nMomma is going to buy us some candy!\n";
	cout << "She may not let us buy all of it so lets make a queue \n";
	cout << "and add our top 10 candy choices in the order from most favorite to \n";
	cout << "least favorite so she will buy our most favorite first!!\n\n";
	// User enters their fav candy
	for (int x = 0; x < 10; x++)
	{
		cout << "CANDY " << x+1 << ":  ";
		getline(cin, candy);
		myQueue.push_back(candy);
	}

	// Mom buys the candy
	cout << "\nYay!  Momma is home from the Piggly Wiggly!  Here is the candy she bought:\n";
	while (!myQueue.isEmpty())
	{
		candy = myQueue.pop_front();
		cout << candy << endl;
	}
	cout << "\nYESSSSSS!  She bought it all!\n\n";
	
	return 0;
}