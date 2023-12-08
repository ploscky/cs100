#pragma once
#include "piece.h"

class Knight : public Piece
{
    public:
        void getValidMoves(string &, Square *, Piece *, int, int);
};