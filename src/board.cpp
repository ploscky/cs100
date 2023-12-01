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
    getSquare(4, 8)->setPiece(new Piece('b', 'K'));
    getSquare(5, 8)->setPiece(new Piece('b', 'Q'));
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

void Board::getKnightLegalMoves(string &legalMoves, Square *currSquare, Piece *currPiece, int file, int rank)
{
    // right 1 square, forward 2 squares
    if ((file) <= 7 && (rank + 1) <= 7)
    {
        if (board[file][rank + 1]->empty())
        {
            legalMoves += 'N';
            legalMoves += currSquare->getCoordinates().at(0) + 1;
            legalMoves += (currSquare->getCoordinates().at(1) + 2);
            legalMoves += ' ';
        }
        else // destination not empty, check color, then capture if different
        {
            if (board[file][rank + 1]->getPiece()->getColor() != currPiece->getColor()) // if opposite colors
            {
            // for notation x<coordinates>
            legalMoves += 'N';
            legalMoves += 'x';
            legalMoves += currSquare->getCoordinates().at(0) + 1;
            legalMoves += (currSquare->getCoordinates().at(1) + 2);
            legalMoves += ' ';
            
            // for notation <file>x<coordinates>
            legalMoves += 'N';
            legalMoves += currSquare->getCoordinates().at(0);
            legalMoves += 'x';
            legalMoves += currSquare->getCoordinates().at(0) + 1;
            legalMoves += (currSquare->getCoordinates().at(1) + 2);
            legalMoves += ' ';
            }
        }
    }


    // left 1 square, forward 2 squares
    if ((file - 2) >= 1 && (rank + 1) <= 8)
    {
        if (board[file - 2][rank + 1]->empty())
        {
            legalMoves += 'N';
            legalMoves += currSquare->getCoordinates().at(0) - 1;
            legalMoves += (currSquare->getCoordinates().at(1) + 2);
            legalMoves += ' ';
        }
        else // destination not empty, check color, then capture if different
        {
            if (board[file - 2][rank + 1]->getPiece()->getColor() != currPiece->getColor()) // if opposite colors
            {
                // for notation x<coordinates>
                legalMoves += 'N';
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) - 1;
                legalMoves += (currSquare->getCoordinates().at(1) + 2);
                legalMoves += ' ';
                
                // for notation <file>x<coordinates>
                legalMoves += 'N';
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) - 1;
                legalMoves += (currSquare->getCoordinates().at(1) + 2);
                legalMoves += ' ';
            }
        }
        
    }


    // right 2 squares, down 1 square
    if ((file + 1) <= 8 && (rank - 2) >= 1)
    {
        if (board[file + 1][rank - 2]->empty())
        {
            legalMoves += 'N';
            legalMoves += currSquare->getCoordinates().at(0) + 2;
            legalMoves += (currSquare->getCoordinates().at(1) - 1);
            legalMoves += ' ';
        }
        else // destination not empty, check color, then capture if different
        {
            if (board[file + 1][rank - 2]->getPiece()->getColor() != currPiece->getColor()) // if opposite colors
            {
                // for notation x<coordinates>
                legalMoves += 'N';
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) + 2;
                legalMoves += (currSquare->getCoordinates().at(1) - 1);
                legalMoves += ' ';
                
                // for notation <file>x<coordinates>
                legalMoves += 'N';
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) + 2;
                legalMoves += (currSquare->getCoordinates().at(1) - 1);
                legalMoves += ' ';
            }
        }
    }


    // right 2 squares, up 1 square
    if ((file + 1) <= 8 && (rank) <= 8)
    {
        if (board[file + 1][rank]->empty())
        {
        legalMoves += 'N';
        legalMoves += currSquare->getCoordinates().at(0) + 2;
        legalMoves += (currSquare->getCoordinates().at(1) + 1);
        legalMoves += ' ';
        }
        else // destination not empty, check color, then capture if different
        {
            if (board[file + 1][rank]->getPiece()->getColor() != currPiece->getColor()) // if opposite colors
            {
                // for notation x<coordinates>
                legalMoves += 'N';
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) + 2;
                legalMoves += (currSquare->getCoordinates().at(1) + 1);
                legalMoves += ' ';
                
                // for notation <file>x<coordinates>
                legalMoves += 'N';
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) + 2;
                legalMoves += (currSquare->getCoordinates().at(1) + 1);
                legalMoves += ' ';
            }
        }
    }


    // left 2 squares, down 1 square
    if ((file - 3) >= 1 && (rank - 2) >= 1)
    {
        if (board[file - 3][rank - 2]->empty())
        {
            legalMoves += 'N';
            legalMoves += currSquare->getCoordinates().at(0) - 2;
            legalMoves += (currSquare->getCoordinates().at(1) - 1);
            legalMoves += ' ';
        }
        else // destination not empty, check color, then capture if different
        {
            if (board[file - 3][rank - 2]->getPiece()->getColor() != currPiece->getColor()) //if opposite colors
            {
                // for notation x<coordinates>
                legalMoves += 'N';
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) - 2;
                legalMoves += (currSquare->getCoordinates().at(1) - 1);
                legalMoves += ' ';
                
                // for notation <file>x<coordinates>
                legalMoves += 'N';
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) - 2;
                legalMoves += (currSquare->getCoordinates().at(1) - 1);
                legalMoves += ' ';
            }
        }

        
    }


    // left 2 squares, up 1 square
    if ((file - 3) >= 1 && (rank) <= 8)
    {
        if (board[file - 3][rank]->empty())
        {
            legalMoves += 'N';
            legalMoves += currSquare->getCoordinates().at(0) - 2;
            legalMoves += (currSquare->getCoordinates().at(1) + 1);
            legalMoves += ' ';
        }
        else // destination not empty, check color, then capture if different
        {
            if (board[file - 3][rank]->getPiece()->getColor() != currPiece->getColor()) // if opposite colors
            {
                // for notation x<coordinates>
                legalMoves += 'N';
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) - 2;
                legalMoves += (currSquare->getCoordinates().at(1) + 1);
                legalMoves += ' ';
                
                // for notation <file>x<coordinates>
                legalMoves += 'N';
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) - 2;
                legalMoves += (currSquare->getCoordinates().at(1) + 1);
                legalMoves += ' ';
            }
        }
    }
        

    // left 1 square, down 2 squares
    if ((file - 2) <= 8 && (rank - 3) >= 1)
    {
        if (board[file - 2][rank - 3]->empty())
        {
            legalMoves += 'N';
            legalMoves += currSquare->getCoordinates().at(0) - 1;
            legalMoves += (currSquare->getCoordinates().at(1) - 2);
            legalMoves += ' ';
        }
        else // destination not empty, check color, then capture if different
        {
            if (board[file - 2][rank - 3]->getPiece()->getColor() != currPiece->getColor()) //if opposite colors
            {
                // for notation x<coordinates>
                legalMoves += 'N';
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) - 1;
                legalMoves += (currSquare->getCoordinates().at(1) - 2);
                legalMoves += ' ';
                
                // for notation <file>x<coordinates>
                legalMoves += 'N';
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) - 1;
                legalMoves += (currSquare->getCoordinates().at(1) - 2);
                legalMoves += ' ';
            }
        }
    } 


    // right 1 square, down 2 squares
    if ((file) <= 8 && (rank - 3) >= 1)
    {
        if (board[file][rank - 3]->empty())
        {
            legalMoves += 'N';
            legalMoves += currSquare->getCoordinates().at(0) + 1;
            legalMoves += (currSquare->getCoordinates().at(1) - 2);
            legalMoves += ' ';
        }
        else // destination not empty, check color, then capture if different
        {
            if (board[file][rank - 3]->getPiece()->getColor() != currPiece->getColor()) //if opposite colors
            {
                // for notation x<coordinates>
                legalMoves += 'N';
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) + 1;
                legalMoves += (currSquare->getCoordinates().at(1) - 2);
                legalMoves += ' ';
                
                // for notation <file>x<coordinates>
                legalMoves += 'N';
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) + 1;
                legalMoves += (currSquare->getCoordinates().at(1) - 2);
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
