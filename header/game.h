#pragma once

#include "board.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;


class Game 
{
    public:
        Board *game;
        vector<string> gameLog;

    public:
        Game();
        ~Game();
        void mainMenu();
        void printInstructions();
        void play();
        void printGameLog();
        void saveGameLog(const string& fileName);

    private:
        string movingPieceCoordinates(bool, string); // (white's turn, input)
        bool isCheckmate(bool); // (white's turn)
        bool isStalemate(bool); // (white's turn)
        bool isLegalMove(bool, string); // (white's turn, input)
        bool inCheck(bool); // (white's turn)
        void undoLastMove();
};
