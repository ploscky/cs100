#pragma once

#include "board.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;


class Game {
private:
    Board *game;
    vector<string> gameLog;
    string current_player;

public:
    Game();
    ~Game();
    void mainMenu();
    void printInstructions();
    void play();
    void printGameLog();
    void saveGameLog(const string& fileName);
    string getOriginal(char piece, char file, char rank);

public: // private: for testing purposes
    bool isCheckmate();
    bool isStalemate();
    bool isLegalMove(bool, string); // (white's turn, input)
    bool inCheck();
};