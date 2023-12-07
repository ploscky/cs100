#include "../header/board.h"

void Board::getKnightLegalMoves(string &legalMoves, Square *currSquare, Piece *currPiece, int file, int rank)
{
    // right 1 square, forward 2 squares
    if ((file + 1) <= 8 && (rank + 2) <= 8)
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
            legalMoves += '*';                                          // for king's legal moves
            legalMoves += currSquare->getCoordinates().at(0) + 1;
            legalMoves += (currSquare->getCoordinates().at(1) + 2);
            legalMoves += ' ';

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
    if ((file - 1) >= 1 && (rank + 2) <= 8)
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
            legalMoves += '*';                                          // for king's legal moves
            legalMoves += currSquare->getCoordinates().at(0) - 1;
            legalMoves += (currSquare->getCoordinates().at(1) + 2);
            legalMoves += ' ';

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
    if ((file + 2) <= 8 && (rank - 1) >= 1)
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
            legalMoves += '*';                                          // for king's legal moves
            legalMoves += currSquare->getCoordinates().at(0) + 2;
            legalMoves += (currSquare->getCoordinates().at(1) - 1);
            legalMoves += ' ';

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
    if ((file + 2) <= 8 && (rank + 1) <= 8)
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
            legalMoves += '*';                                          // for king's legal moves
            legalMoves += currSquare->getCoordinates().at(0) + 2;
            legalMoves += (currSquare->getCoordinates().at(1) + 1);
            legalMoves += ' ';

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
    if ((file - 2) >= 1 && (rank - 1) >= 1)
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
            legalMoves += '*';                                          // for king's legal moves
            legalMoves += currSquare->getCoordinates().at(0) - 2;
            legalMoves += (currSquare->getCoordinates().at(1) - 1);
            legalMoves += ' ';

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
    if ((file - 2) >= 1 && (rank + 1) <= 8)
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
            legalMoves += '*';                                          // for king's legal moves
            legalMoves += currSquare->getCoordinates().at(0) - 2;
            legalMoves += (currSquare->getCoordinates().at(1) + 1);
            legalMoves += ' ';

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
    if ((file - 1) >= 1 && (rank - 2) >= 1)
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
            legalMoves += '*';                                          // for king's legal moves
            legalMoves += currSquare->getCoordinates().at(0) - 1;
            legalMoves += (currSquare->getCoordinates().at(1) - 2);
            legalMoves += ' ';

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
    if ((file + 1) <= 8 && (rank - 2) >= 1)
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
            legalMoves += '*';                                          // for king's legal moves
            legalMoves += currSquare->getCoordinates().at(0) + 1;
            legalMoves += (currSquare->getCoordinates().at(1) - 2);
            legalMoves += ' ';

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