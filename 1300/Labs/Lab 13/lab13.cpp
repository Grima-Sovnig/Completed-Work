#include <iostream>
#include <string>
using namespace std;

struct Player   {
    string name;
    string hometown;
    int age;
    int numGames;
};

int main()   {
    int numPlayers;
    int total;
    int largest=0;
    string largestP;
    int least=10000;
    string leastP;

    cout << "How many esports players are there at TTU who major in CSC? \n";
    cin >> numPlayers;
    Player info[numPlayers];
    int *hours[numPlayers];

    cout << "Please enter in information about each player: \n";

    for (int i=0; i<numPlayers; i++)   {
        total = 0;
        cout << "PLAYER: " << i+1 << ":";
        cout << "\n     NAME: ";
        cin.ignore();
        getline(cin, info[i].name);
        cout << "\n     HOMETOWN: ";
        cin.ignore();
        getline(cin, info[i].hometown);
        cout << "\n    AGE: ";
        cin >> info[i].age;
        cout << "\n     HOW MANY GAMES DOES " << info[i].name << " PLAY?    ";
        cin >> info[i].numGames;
        hours[i] = new int[info[i].numGames];
        for (int x=0; x<info[i].numGames; x++)   {
            cout << "\n         NUMBER OF HOURS " << info[i].name << " PLAYED GAME " << x+1 << "    ";
            cin >> hours[i][x];
            total += hours[i][x];
            if (total > largest)   {
                largest = total;
                largestP = info[i].name;
            }
            if (total < least)   {
                least = total;
                leastP = info[i].name;
            }
        }
    }
    cout << "\nThe player who played the most hours (" << largest << " hours) is " << largestP;
    cout << "\nThe playerv who played the least hours (" << least << " hours) is " << leastP;

    for (int i=0; i<numPlayers; i++)   {
        delete [] hours[i];
    }

    return 0;
}