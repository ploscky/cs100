#pragma once
#include "piece.h"

class Pawn : public Piece
{
    private:
        bool moved;
    public:
        void getPawnLegalMoves(string &, Square *, Piece *, int, int);
};