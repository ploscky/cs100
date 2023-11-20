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
        // void setCoordinates(int, int);
        string getCoordinates() {return coordinates;}
        void setPiece(Piece *p) {currPiece = p;}
        Piece * getPiece()      {return currPiece;}
        string getLegalMoves();
};