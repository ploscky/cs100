#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib> 

using namespace std;

void showMainMenu();
void showHowToPlay();
void showPlayScreen();
void showGameOverScreen();
void showGameLogScreen();


void showMainMenu() {
    int choice;

    cout <<
    "---------------------------------\n"
    "           CHESS GAME\n"
    "---------------------------------\n"
    "1. Start New Game\n"
    "2. How to Play\n"
    "3. Exit\n"
    "Enter your choice: ";

    cin >> choice;

    switch (choice) {
        case 1:
            showPlayScreen();
            break;
        case 2:
            showHowToPlay();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Invalid choice, please try again.\n";
            showMainMenu();
    }
}

void showHowToPlay() {
    cout <<  
    "---------------------------------\n"
    "           HOW TO PLAY\n"
    "---------------------------------\n\n"
    "Chess is played on an 8x8 grid, with each player starting\n"
    "with 16 pieces that move in distinct ways. To win, you must\n"
    "checkmate your opponent's king.\n"
    "Rules:\n"
    "- Use chess notation for moves, e.g., \"Ne6\".\n"
    "- A move is denoted by the piece's letter and its destination\n"
    "  square, e.g., \"Nf3\" moves a knight to the f3 square.\n"
    "- On the board each white piece is identified by an uppercase letter:\n"
    "  R for Rook, N for Knight, B for Bishop, Q for Queen,\n"
    "  K for King, and P for Pawn.\n"
    "- On the board each black piece is identified by a lowercase letter:\n"
    "  r for Rook, n for Knight, b for Bishop, q for Queen,\n"
    "  k for King, and p for Pawn.\n"
    "- The columns (files) are labeled a-h from left to right,\n"
    "  and the rows (ranks) are labeled 1-8 from bottom to top.\n"
    "- To capture, simply move your piece to the square occupied\n"
    "  by an opponent's piece.\n"
    "- Pawns are not denoted by letter, only by the destination\n"
    "  square, e.g., \"e4\".\n"
    "- Castling is indicated by \"O-O\" for kingside or \"O-O-O\" for\n"
    "  queenside.\n\n"
    "Special Moves:\n"
    "- \"en passant\" is a special pawn capture.\n"
    "- \"promotion\" occurs when a pawn reaches the farthest rank.\n\n"
    "Commands:\n"
    "- \"e4\": To move a pawn to e4.\n"
    "- \"exit\": Exit the current game and return to the main menu.\n"
    "- \"help\": Show a list of commands and rules.\n\n"
    "Type your commands or moves when prompted during gameplay.\n"
    "Press any key to return to the main menu\n";
    cin.ignore(); cin.get();
    showMainMenu();
}


void showPlayScreen() {
}

void showGameOverScreen() {
}

void showGameLogScreen() {

}


int main() {
    showMainMenu();
    return 0;
}
