/*
    Author: Gabriel Snider
    Title: Lab 2 
    Date: 8/31/2020
    Purpose: Program to Inventory Friends
*/

#include <iostream>
using namespace std;

struct Friends
{
    string Name;
    string Birthday;
    int Age;
    string Description;

};

void sortFriends(Friends* friendArray, int FriendCount)
{
    int lowest;
    Friends temp;
    cout << "\n\nSorting your friends!\n\n";
    for (int i=0; i < FriendCount; i++)
    {
        //find next lowest name (alphabetically)
        lowest = i;
        for (int x=i; x < FriendCount; x++)
            if(friendArray[x].Name < friendArray[lowest].Name)
                lowest = x;
        //swap
        temp = friendArray[lowest];
        friendArray[lowest] = friendArray[i];
        friendArray[i] = temp;

    }
}

void printFriends(Friends* freindArray, int FriendCount)
{
    for (int i=0; i < FriendCount; i++)
    {
        cout << "Friend " << i+1 << endl;
        cout << "Name: " << freindArray[i].Name << endl;
        cout << "Birthday: " <<freindArray[i].Birthday << endl;
        cout << "Age: " << freindArray[i].Age << endl;
        cout << "Description: " << freindArray[i].Description << endl;
    }
}

void enterFriends(Friends* friendArray, int FriendCount)
{
    cout << "Enter your friends's information!" << endl;
    for (int i=0; i < FriendCount; i++)
    {
    
        cout << "Friend " << i+1 << endl;
        cout << "Name: ";
        getline(cin,friendArray[i].Name);
        cout <<"\nBirthday: ";
        getline(cin, friendArray[i].Birthday);
        cout <<"\nAge: ";
        cin >> friendArray[i].Age;
        cin.ignore(); // to let cursor go to next line after scanning interger
        cout <<"\nDescription: ";
        getline(cin,friendArray[i].Description);
        

    }

}


int main()
{
    int FriendCount;
    int userChoice;
    cout << "How many friends do you have?" << endl;
    cin >> FriendCount;

    Friends* friendArray;
    friendArray = new Friends[FriendCount];
    do
    {
    cout << "Choose from the following options:" << endl;
    cout << "1. Enter Friends" << endl;
    cout << "2. Print Friends" << endl;
    cout << "3. End Program" << endl;
    cout << "Choose 1-3: ";
    cin >> userChoice;
    cin.ignore();

    if (userChoice < 1 || userChoice > 3)
    {
        cout << "Please enter a number 1-3: ";
        cin >> userChoice;
        cin.ignore();
    }
    if (userChoice == 1)
    {
        enterFriends(friendArray, FriendCount);
    }
    else if (userChoice == 2)
    {
        sortFriends(friendArray, FriendCount);
        printFriends(friendArray, FriendCount);
    }
    }while(userChoice != 3);
    
    cout << "Thanks for using my friend program!!";
    delete[] friendArray;
    return 0;

}