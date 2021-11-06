#include <iostream>
using namespace std;

int main()
{
    int customerED= 16500 * .15;
    int customerCitrus= customerED * .58;

    cout << "Num of people who drink more than one a week: " << customerED << endl;
    cout << "Num of people who drink more than one a week and prefer Citrus flavored: " << customerCitrus << endl;

    return 0;

}