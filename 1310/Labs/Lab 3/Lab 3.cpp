/*
	Title:  Lab3.cpp
	Author: Gabriel Snider
	Purpose:  Demonstrate your knowledge of recursive functions
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrModified;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				//print out the result of the sumOfNumbers function here
				cout << "\n The result is: " << sumOfNumbers(num) << endl;
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				//print if the value that the user entered is in the array or not here
				bool answer;
				answer = isMember(myArray, num, ARRAY_SIZE);
				if(answer == true)
				{
					cout << endl << num << " is in the array.";
				}
				else if(answer == false)
				{
					cout << endl << num << " is not in the array.";
				}
				
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				//call string reverser function here
				stringReverser(userString);
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;
				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',') 
					{
						userStrModified.erase(x, 1);
					}
				}
				
				//print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				isPalindrome(userString);
				cout << endl << userString;
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				//print out the value returned from the multiply function here
				cout << multiply(num1, num2);
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}


//implement the five recursive functions below!!!!


int sumOfNumbers(int n)
{
	if (n != 0)
	{
		return n + sumOfNumbers(n - 1);
	}
	else
	{
		return n;
	}
}

bool isMember(int* myArray, int v, int ARRAY_SIZE)
{
	if (ARRAY_SIZE == 0)
	{
		return false;
	}
	else if (myArray[ARRAY_SIZE] == v)
	{
		return true;
	}
	else
	{
		isMember(myArray, v, ARRAY_SIZE - 1);
	}
}

void stringReverser(string uS)
{
	if(uS.size() == 0)
	{
		return;
	}
	stringReverser(uS.substr(1));
	cout << uS[0];
}

bool isPalindrome(string s)
{
	int length = s.length();
	if (length <= 1)
	{
		cout << "String is a Palindrome." << endl;
	}
	else if (s.at(0) == s.at(length-1))
	{
		s = s.substr(1,(length - 2));
		isPalindrome(s);
	}
	else
	{
		cout << "String is not a Palindrome." << endl;
	}	
}

int multiply(int a, int b)
{
	if(a == 0 || b == 0)
	{
		return 0;
	}
	return a + multiply(a, b - 1);
}