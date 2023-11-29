#include "../header/board.h"
#include <iostream>

Board::Board() // generates empty board with 1 pawn at e2 for testing purposes, need to add rest of starting pieces
{
    for (int file = 1; file <= 8; ++file)
    {
        for (int rank = 1; rank <= 8; ++rank)
        {
            board[file - 1][rank - 1] = new Square(file, rank);
        }
    }

    getSquare(6, 5)->setPiece(new Piece('b', 'R'));
    getSquare(6, 3)->setPiece(new Piece('w', 'P'));
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
    cout <<
        "-----------------------------------\n"
        "               BOARD               \n"
        "-----------------------------------\n"
        "Status: [Start of Game]\n"
        "\n"
        "    A   B   C   D   E   F   G   H  \n"
        "  ---------------------------------\n"
        "8 | r | n | b | q | k | b | n | r |\n"
        "  ---------------------------------\n"
        "7 | p | p | p | p | p | p | p | p |\n"
        "  ---------------------------------\n"
        "6 | . | . | . | . | . | . | . | . |\n"
        "  ---------------------------------\n"
        "5 | . | . | . | . | . | . | . | . |\n"
        "  ---------------------------------\n"
        "4 | . | . | . | . | . | . | . | . |\n"
        "  ---------------------------------\n"
        "3 | . | . | . | . | . | . | . | . |\n"
        "  ---------------------------------\n"
        "2 | P | P | P | P | P | P | P | P |\n"
        "  ---------------------------------\n"
        "1 | R | N | B | K | Q | B | N | R |\n"
        "  ---------------------------------\n";
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

    return legalMoves;
}

void Board::getPawnLegalMoves(string &legalMoves, Square *currSquare, Piece *currPiece, int file, int rank)
{
    if (currPiece->getColor() == 'w') // is white
    {
        if (board[file - 1][rank]->empty())
        {
            legalMoves += currSquare->getCoordinates().at(0);         // forward 1 square
            legalMoves += (currSquare->getCoordinates().at(1) + 1);
            legalMoves += ' ';
            
            if (board[file - 1][rank + 1]->empty() && !currPiece->hasMoved())
            {
                legalMoves += currSquare->getCoordinates().at(0);         // forward 2 squares
                legalMoves += (currSquare->getCoordinates().at(1) + 2);
                legalMoves += ' ';
            }
        }

        if (currSquare->getCoordinates().at(0) != 'a' &&            // taking left
            !board[file - 2][rank]->empty() && 
            board[file - 2][rank]->getPiece()->getColor() == 'b')            
        {
            legalMoves += currSquare->getCoordinates().at(0);
            for (int i = 0; i < 2; ++i) // for both notations <file>x<coordinates> and x<coordinates>
            {
                legalMoves += 'x';
                legalMoves += (currSquare->getCoordinates().at(0) - 1);   
                legalMoves += (currSquare->getCoordinates().at(1) + 1);
                legalMoves += ' ';
            }
        }

        if (currSquare->getCoordinates().at(0) != 'h' &&               // taking right
            !board[file][rank]->empty() && 
            board[file][rank]->getPiece()->getColor() == 'b')
        {
            legalMoves += currSquare->getCoordinates().at(0);
            for (int i = 0; i < 2; ++i) // for both notations <file>x<coordinates> and x<coordinates>
            {
                legalMoves += 'x';
                legalMoves += (currSquare->getCoordinates().at(0) + 1);   
                legalMoves += (currSquare->getCoordinates().at(1) + 1);
                legalMoves += ' ';
            }
        }
    }
    else // is black
    {
        if (board[file - 1][rank - 2]->empty())
        {
            legalMoves += currSquare->getCoordinates().at(0);         // forward 1 square
            legalMoves += (currSquare->getCoordinates().at(1) - 1);
            legalMoves += ' ';
            
            if (board[file - 1][rank - 3]->empty() && !currPiece->hasMoved())
            {
                legalMoves += currSquare->getCoordinates().at(0);         // forward 2 squares
                legalMoves += (currSquare->getCoordinates().at(1) - 2);
                legalMoves += ' ';
            }
        }

        if (currSquare->getCoordinates().at(0) != 'a' &&            // taking left
            !board[file - 2][rank - 2]->empty() && 
            board[file - 2][rank - 2]->getPiece()->getColor() == 'w')            
        {
            legalMoves += currSquare->getCoordinates().at(0);  
            for (int i = 0; i < 2; ++i) // for both notations <file>x<coordinates> and x<coordinates>
            { 
                legalMoves += 'x';
                legalMoves += (currSquare->getCoordinates().at(0) - 1);   
                legalMoves += (currSquare->getCoordinates().at(1) - 1);
                legalMoves += ' ';
            }
        }

        if (currSquare->getCoordinates().at(0) != 'h' &&               // taking right
            !board[file][rank - 2]->empty() && 
            board[file][rank - 2]->getPiece()->getColor() == 'w')
        {
            legalMoves += currSquare->getCoordinates().at(0);
            for (int i = 0; i < 2; ++i) // for both notations <file>x<coordinates> and x<coordinates>
            {
                legalMoves += 'x';
                legalMoves += (currSquare->getCoordinates().at(0) + 1);   
                legalMoves += (currSquare->getCoordinates().at(1) - 1);
                legalMoves += ' ';
            }
        }
    }
}

void Board::getRookLegalMoves(string &legalMoves, Square *currSquare, Piece *currPiece, int file, int rank)
{
    for (int i = 1; i <= 7; ++i) // forward i squares
    {
        if (rank + i <= 8 && board[file - 1][rank - 1 + i]->empty()) // if not off board and square is empty
        {
            legalMoves += 'R';
            legalMoves += currSquare->getCoordinates().at(0);
            legalMoves += (currSquare->getCoordinates().at(1) + i);
            legalMoves += ' ';
        }
        else
        {
            if (rank + i <= 8 && board[file - 1][rank - 1 + i]->getPiece()->getColor() != currPiece->getColor()) //if opposite colors
            {
                legalMoves += 'R';
                legalMoves += 'x';                                        // for notation x<coordinates>
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += (currSquare->getCoordinates().at(1) + i);
                legalMoves += ' ';

                legalMoves += 'R';
                legalMoves += currSquare->getCoordinates().at(0);           // for notation <file>x<coordinates>
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += (currSquare->getCoordinates().at(1) + i);
                legalMoves += ' ';

                legalMoves += 'R';
                legalMoves += currSquare->getCoordinates().at(1);           // for notation <rank>x<coordinates>
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += (currSquare->getCoordinates().at(1) + i);
                legalMoves += ' ';
            }
            break; // if enemy is in the way, stop the loop
        }
    }

    for (int i = 1; i <= 7; ++i) // back i squares
    {
        if (rank - i >= 1 && board[file - 1][rank - 1 - i]->empty()) // if not off board and square is empty
        {
            legalMoves += 'R';
            legalMoves += currSquare->getCoordinates().at(0);
            legalMoves += (currSquare->getCoordinates().at(1) - i);
            legalMoves += ' ';
        }
        else
        {
            if (rank - i >= 1 && board[file - 1][rank - 1 - i]->getPiece()->getColor() != currPiece->getColor()) //if opposite colors
            {
                legalMoves += 'R';
                legalMoves += 'x';                                        // for notation x<coordinates>
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += (currSquare->getCoordinates().at(1) - i);
                legalMoves += ' ';

                legalMoves += 'R';
                legalMoves += currSquare->getCoordinates().at(0);           // for notation <file>x<coordinates>
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += (currSquare->getCoordinates().at(1) - i);
                legalMoves += ' ';

                legalMoves += 'R';
                legalMoves += currSquare->getCoordinates().at(1);           // for notation <rank>x<coordinates>
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += (currSquare->getCoordinates().at(1) - i);
                legalMoves += ' ';
            }
            break;
        }
    }

    for (int i = 1; i <= 7; ++i) // left i squares
    {
        if (file - i >= 1 && board[file - 1 - i][rank - 1]->empty()) // if not off board and square is empty
        {
            legalMoves += 'R';
            legalMoves += currSquare->getCoordinates().at(0) - i;
            legalMoves += (currSquare->getCoordinates().at(1));
            legalMoves += ' ';
        }
        else
        {
            if (file - i >= 1 && board[file - 1 - i][rank - 1]->getPiece()->getColor() != currPiece->getColor()) //if opposite colors
            {
                legalMoves += 'R';
                legalMoves += 'x';                                        // for notation x<coordinates>
                legalMoves += currSquare->getCoordinates().at(0) - i;
                legalMoves += (currSquare->getCoordinates().at(1));
                legalMoves += ' ';

                legalMoves += 'R';
                legalMoves += currSquare->getCoordinates().at(0);           // for notation <file>x<coordinates>
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) - i;
                legalMoves += (currSquare->getCoordinates().at(1));
                legalMoves += ' ';

                legalMoves += 'R';
                legalMoves += currSquare->getCoordinates().at(1);           // for notation <rank>x<coordinates>
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) - i;
                legalMoves += (currSquare->getCoordinates().at(1));
                legalMoves += ' ';
            }
            break;
        }
    }

    for (int i = 1; i <= 7; ++i) // right i squares
    {
        if (file + i <= 8 && board[file - 1 + i][rank - 1]->empty()) // if not off board and square is empty
        {
            legalMoves += 'R';
            legalMoves += currSquare->getCoordinates().at(0) + i;
            legalMoves += (currSquare->getCoordinates().at(1));
            legalMoves += ' ';
        }
        else
        {
            if (file + i <= 8 && board[file - 1 + i][rank - 1]->getPiece()->getColor() != currPiece->getColor()) //if opposite colors
            {
                legalMoves += 'R';
                legalMoves += 'x';                                        // for notation x<coordinates>
                legalMoves += currSquare->getCoordinates().at(0) + i;
                legalMoves += (currSquare->getCoordinates().at(1));
                legalMoves += ' ';

                legalMoves += 'R';
                legalMoves += currSquare->getCoordinates().at(0);           // for notation <file>x<coordinates>
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) + i;
                legalMoves += (currSquare->getCoordinates().at(1));
                legalMoves += ' ';

                legalMoves += 'R';
                legalMoves += currSquare->getCoordinates().at(1);           // for notation <rank>x<coordinates>
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) + i;
                legalMoves += (currSquare->getCoordinates().at(1));
                legalMoves += ' ';
            }
            break;
        }
    }
}

