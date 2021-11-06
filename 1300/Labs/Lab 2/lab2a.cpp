#include <iostream>
#include <iomanip>
using namespace std;
// Gabriel Snider, Chris Wilhite Lab 2 a
int main()
{
    double stock =750 *35;
    double commission =stock*0.02;
    double total = stock + commission;
    cout << setprecision(2) << fixed;
    cout << "Amount paid for the stock:$" << stock << endl;
    cout << "Commission paid on the sale:$" << commission << endl;
    cout << "Total amount paid for stock:$" << total << endl;

    return 0;




}