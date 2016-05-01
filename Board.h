#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>

struct ball
{
    ball *next;
    ball *previous;
    int position;
    std::string color;
};

struct guess
{
    std::vector<std::string> userColors;
    int correctColor;
    int correctColorandPosition;
};

class Board
{
    public:
        Board();
        ~Board();
        void createCode();
        void colorCounter(guess*);
        void assignColors(std::string x);
        void viewGame();
        bool validateInput(std::string guess);
        int correctCol;
        int correctColPos;
        guess* allGuesses[10];
        std::string cRed = "\033[01;31m";
        std::string cBlue = "\033[01;34m";
        std::string cGreen = "\033[01;32m";
        std::string cYellow = "\033[01;33m";
        std::string cCyan = "\033[01;36m";
        std::string cPink = "\033[01;35m";
        std::string cDefault = "\033[0m";

    protected:
    private:
        void colorCode();
        ball *root;
        std::string colorList[6] = {"Red", "Blue", "Green", "Yellow", "Cyan", "Pink"};
        std::vector<std::string> code;
        int CodenumBlue;
        int CodenumRed;
        int CodenumYell;
        int CodenumGreen;
        int CodenumCyan;
        int CodenumPink;
        int UsernumBlue;
        int UsernumRed;
        int UsernumYell;
        int UsernumGreen;
        int UsernumCyan;
        int UsernumPink;
        void checkCombo(guess *combo);


};

#endif // BOARD_H
