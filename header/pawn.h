#pragma once
#include "piece.h"

class Pawn 
{
    private:
        bool moved;
    public:
        void getPawnLegalMoves(string &, Square *, Piece *, int, int);
};