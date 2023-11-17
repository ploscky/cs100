#pragma once

#include "piece.h"
#include <string>

class Square //: public Board
{
    public: //protected:
        Piece *currPiece;
        string coordinates;

    public:
        Square(int, int);
        ~Square();
        bool empty();
        string getCoordinates() {return coordinates;}
        void setPiece(Piece *p) {currPiece = p;}
        string getLegalMoves();
};