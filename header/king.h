#pragma once
#include "piece.h"

class King : public Piece
{
    private:
        bool moved;
    public:
        bool hasMoved();
        void getValidMoves(string &, Square *, Piece *, int, int);
};