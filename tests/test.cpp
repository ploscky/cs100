#include "../header/board.h"
using namespace std;

int main() {
    Game g; 

    cout << g.game->getLegalMoves(6,5) << endl;

    
    Board board1;
    //board1.movePiece("e2", "e3");
    board1.print();
    return 0;
}