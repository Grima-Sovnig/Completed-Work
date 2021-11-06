#include <iostream>
#include <cmath>
using namespace std;
// Gabriel Snider and Rachel Kurtsinger
int main()
{
    const double GALLONPAINT=350;
    double wallHeight= 0;
    double wallWidth= 0;
    double wallArea=0;
    double paintNeeded=0;
    double cansNeeded= 0;


    cout <<"Enter wall height (feet):" << endl;
    cin >> wallHeight;
    cout <<"Enter wall width (feet):" << endl;
    cin >> wallWidth;

    wallArea= wallHeight * wallWidth;
    cout <<"Wall area: "<< wallArea <<" square feet" << endl;
    paintNeeded= wallArea / GALLONPAINT;
    cout <<"Paint needed: " << paintNeeded << " gallons"<< endl;
    cansNeeded= ceil(paintNeeded);
    cout <<"Cans needed: " << cansNeeded << " can(s)" << endl;



    





}