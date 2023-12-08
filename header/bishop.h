#pragma once
#include "piece.h"

class Bishop : public Piece
{
    public:
        void getValidMoves(string &, Square *, Piece *, int, int);
};