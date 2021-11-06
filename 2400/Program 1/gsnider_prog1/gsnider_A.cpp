/*   Name: Gabriel Snider
     File Name: gsnider_A.cpp
     Purpose: To use Euclid's Algorithm to find the gcd of two given non-negative, non-zero integers
*/
#include <iostream>
#include <cstdlib>
using namespace std;
int euclidsAlgorithm(int, int);
// This is the main function of the program, it will take in the command line arguments and then pass them to the euclids algorithm function.
int main(int argc, char* argv[])
{
     int gcd = 0;
     //I use atoi to convert the command line arguments into integers so that they can be passed to the euclidsAlgorithm function.
     int m = atoi (argv[1]);
     int n = atoi(argv[2]);
     
     //This first if statement checks to see if the gcd is undefined.
     if(m <= 0 && n <= 0)
     {
          cout << "gcd is undefined." << endl;
     }
     else
     {
          //Here I set the gcd equal to what the euclidsAlgorithm returns.
          gcd = euclidsAlgorithm(m,n);
          //This is where the final answer is printed.
          cout << "gcd(" << argv[1] <<"," << argv[2] <<") is " << gcd << endl;
     }
}
//This is the function that I am using to implement Euclids Algorithm. It will recursively find the gcd if necessary.
int euclidsAlgorithm(int m, int n)
{
     if(n == 0)
     {
          return m;
     }
     else
     {
          return euclidsAlgorithm(n, m % n);
     }
}
