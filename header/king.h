#pragma once
#include "piece.h"

class King {
    private:
        bool moved;
    public:
        void getKingLegalMoves(string &, Square *, Piece *, int, int);
};