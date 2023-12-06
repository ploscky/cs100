#pragma once
#include "piece.h"

class Knight : public Piece
{
    public:
        void getKnightLegalMoves(string &, Square *, Piece *, int, int);
};