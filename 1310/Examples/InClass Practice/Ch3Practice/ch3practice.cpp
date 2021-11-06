/*
	Title:  	ch3practice.cpp
	Author:  	Gabriel Snider
	Date:		9/23/2020
	Purpose:	Practice linear & binary search
*/
#include <iostream>
using namespace std;

const int SIZE = 6;

void sort(string arr[]);
void print(string arr[]);
bool binarySearch(string arr[], const int SIZE, string uC); 
bool linearSearch(string arr[], const int SIZE, string uC);

int main()
{
	string userCountry;

	string countries[SIZE] = 
		{
			"Norway",
			"United States",
			"United Kingdom",
			"Germany",
			"Italy",
			"Russia"
		};
		
	cout << "\nWhat is the name of your country?  ";
	getline(cin, userCountry);
	
	//FINISH THIS CODE
	bool ls;
	bool bs;
	ls = linearSearch(countries, SIZE, userCountry);
	if(ls == true)
	{
		cout << "Linear Search says that your country is one of the top six countries that eats the most pizza in the world." << endl;
	}
	else if (ls == false)
	{
		cout << "Linear Search says that your country is not one of the top six countires that eats the most pizza in the world." << endl;
	}
	sort(countries);
	print(countries);
	bs = binarySearch(countries, SIZE, userCountry);
	if(bs == true)
	{
		cout << "Binary Search says that your country is one of the top six countries that eats the most pizza in the world." << endl;
	}
	else if (bs == false)
	{
		cout << "Binary Search says that your country is not one of the top six countires that eats the most pizza in the world." << endl;
	}
	return 0;
}

//a simple function to sort array elements in ascending order
void sort(string arr[])
{
	string key; 
	int j;  
	
	for(int i=1; i < SIZE; i++)
	{
		key = arr[i]; 
		j = i-1; 
		while(j >= 0 && arr[j] > key) 
		{
			arr[j+1] = arr[j]; 
			j = j-1; 
		}
		arr[j+1] = key;
	}
}

//print array elements
void print(string arr[])
{
	cout << "\nSorted list of countries:\n";
	for(int x=0; x < SIZE; x++)
	{
		cout << arr[x] << "\n";
	}
	cout << endl;
}


bool binarySearch(string arr[],const int SIZE, string uC)
{
	int first = 0,
	last = SIZE - 1,
	middle,
	position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if(arr[middle] == uC)
		{
			found = true;
			position = middle;
		}
		else if (arr[middle] > uC)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return found;
}

bool linearSearch(string arr[], const int SIZE, string uC)
{
	int index = 0;
	int position = -1;
	bool found = false;

	while (index < SIZE && !found)
	{
		if (arr[index] == uC)
		{
			found = true;
			position = index;
		}
		index++;
	}
	return found;
}
