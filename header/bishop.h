#pragma once
#include "piece.h"

class Bishop {
    private:
        bool moved;
    public:
        void getBishopLegalMoves(string &, Square *, Piece *, int, int);
};