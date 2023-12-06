#include "../header/board.h"
#include <iostream>
#include <cctype>
#include <string>

Board::Board() // generates empty board with pieces in starting position
{
    for (int file = 1; file <= 8; ++file)
    {
        for (int rank = 1; rank <= 8; ++rank)
        {
            board[file - 1][rank - 1] = new Square(file, rank);
        }
    }
    
    for (unsigned int file = 1; file <= 8; ++file) {
        getSquare(file, 2)->setPiece(new Piece('w', 'P'));
    }
    getSquare(1, 1)->setPiece(new Piece('w', 'R'));
    getSquare(2, 1)->setPiece(new Piece('w', 'N'));
    getSquare(3, 1)->setPiece(new Piece('w', 'B'));
    getSquare(4, 1)->setPiece(new Piece('w', 'K'));
    getSquare(5, 1)->setPiece(new Piece('w', 'Q'));
    getSquare(6, 1)->setPiece(new Piece('w', 'B'));
    getSquare(7, 1)->setPiece(new Piece('w', 'N'));
    getSquare(8, 1)->setPiece(new Piece('w', 'R'));

    for (unsigned int file = 1; file <= 8; ++file) {
        getSquare(file, 7)->setPiece(new Piece('b', 'P'));
    }
    getSquare(1, 8)->setPiece(new Piece('b', 'R'));
    getSquare(2, 8)->setPiece(new Piece('b', 'N'));
    getSquare(3, 8)->setPiece(new Piece('b', 'B'));
    getSquare(4, 8)->setPiece(new Piece('b', 'Q'));
    getSquare(5, 8)->setPiece(new Piece('b', 'K'));
    getSquare(6, 8)->setPiece(new Piece('b', 'B'));
    getSquare(7, 8)->setPiece(new Piece('b', 'N'));
    getSquare(8, 8)->setPiece(new Piece('b', 'R'));
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
{
    unsigned int rankCounter = 8;   //to number the ranks
    cout <<
        "-----------------------------------\n"
        "               BOARD               \n"
        "-----------------------------------\n"
        "\n";


    cout <<
        "  A   B   C   D   E   F   G   H\n"
        "---------------------------------\n";  //numbering the files


    //ranks (rows)
    for (unsigned int i = 8; i >= 1; --i) {
        //files (columns)
        for (unsigned int j = 1; j <= 8; ++j) {
            Square* currSquare = getSquare(j, i);   //get current Square in board
            Piece* currPiece = currSquare->getPiece();  //get the Piece that is on that Square
            if (currPiece == nullptr) { //if there is no piece on the square, returns nullptr
                cout << "|   "; //print space
            }
            else {  //piece on the square
                char currNotation = currPiece->getNotation();   //get piece's notation
                char currColor = currPiece->getColor(); //get piece's color


                if (currColor == 'w') { //piece is white
                cout << "| " << static_cast<char>(toupper(currNotation)) << ' ';
                }
                else {  //piece is black
                cout << "| " << static_cast<char>(tolower(currNotation)) << ' ';
                }
            }
        }
        cout << "| ";
        cout << rankCounter-- << " ";
        cout << "\n---------------------------------\n";
    }
}

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

    if (board[file][rank]->getPiece() != nullptr) // if taking a piece, delete piece
        {delete board[file][rank]->getPiece();}

    board[file][rank]->setPiece(currPiece);

    currPiece->move();
}

string Board::getLegalMoves(int file, int rank)
{
    Square *currSquare = board[file - 1][rank - 1];

    if (currSquare->getPiece() == nullptr) // if no piece
        {return "";}

    Piece *currPiece = currSquare->getPiece();
    string legalMoves = " ";

    if      (currSquare->getPiece()->getNotation() == 'P') // pawn
        {getPawnLegalMoves(legalMoves, currSquare, currPiece, file, rank);}

    else if (currSquare->getPiece()->getNotation() == 'R') // rook
        {getRookLegalMoves(legalMoves, currSquare, currPiece, file, rank);}
 
    else if (currSquare->getPiece()->getNotation() == 'N') // knight
        {getKnightLegalMoves(legalMoves, currSquare, currPiece, file, rank);}

    else if (currSquare->getPiece()->getNotation() == 'B') // bishop
        {getBishopLegalMoves(legalMoves, currSquare, currPiece, file, rank);}

    else if (currSquare->getPiece()->getNotation() == 'Q') // queen
        {getQueenLegalMoves(legalMoves, currSquare, currPiece, file, rank);}

    else if (currSquare->getPiece()->getNotation() == 'K') // king
        {getKingLegalMoves(legalMoves, currSquare, currPiece, file, rank);}   

    return legalMoves;
}
