#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
    string cFault = "\033[39m";
    cout<<cFault;
    cout<<"Welcome to MasterMind!"<<endl;
    string answer;
    Board *myBoard = new Board;
    myBoard->createCode();
    int numTries = 0;
    while (numTries < 10)
    {
        cout<<"Enter your guess code: ";
        getline(cin, answer);
        if (answer.size() != 4)
            cout<<"Enter a correct input."<<endl;
        else
        {
            // validates input before running game code
            bool inputPassed;
            inputPassed = myBoard->validateInput(answer);
            if (inputPassed) {
                cout<<endl;
                myBoard->assignColors(answer);
                myBoard->viewGame();
                if (myBoard->allGuesses[numTries]->correctColorandPosition == 4)
                    break;
                numTries++;
            }
            else {
                cout << "Please enter a valid guess. Your guess must be 4 characters and only include the characters r, b, g, y, c, p." << endl;
            }
        }
    }
    if (numTries == 10)
        cout<<"Sorry, you lost."<<endl;
    else
        cout<<"Congratulations you win!"<<endl;
    return 0;
}
