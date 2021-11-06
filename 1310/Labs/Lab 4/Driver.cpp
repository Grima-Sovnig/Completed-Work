#include "Song.h"
#include "Timer.h"
#include <iostream>
#include <fstream>
using namespace std;

//LOOK!!  ENTER YOUR FUNCTION PROTOTYPES HERE
void insertionSort(Song*, int);
void reverseBubbleSort(Song*, int);
void quickSort(Song*,int, int);
int partition(Song*, int, int);

int main()
{
	Song *mySongArray;
	mySongArray = new Song[150000];
	int numSongs = 0;
	float length;
	string temp;
	
	ofstream outFile;
	ifstream inFile;

	time_t start, end;
	char filename[50];
	cout << "\n\nWhat is the name of the file with songs? (example.txt)\n";
	cin >> filename;
	inFile.open(filename);
	
	if(!inFile)
	{
		cout << "\n\nSorry, I can't open the file songs.txt\n\n";
		exit(1);
	}
	
	while(getline(inFile, temp) && numSongs != 150000)
	{
		mySongArray[numSongs].setTitle(temp);
		getline(inFile, temp);
		mySongArray[numSongs].setArtist(temp);
		inFile >> length;
		inFile.ignore();
		mySongArray[numSongs].setLength(length);
		numSongs++;
	}
	cout << "\n\nYou have created " << numSongs << " Song objects.\n\n";
	
	
	
	//sort the songs using insertion sort and print them out to the text file sortFileInsertion.txt
	start = getTime(); //Starts timer.   
	
	//LOOK!!!!  CALL THE INSERTION SORT ALGORITHM HERE
	insertionSort(mySongArray,numSongs);
	
	end = getTime(); //Ends timer.
	outFile.open("sortFileInsertion.txt");
	cout << "\nInsertion sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	
	//sort the songs in reverse order using bubble sort & print them out to the text file sortFileReverseBubble.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE REVERSE BUBBLE SORT ALGORITHM HERE
	reverseBubbleSort(mySongArray, numSongs);
	
	end = getTime(); //Ends timer.
	outFile.open("sortFileReverseBubble.txt");
	cout << "\nReverse bubble sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	
	//sort the songs with quick sort & print them out to sortFileQuick.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE QUICKSORT ALGORITHM HERE
	quickSort(mySongArray, 0, numSongs);
	
	end = getTime(); //Ends timer.
	cout << "\nQuicksort: " << totalTime(start, end) << " seconds\n\n";
	outFile.open("sortFileQuick.txt");
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	delete [] mySongArray;
	return 0;
}

//LOOK!  WRITE YOUR INSERTION SORT FUNCTION HERE
void insertionSort(Song *arr, int size)
{
	Song temp;
	string jTitle, iTitle;
	int j;

	for(int i=1; i<size; i++)
	{
		temp = arr[i];
		j = i-1;
		jTitle = arr[j].getTitle();
		iTitle = arr[i].getTitle();
		while(j>= 0 && jTitle > iTitle)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = temp;
	}
}


//LOOK!  WRITE YOUR REVERSE BUBBLE SORT FUNCTION HERE
void reverseBubbleSort(Song *arr, int size)
{
	Song tempSwap;
	string high, low;

	for (int maxElemenet = (size-1); maxElemenet > 0; maxElemenet --)
	{
		for(int i = 0; i < maxElemenet; i++)
		{
			high = arr[i].getTitle();
			low = arr[i+1].getTitle();
			if(high < low)
			{
				tempSwap = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tempSwap;
			}
		}
	}
}


//LOOK!  WRITE YOUR RECURSIVE QUICK SORT FUNCTION HERE
void quickSort(Song *arr, int low, int high)
{
	int pivot_location = 0;
	if(low>= high)
	{
		return;
	}
	pivot_location = partition(arr,low,high);
	quickSort(arr,low,pivot_location);
	quickSort(arr,pivot_location + 1, high);
}
//LOOK!  WRITE YOUR PARTITION FUNCTION HERE
int partition(Song *arr, int left, int right)
{
	string pivot, lTitle, rTitle, temp;
	int middle;
	bool done = false;
	middle = left + (right-left) / 2;
	pivot = arr[middle].getTitle();
	int l = left;
	int r = right;

	lTitle = arr[l].getTitle();
	rTitle = arr[r].getTitle();
	while(!done)
	{
		while(lTitle < pivot)   
		{
		   ++l;
		   lTitle = arr[l].getTitle();
		}
		while(pivot < rTitle)   
		{
		   --r;
		   rTitle = arr[r].getTitle();
		}
		if(l >= r)
			done = true;
		else
		{
			temp = arr[l].getTitle();
			arr[l].setTitle(rTitle);
			arr[r].setTitle(temp);
			++l;
			--r;
		}
	}
	return r;
}
