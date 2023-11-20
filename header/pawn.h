#pragma once

#include "piece.h"

using namespace std;

class Pawn : public Piece
{
    private:
        bool moved = false;

    public:
        Pawn(char);
        string getMoves(string);
        void move();
    
    private:
        bool hasMoved();
};