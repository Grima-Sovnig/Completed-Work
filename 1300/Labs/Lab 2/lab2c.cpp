#include <iostream>
using namespace std;

int main ()
{
    string fn1;
    string fn2;
    string ln1;
    string ln2;

    cout << "What is the first person's first name?\n";
    cin >> fn1;
    cout << "What is the first person's last name?\n";
    cin >> ln1;
    cout << "What is the second person's first name:\n";
    cin >> fn2;
    cout << "What is the second person's last name?\n";
    cin >> ln2;

    cout << "Here are some common married-couple names:\n";
    cout << fn1+ " " + ln1+ " " + "and "+ fn2 + " " + ln2 << endl;
    cout << fn1+ " and " + fn2+ " " +ln1 << endl;
    cout << fn1+ " and " + fn2+ " " +ln2 << endl;
    cout << fn1 + " " + ln1 + " and " + fn2 + " " + ln1 + "-" + ln2 + "\n";
    cout << fn1 + " " + ln1 + " and " + fn2 + " " + ln2 + "-" + ln1 + "\n";


    
    
    
    

return 0;

}