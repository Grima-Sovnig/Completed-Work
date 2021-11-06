#include <iostream>
#include <string>
using namespace std;
// Gabriel Snider, and Rachel Kurtsinger
int main()
{
    int userInt= 0;
    double userDouble= 0;
    char userChar;
    string userString;

    cout <<"Please enter a Integer:" << endl;
    cin >> userInt;
    cout <<"Please enter a Double:" << endl;
    cin >> userDouble;
    cout <<"Please enter a Character:" << endl;
    cin >> userChar;
    cout <<"Please enter a String:" << endl;
    cin >> userString;

    cout << userInt <<"  " << userDouble  << "  "<< userChar << "  "<< userString << endl;
    cout << userString <<"  " << userChar<< "  " << userDouble<< "  " << userInt << endl;
    cout << userDouble << "  cast to an integer is  " << (int) userDouble << endl;











}