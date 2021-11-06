#include <iostream>
#include <iomanip>
using namespace std;
// Gabriel Snider and David Gregory

int main()
{

    float caffeineAmount;
    float caffeineSix;
    float caffeineTwelve;
    float caffeineEighteen;
    cout << "Enter a caffeine amount:" << endl;
    cin >> caffeineAmount;


    
    while(caffeineAmount < 0)
    {
        cout <<"Enter a valid number greater than zero." << endl;
        cin >> caffeineAmount;
    }

    caffeineSix=caffeineAmount/2;
    caffeineTwelve=caffeineSix/2;
    caffeineEighteen=caffeineAmount/8;

    cout << setprecision(2) << fixed;

    cout << "After 6 hours: " << caffeineSix <<" mg" << endl << endl;
    cout << "After 12 hours: " << caffeineTwelve <<" mg" << endl << endl;
    cout << "After 18 hours: " << caffeineEighteen << " mg" << endl << endl;








}