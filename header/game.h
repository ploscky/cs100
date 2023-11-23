#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;


class Game {
private:
    vector<string> gameLog;

public:
    Game();
    void mainMenu();
    void printInstructions();
    void play();
    void printGameLog();
    bool isCheckmate();
    bool isStalemate();
    bool invalidInput();
    bool isLegalMove(char piece, char rankFile, const string& coordinates);
    bool inCheck();
    void saveGameLog(const string& fileName);
};
