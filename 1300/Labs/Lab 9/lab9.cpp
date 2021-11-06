//Gabriel Snider
#include <iostream>

using namespace std;

const int SIZE = 4;

int main()
{
int*numBooksArray[SIZE];
int numGenres;
int largestBooks;
int largestLibrary;
int largestGenre;


cout << "How many genres of books do you have?" << endl;
cin >> numGenres;
cout << "\n PLease enter the number of books in each genre." << endl;

for (int i=0; i < SIZE; i++)
{
    numBooksArray[i] = new int [numGenres];
    for (int x=0; x<numGenres; x++)
    {
        cout <<"LIBRARY " << i+1 <<"  GENRE "<< x+1 << ":   ";
        cin >> numBooksArray[i][x];
    }
}

for (int i=0; i < SIZE; i++)
{
    for(int x=0; x < numGenres; x++)
    {
       if (numBooksArray[i][x] > largestBooks)
       {
           largestLibrary = i+1;
           largestGenre = x+1;
           largestBooks = numBooksArray[i][x];
       }
    }
}

cout <<"LIBRARY " << largestLibrary << " has the largest number of books in GENRE " << largestGenre <<" which contains " << largestBooks <<" books!";



return 0;
}