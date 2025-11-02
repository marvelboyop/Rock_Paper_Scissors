#include <iostream>
#include <cstdlib> //For rand() and srand()
#include <ctime>   // For time()
#include <limits>  // for numeric_limits

using namespace std;

int main()
{
    // Variables + Seeding Randomness
    int PlayerInput, CompInput;
    int wins = 0, losses = 0, draws = 0;
    char playAgain;
    srand(time(0));

    cout << "------------Welcome to Rock, Paper & Scissors-------------\n";
    // The Game Loop : The big do while loop
    do
    {
        cout << "\nPress 1 for ROCK, Press 2 for PAPER, Press 3 for SCISSORS : ";

        // Input Validation Block
        while (!(cin >> PlayerInput) || PlayerInput < 1 || PlayerInput > 3)
        {
            cout << "INVALID INPUT!!! Please enter 1, 2, or 3: ";
            cin.clear();                                         // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        }
        // Random Computer Choice
        CompInput = rand() % 3 + 1;

        // Outcome Logic Version1 : else if logic for every possibbility

        // if (PlayerInput == 1 && CompInput == 2)
        //     cout << "You : ROCK \nComp : PAPER \nYou LOSE :(";
        // else if (PlayerInput == 2 && CompInput == 3)
        //     cout << "You : PAPER \nComp : SCISSORS\nYou LOSE :(";
        // else if (PlayerInput == 3 && CompInput == 1)
        //     cout << "You : SCISSORS \nComp : ROCK \nYou LOSE :(";

        // else if (PlayerInput == CompInput)
        //     cout << "This Match is Draw.";

        // else if (PlayerInput == 2 && CompInput == 1)
        //     cout << "You : PAPER \nComp : ROCK \nYou Win :) ";
        // else if (PlayerInput == 3 && CompInput == 2)
        //     cout << "You : SCISSORS \nComp : PAPER \nYou Win :) ";
        // else if (PlayerInput == 1 && CompInput == 3)
        //     cout << "You : ROCK \nComp : SCISSORS \nYou Win :) ";

        cout << "You chose: " << (PlayerInput == 1 ? "ROCK" : PlayerInput == 2 ? "PAPER"
                                                                               : "SCISSORS")
             << endl;
        cout << "Computer chose: " << (CompInput == 1 ? "ROCK" : CompInput == 2 ? "PAPER"
                                                                                : "SCISSORS")
             << endl;

        // Outcome Logic Version2 : Logically set the outcome in less instructions
        if (PlayerInput == CompInput)
        {
            cout << "Result: It's a DRAW!\n";
            draws++;
        }
        else if ((PlayerInput == 1 && CompInput == 3) || (PlayerInput == 2 && CompInput == 1) || (PlayerInput == 3 && CompInput == 2))
        {
            cout << "Result: You WIN! :)\n";
            wins++;
        }
        else
        {
            cout << "Result: You LOSE! :(\n";
            losses++;
        }

        // Score Tracking
        cout << "\nCurrent Score -> Wins: " << wins << " | Losses: " << losses << " |Draws: " << draws << endl;

        // Replay Option
        cout << "Play again(y/n): ";
        cin >> playAgain;

        // Replay Option Validation
        while (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N')
        {
            cout << "INVALID INPUT! Please enter 'y or 'n': ";
            cin >> playAgain;
        }
        cout << "\n---------------------------------------------------------\n";
    } while (playAgain == 'y' || playAgain == 'Y');

    // Game Summary
    cout << "\nFinal Score Summary:\n";
    cout << "Wins: " << wins << "\nLosses: " << losses << "\nDraws: " << draws << endl;
    cout << "Thanks for Playing!!!\n";
    return 0;
}