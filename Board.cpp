#include "Board.h"
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

Board::Board()
{
    for (int x = 0; x < 10; x++)
    {
        allGuesses[x] = NULL;
    }
    CodenumBlue = 0;
    CodenumRed = 0;
    CodenumCyan = 0;
    CodenumGreen = 0;
    CodenumPink = 0;
    CodenumYell = 0;
}

Board::~Board()
{
    //dtor
}

/*
Method: createCode
Description: This is the method that randomnly generates a code by using a random number to use as the index in the color string array found in Board.h
*/

void Board::createCode()
{
    std::string color;
    srand((int) time(0));
    for (int x = 0; x < 4; x++)
    {
        int randNum = rand()%5;
        color = colorList[randNum];
        code.push_back(color);
    }
    for (int x = 0; x < 4; x++)
    {
        if (code[x] == "Red")
            CodenumRed++;
        else if (code[x] == "Blue")
            CodenumBlue++;
        else if (code[x] == "Green")
            CodenumGreen++;
        else if (code[x] == "Cyan")
            CodenumCyan++;
        else if (code[x] == "Yellow")
            CodenumYell++;
        else if (code[x] == "Pink")
            CodenumPink++;
    }
    colorCode();
}

/*
Method: assignColors
Description: This is the method that colors the user's guess code by adding substrings of values that give text color.
*/

void Board::assignColors(std::string x)
{
    std::cout<<x<<std::endl;
    guess *temp = new guess;
    std::string hold;
    if (x.size() == 4)
    {
        for (int i = 0; i < x.size(); i++)
        {
            hold = "";
            if (x[i] == 'r')
            {
                hold = cRed + "Red" + cDefault;
                temp->userColors.push_back(hold);
            }
            else if (x[i] == 'b')
            {
                hold = cBlue + "Blue" + cDefault;
                temp->userColors.push_back(hold);
            }
            else if (x[i] == 'g')
            {
                hold = cGreen + "Green" + cDefault;
                temp->userColors.push_back(hold);
            }
            else if (x[i] == 'y')
            {
                hold = cYellow + "Yellow" + cDefault;
                temp->userColors.push_back(hold);
            }
            else if (x[i] == 'c')
            {
                hold = cCyan + "Cyan" + cDefault;
                temp->userColors.push_back(hold);
            }
            else if (x[i] == 'p')
            {
                hold = cPink + "Pink" + cDefault;
                temp->userColors.push_back(hold);
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (allGuesses[i] == NULL)
        {
            allGuesses[i] = temp;
            break;
        }
    }
}

/*
Method: colorCode
Description: This is the function that gives the code text color by adding substrings of values that give text color (Found in Board.h)
*/

void Board::colorCode()
{
    for (int x = 0; x < 4; x++)
    {
        if (code[x] == "Red")
            code[x] = cRed + code[x] + cDefault;
        else if (code[x] == "Blue")
            code[x] = cBlue + code[x] + cDefault;
        else if (code[x] == "Yellow")
            code[x] = cYellow + code[x] + cDefault;
        else if (code[x] == "Green")
            code[x] = cGreen + code[x] + cDefault;
        else if (code[x] == "Cyan")
            code[x] = cCyan + code[x] + cDefault;
        else if (code[x] == "Pink")
            code[x] = cPink + code[x] + cDefault;
    }
}

/*
Method: viewGame
Description: Shows all guesses with corresponding number of correct colors and correct colors in the right position
*/

void Board::viewGame()
{
    int numAdded = 0;
    for (int j = 0; j < 10; j++)
    {
        if (allGuesses[j] != NULL)
            numAdded++;
    }
    for (int x = 0; x < numAdded; x++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i == 0)
                std::cout<<allGuesses[x]->userColors[i];
            else
            {
                std::cout<<","<<allGuesses[x]->userColors[i];
            }
        }
        checkCombo(allGuesses[x]);
        std::cout<<" || Correct Col: "<<allGuesses[x]->correctColor<<" Correct ColPos: "<<allGuesses[x]->correctColorandPosition<<std::endl;
    }
    /*
    for (int a = 0; a < 4; a++)
    {
        std::cout<<code[a]<<std::endl;
    }
    */
}

/*
Method: checkCombo
Description: Checks a given combo against the code combo
*/

void Board::checkCombo(guess *combo)
{
    correctCol = 0;
    correctColPos = 0;
    int numAdded = 0;
    for (int j = 0; j < 10; j++)
    {
        if (allGuesses[j] != NULL)
            numAdded++;
    }
    for (int x = 0; x < numAdded; x++)
    {
        correctCol = 0;
        correctColPos = 0;
        for (int i = 0; i < 4; i++)
        {
            if (allGuesses[x]->userColors[i] == code[i])
                correctColPos++;
        }
        int counterR = 0;
        int counterB = 0;
        int counterG = 0;
        int counterC = 0;
        int counterY = 0;
        int counterP = 0;
        for (int b = 0; b < 4; b++)
        {
            if (allGuesses[x]->userColors[b].find("Red") != std::string::npos && counterR <= UsernumRed && CodenumRed > 0)
                counterR++;
            else if (allGuesses[x]->userColors[b].find("Blue") != std::string::npos && counterB <= UsernumBlue && CodenumBlue > 0)
                counterB++;
            else if (allGuesses[x]->userColors[b].find("Green") != std::string::npos && counterG <= UsernumGreen && CodenumGreen > 0)
                counterG;
            else if (allGuesses[x]->userColors[b].find("Cyan") != std::string::npos && counterC <= UsernumCyan && CodenumCyan > 0)
                counterC++;
            else if (allGuesses[x]->userColors[b].find("Yellow") != std::string::npos && counterY <= UsernumYell && CodenumYell > 0)
                counterY++;
            else if (allGuesses[x]->userColors[b].find("Pink") != std::string::npos && counterP <= UsernumPink && CodenumPink > 0)
                counterP++;
        }
        correctCol = counterB + counterC + counterR + counterG + counterY + counterP;
        allGuesses[x]->correctColorandPosition = correctColPos;
        correctCol = correctCol - correctColPos;
        if (correctCol < 0)
            correctCol = 0;
        allGuesses[x]->correctColor = correctCol;
    }
}

/*Method: colorCounter
Description: counts the number of each color in a given combination
*/

void Board::colorCounter(guess *combo)
{
    int numAdded = 0;
    UsernumBlue = 0;
    UsernumCyan = 0;
    UsernumGreen = 0;
    UsernumPink = 0;
    UsernumRed = 0;
    UsernumYell = 0;
    for (int j = 0; j < 10; j++)
    {
        if (allGuesses[j] != NULL)
            numAdded++;
    }
    for (int x = 0; x < numAdded; x++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (allGuesses[x]->userColors[i].find("Red") >= 0)
                UsernumRed++;
            else if(allGuesses[x]->userColors[i].find("Blue") >= 0)
                UsernumBlue++;
            else if (allGuesses[x]->userColors[i].find("Cyan") >= 0)
                UsernumCyan++;
            else if (allGuesses[x]->userColors[i].find("Green") >= 0)
                UsernumGreen++;
            else if (allGuesses[x]->userColors[i].find("Pink") >= 0)
                UsernumPink++;
            else if (allGuesses[x]->userColors[i].find("Yellow"))
                UsernumYell++;
        }
    }
}

/*
Method: validateInput
Description: This function checks to make sure that only correct characters are entered. If correct it will run the game code, otherwise it asks the user to enter correct input.
Pre-conditions: User enters their guess
Post-conditions: Game either runs using the input, or throws an error if input is incorrect
*/
bool Board::validateInput(std::string guess) {
    bool correctInput = true;
    std::string validInput = "rbgycp";
    for (int i = 0; i < guess.size(); i++) { // loop through chars in string
        if (validInput.find(guess[i]) == std::string::npos) { // if it's not the valid input string
            correctInput = false;
        }
    }
    return correctInput;
}


