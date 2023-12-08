#pragma once
#include "piece.h"

class King : public Piece
{
    private:
        bool moved;
    public:
        void getKingLegalMoves(string &, Square *, Piece *, int, int);
};