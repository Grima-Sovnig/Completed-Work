#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int main()
{
    ifstream file1, file2;
    string fname1, fname2;
    char fileChar, a, b , c;
    queue <char> queue1;
    queue <char> queue2;
    bool match = false;

    cout << "\n Please enter the first file name: ";
    cin >> fname1;
    cout << "\n Please enter the second file name: ";
    cin >> fname2;
    file1.open(fname1, ios::in);
    file2.open(fname2, ios::in);
    while(!file1.eof())
    {
        file1.get(fileChar);
        queue1.push(fileChar);
    }
    file1.close();
    while(!file2.eof())
    {
        file2.get(fileChar);
        queue2.push(fileChar);
    }
    file2.close();
    while(!queue1.empty() && !queue2.empty());
    {
        a = queue1.front();
        b = queue2.front();
        if (a != b)
        {
            match = true;
        }
        queue1.pop();
        queue2.pop();
    }
    if(match)
    {
        cout << "\nThe files are not identical.";
    }
    else
    {
        cout << "\n The files are identical.";
    }
    
}