#pragma once

#include "square.h"

class Board
{
    public: // protected? i dont remember how this works lol
        Square *board[8][8];

    public:
        Board();
        ~Board();
        void print();
        Square * getSquare(int, int);
        void movePiece(string, string);
        string getLegalMoves(int, int);
    
    private:
        void getPawnLegalMoves(string &, Square *, Piece *, int, int);
        void getRookLegalMoves(string &, Square *, Piece *, int, int);
        void getKnightLegalMoves(string &, Square *, Piece *, int, int);
        void getBishopLegalMoves(string &, Square *, Piece *, int, int);
        void getQueenLegalMoves(string &, Square *, Piece *, int, int);
        void getKingLegalMoves(string &, Square *, Piece *, int, int);

};