#pragma once

#include "square.h"
#include "pawn.h"

class Board
{
    public: //protected? i dont remember how this works lol
        Square *board[8][8];
    
    public:
        Board();
        ~Board();
        void print();
        Square * getSquare(int, int);
        void movePiece(string, string);
};
