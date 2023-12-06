#pragma once
#include "piece.h"

class Knight {
    private:
        bool moved;
    public:
        void getKnightLegalMoves(string &, Square *, Piece *, int, int);
};