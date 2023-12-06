#pragma once

#include "board.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;


class Game {
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



public: // private: for testing purposes
    bool isCheckmate();
    bool isStalemate(bool isWhiteTurn);
    bool isLegalMove(bool, string); // (white's turn, input)
    bool inCheck();
};