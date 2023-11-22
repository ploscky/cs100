#pragma once

#include "piece.h"

class Square
{
    private:
        Piece *currPiece;
        string coordinates;

    public:
        Square(int, int);
        ~Square();
        bool empty();
        string getCoordinates() {return coordinates;}
        void setPiece(Piece *p) {currPiece = p;}
        Piece * getPiece()      {return currPiece;}
};