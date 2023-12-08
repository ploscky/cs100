#pragma once
#include "piece.h"

class Queen : public Piece
{
    public:
        void getValidMoves(string &, Square *, Piece *, int, int);
};