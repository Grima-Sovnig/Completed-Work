#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

void swap(char *x, char *y)
{
    char temp;
    *x = *y;
    *y = temp;
}

void JohnsonTrotter(char *a, int l, int r)
{
    int i;
    if( l == r)
    {
        printf("%s\n", a);
    }
    else
    {
        for(i = l; i <= r; i++)
        {
            swap((a+l),(a+i));
            JohnsonTrotter(a, l+1, r);
            swap((a+l), (a+i));
        }
    }
}

int main()
{
    char str[] = "ABC";
    cout << endl << endl;
    int n = strlen(str);
    JohnsonTrotter(str, 0, n-1);
    return 0;

    
}