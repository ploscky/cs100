#pragma once
#include "piece.h"

class Queen {
    private:
        bool moved;
    public:
        void getQueenLegalMoves(string &, Square *, Piece *, int, int);
};