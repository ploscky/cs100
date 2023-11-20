#include "../header/board.h"
#include <iostream>

Board::Board()
{
    for (int rank = 8; rank >= 1; --rank)
    {
        for (int file = 1; file <= 8; ++file)
        {
            board[8 - rank][file - 1] = new Square(file, rank);
        }
    }
}

Board::~Board()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            delete board[i][j];
        }
    }
}

void Board::print()
    {cout << "FIXME" << endl;}

Square * Board::getSquare(int file, int rank)
    {return board[file - 1][rank - 1];}

void Board::movePiece(string from, string to)
{
    int file, rank;
    Piece *currPiece = nullptr;

    file = static_cast<int>(from.at(0) - 'a');
    rank = static_cast<int>(from.at(1) - '0' - 1);

    currPiece = board[file][rank]->getPiece();
    board[file][rank]->setPiece(nullptr);

    file = static_cast<int>(to.at(0) - 'a');
    rank = static_cast<int>(to.at(1) - '0' - 1);

    board[file][rank]->setPiece(currPiece);
}