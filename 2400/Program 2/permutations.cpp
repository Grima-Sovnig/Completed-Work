/*
    File Name: permutations.cpp
    Author: Gabriel Snider
    Purpose: A program that generates permutations through Lexicographic Permute and Johnson-Trotter Algorithm.
    Date: 10-18-2021
*/

#include <iostream>
#include <cstdlib>
using namespace std;

//The First Algorithm will be the Johnson-Trotter Algorithm.

/*
    Function Name: johnMobile
    Input: The users string they want permutations of, and the array of arrows.
    Purpose: Finds the maximum mobile element in the array
    Returns: The index of the mobile element?
*/
int johnMobile(char userString[], bool arrows[])
{
    int maxMobile;
    char max = ' ';

    for(int i = 0; i < strlen(userString); i++)
    {
        if(arrows[i] == 0 && userString[i] > userString[i-1] && userString[i] > max && i > 0)
        {
            max = userString[i];
            maxMobile = i;
        }
        if(arrows[i] != 0 && userString[i] > userString[i+1] && userString[i] > max && i < strlen(userString) - 1)
        {
            max = userString[i];
            maxMobile = i;
        }
    }

    return maxMobile;
}
/*
    Function Name: johnFactorial
    Input: The users string they want permutations of.
    Purpose: Find the factorial of the number elements in the users input. This will give us the number of permutations.
    Returns: The result of the factorial.
*/
int johnFactorial(char userString[])
{
    int factorial = 1;
    for(int i = 1; i <= strlen(userString); i++)
    {
        factorial = factorial * i;
    }

    return factorial;
}
/*
    Function Name: johnPermutations
    Input: The users string they want permutations of.
    Purpose: Print the permutations that have been found using the Johnson-Trotter Algorithm.
    Returns: Nothing, but it does print the permutations to the screen.
*/
void johnPermutations(char userString[])
{

    enum arrow {LEFT = 0, RIGHT = 1};

    int size = strlen(userString);
    int k, temp;
    bool tempArrow;
    bool arrows[size] = {0};

    char initialize[size];
    for(int i = 0; i < strlen(userString); i++)
    {
        initialize[i] = userString[i];
    }

    cout << "Johnson-Trotter Algorithm" << endl;
    cout << 1 << ":     ";
    
    for(int i = 0; i < size; i++)
    {
        if(arrows[i] == LEFT)
        {
            cout << "<-";
        }
        else
        {
            cout << "->";
        }
    }
    
    cout << endl << "\t";

    for(int i = 0; i < size; i++)
    {
        cout << userString[i] << " ";
    }
    cout << endl << endl;

    for(int i = 1; i < johnFactorial(userString);)
    {
        k = johnMobile(userString, arrows);

        if(arrows[k] == LEFT && k > 0)
        {
            temp = userString[k-1];
            tempArrow = arrows[k-1];
            userString[k-1] = userString[k];
            arrows[k-1] = arrows[k];
            userString[k] = temp;
            arrows[k] = tempArrow;
            k--;
        }
        else if(arrows[k] == RIGHT && k < size - 1)
        {
            temp = userString[k+1];
            tempArrow = arrows[k+1];
            userString[k+1] = userString[k];
            arrows[k+1] = arrows[k];
            userString[k] = temp;
            arrows[k] = tempArrow;
            k++;
        }

        for(int i = 0; i < size; i++)
        {
            if(userString[i] > userString[k])
            {
                arrows[i] = !arrows[i];
            }
        }
        cout << i++ + 1 << ":     ";
        for(int i = 0; i < size; i++)
        {
            if(arrows[i] == LEFT)
            {
                cout << "<-";
            }
            else
            {
                cout << "->";
            }
        }

        cout << endl << "\t";

        for(int i = 0; i < size; i++)
        {
            cout << userString[i] << " ";
        }
        cout << endl << endl;
    }
    return;
}

//The Next Algorithm will be the Lexicographic Permute.

/*
    Function Name: lexicoCompare
    Purpose: This function is need to use the qsort. The qsort function is included in the cstdlib.
    Returns: Integer
*/
int lexicoCompare(const void *a, const void *b)
{
    return ( *(char *)a - *(char *)b );
}
/*
    Function Name: lexicoSwap
    Purpose: Swaps that location of two char. Uses a temp variable to do so.
    Returns: Nothing
*/
void lexicoSwap (char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
/*
    Function Name: lexicoFindSmallest
    Purpose: Finds the smallest index in the given array.
    Returns: The smallest index.
*/
int lexicoFindSmallest(char str[], char first, int l, int h)
{
    int smallestIndex = l;

    for(int i = l + 1; i <= h; i++)
    {
        if(str[i] > first && str[i] < str[smallestIndex])
        {
            smallestIndex = i;
        }
    }
    return smallestIndex;
}
/*
    Function Name: lexicoSortedPermutations
    Purpose: To sort the permutations and print them to the screen.
    Returns: Nothing, but it does cout the permutations to the screen in sorted order.
*/
void lexicoSortedPermutations(char str[])
{
    cout << "Lexicographic Algorithm" << endl;
    int arraySize = strlen(str);

    qsort(str, arraySize, sizeof(str[0]), lexicoCompare);

    
    bool completed = false;

    while(!completed)
    {
        
        
        int i;

        for(i = arraySize - 2; i >= 0; --i)
        if(str[i] < str[i+1])
        {
            break;
        }

        if(i == -1)
        {
            completed = true;
        }
        /* 
            Because I use the qsort(quicksort) function I am unable to get the output that is wanted.
            If I try to use a counter it does not increment because the qsort is only called the one time and not in a for loop for a set amount of times.
        */
        else
        {
            int smallestIndex = lexicoFindSmallest(str, str[i], i + 1, arraySize - 1);

            lexicoSwap(&str[i], &str[smallestIndex]);
            
            qsort(str + i + 1, arraySize - i - 1, sizeof(str[0]), lexicoCompare);

            cout << str << endl;
        }
    }
}
/*
    Function Name: Main
    Purpose: A driver for the program, calls other functions.
    Returns: 0
*/
int main()
{
    char userString[] = "";

    cout << "Enter a string to find its permutations: ";
    cin >> userString;
    cout << endl << endl;
    johnPermutations(userString);
    cout << endl << endl;
    lexicoSortedPermutations(userString);

    return 0;
}