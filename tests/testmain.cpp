#include "../header/game.h"
#include <iostream>

using namespace std;

int main() {
    // Create a Game object
    Game chessGame;


    // Display the main menu
    chessGame.mainMenu();

   
    cout << "Printing game log:\n";
    chessGame.printGameLog();

    // doesnt work
    chessGame.saveGameLog("game_log.txt");

    return 0;
}
