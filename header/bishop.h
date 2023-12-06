#pragma once
#include "piece.h"

class Bishop : public Piece
{
    public:
        void getBishopLegalMoves(string &, Square *, Piece *, int, int);
};