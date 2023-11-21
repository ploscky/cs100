#pragma once
#include <string>
#include "square.h"
#include "piece.h"
using namespace std;

class Board {
    public:
        Square *board[8][8];

    public:
        Board();
        ~Board();
        void print();
        Square * getSquare(int, int);
        void movePiece(string, string);
        string getLegalMoves(int, int);
};