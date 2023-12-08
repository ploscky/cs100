#pragma once
#include "piece.h"

class Queen : public Piece
{
    public:
        void getQueenLegalMoves(string &, Square *, Piece *, int, int);
};