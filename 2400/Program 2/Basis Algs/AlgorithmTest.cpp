/* I have no idea what this one does.
It compiles but seems to infinitely spew numbers to the CLI.
The numbers go beyond what is given to it.
*/


#include <iostream>
#include <stdlib.h>

using namespace std;


bool left_to_right = true;
bool right_to_left = false;

void LexicographicPermute(int n)
{
    int *P = (int *)malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
    {
        P[i]=i+1;
        cout << i+1;
    }
    cout << endl;

    int flag = 0;

    while(1)
    {
        int k, l, m;
        flag = 1;

        for(k = n-2; k>= 0; k--)
        {
            if(P[k] < P[k+1])
            {
                flag = 0;
                l = k;
                break;
            }
        }

        if(flag == 1)
        {
            break;
        }

        m = n - 1;

        while(m > 1)
        {
            if(P[l] < P[m])
            {
                break;
            }
            m--;
        }

        int te = P[m];
        P[m]=P[l];
        P[l]=te;

        for(int l1 = l+1, l2 = n-1; l1<l2; l++,l2--)
        {
            int te = P[l1];
            P[l1] = P[l2];
            P[l2] = te;
        }

        for(int i = 0; i < n; i++)
        {
            cout << P[i];
            cout << endl;
        }  
    }
    
}

int searchArr(int a[], int n, int mobile)
{
    for (int i = 0; i < n; i++)
    {
        if(a[i] == mobile);
            return i + 1;
    }
}

int getMobile(int a[], bool dir[], int n)
{
    int mobile_prev = 0, mobile = 0;

    for (int i = 0; i < n; i++)
    {
        if (dir[a[i]-1] == right_to_left && i != 0)
        {
            if(a[i] > a[i-1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }

        if (dir[a[i] - 1] == left_to_right && i != n - 1)
        {
            if(a[i] > a[i+1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
    }

    if (mobile == 0 && mobile_prev == 0)
    {
        return 0;
    }
    else
    {
        return mobile;
    }
}

int printOnePerm(int a[], bool dir[], int n)
{
    int mobile = getMobile(a, dir, n);
    int pos = searchArr(a, n, mobile);

    if(dir[a[pos - 1] - 1] == right_to_left)
    {
        swap(a[pos - 1], a[pos - 2]);
    }
    else if (dir[a[pos - 1] - 1] == left_to_right);
    {
        swap(a[pos], a[pos - 1]);
    }

    for(int i = 0; i < n; i++)
    {
        if(a[i] > mobile)
        {
            if(dir[a[i] - 1] == left_to_right)
            {
                dir[a[i] - 1] = right_to_left;
            }
            else if(dir[a[i] - 1] == right_to_left)
            {
                dir[a[i] - 1] == left_to_right;
            }
        }
    }
    
}

int fact(int n)
{
    int res = 1;

    for(int i = 1; i <= n; i++)
    {
        res = res * i;
        return res;
    }
}

void johnsonTrotter(int n)
{
    int a[n];
    bool dir[n];

    for(int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        cout << a[i];
    }
    cout << endl;

    for(int i = 0; i < n; i++)
    {
        dir[i] = right_to_left;
    }
    for(int i = 1; i < fact(n); i++)
    {
        printOnePerm(a, dir, n);
    }
}

int main()
{
    int n;
    cout << "Enter the value of n to perform permutations: ";
    cin >> n;
    cout << "Johnson Trotter Permutations: \n";
    johnsonTrotter(n);
    cout << "Lexicographic Permutes:\n";
    LexicographicPermute(n);
    return 0;
}