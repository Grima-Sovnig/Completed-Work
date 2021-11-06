#include <iostream>
using namespace std;
//Gabriel Snider and David Gregory
int main()
{
    int userChoice;
    cout <<"What month is it?" << endl;
    cout <<"1.January" << endl;
    cout <<"2.February" << endl;
    cout <<"3.March" << endl;
    cout <<"4.April" << endl;
    cout <<"5.May" << endl;
    cout <<"6.June" << endl;
    cout <<"7.July" << endl;
    cout <<'8.August' << endl;
    cout <<"9.September" << endl;
    cout <<"10.October" << endl;
    cout <<"11.November" << endl;
    cout <<"12.December" << endl;
    cout <<"Choose 1-12:" << endl;
    cin >> userChoice;
    
    while(userChoice<1||userChoice>12)
    {
        cout <<"You did not enter a valid number.";
        break;
    }

    switch(userChoice)
    {
        case 1:
        case 2:
        case 12:
            cout <<"It is winter!";
            break;
        case 3:
        case 4:
        case 5:
            cout <<"It is spring!";
            break;
        case 6:
        case 7:
        case 8:
            cout <<"It is summer!";
            break;
        case 9:
        case 10:
        case 11:
            cout <<"It is fall, which is the best time of the year!";
            break;
        default:
            cout <<"He did you get here";
            break;

    





    }







}