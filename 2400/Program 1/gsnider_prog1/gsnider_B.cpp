/*   Name: Gabriel Snider
     File Name: gsnider_B.cpp
     Purpose: To use the Consecutive Integer Checking Algorithm to find the gcd of two given non-negative, non-zero integers
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
     //Here is the variable declaration, I use atoi on the command line arguments to convert from char to integers.
     int min = 0;
     int m = atoi (argv[1]);
     int n = atoi (argv[2]);
     //This is where I find which number is the smallest.
     if(m<n)
     {
          min = m;
     }
     else
     {
          min = n;
     }
     //This is the main loop of the code. It first checks to see if it is undefined. Then it will see if the gcd is already found and print it to the screen.
     //If the gcd is not found it will decrease the min and redo the calculation until the gcd is found.
     do
     {
          if(m <= 0 && n <= 0)
          {
               cout << "gcd is undefined." << endl;
               break;
          }
          if(m % min == 0 && n % min == 0)
          {
               cout << "gcd(" << argv[1] <<"," << argv[2] <<") is " << min << endl;
               break;
          }
          else
          {
               min = min - 1;
          }
     } while (min >= 0);
     
     
     
     return 0;
}