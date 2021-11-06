// Gabriel Snider and David Gregory

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    char gamePlay;
    int randomNum;
    int userGuess;
    int totalGuess=1;
    
    srand(time(0));
    do {
        randomNum= rand()%100+1;
        cout << "Guess a random number between 1 - 100." << endl;
        cout << randomNum << endl;
        cin >> userGuess;
        while (userGuess > 100 || userGuess < 1)
        {
            cout << "Enter a number between 1-100." << endl;
            cin >> userGuess;
        }
        do {
        if (userGuess > randomNum)
        {
            cout << "Number is too high, try a lower guess." << endl;
            cin >> userGuess;
            totalGuess++;
        }
        else if (userGuess < randomNum)
        {
            cout << "Number is too low, try a higher guess." << endl;
            cin >> userGuess;
            totalGuess++;
        }
        
        }while(userGuess != randomNum);
            cout << "You got the number correct. It took this many guesses: " << totalGuess << endl;
            cout << "Would you like to play again? (y or n) "<< endl;
            cin >> gamePlay;
            while(gamePlay != 'y' && gamePlay != 'n')
            {
                cout <<"Enter either y to play again or n to quit." << endl;
                cin >> gamePlay;
            }
            
        
    } while(gamePlay=='y');
        

    

}
