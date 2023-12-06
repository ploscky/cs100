#pragma once
#include "piece.h"

class Rook {
    private:
        bool moved;
    public:
        void getRookLegalMoves(string &, Square *, Piece *, int, int);
};