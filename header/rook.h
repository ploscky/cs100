#pragma once
#include "piece.h"

class Rook : public Piece
{
    private:
        bool moved;
    public:
        void getRookLegalMoves(string &, Square *, Piece *, int, int);
};