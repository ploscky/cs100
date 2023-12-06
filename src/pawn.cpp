#include "../header/board.h"

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
       
        legalMoves += '*';                                           // for king's legal moves
        legalMoves += (currSquare->getCoordinates().at(0) - 1);  
        legalMoves += (currSquare->getCoordinates().at(1) + 1);
        legalMoves += ' ';

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

        legalMoves += '*';                                          // for king's legal moves
        legalMoves += (currSquare->getCoordinates().at(0) + 1);  
        legalMoves += (currSquare->getCoordinates().at(1) + 1);
        legalMoves += ' ';

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

        legalMoves += '*';                                          // for king's legal moves
        legalMoves += (currSquare->getCoordinates().at(0) - 1);  
        legalMoves += (currSquare->getCoordinates().at(1) - 1);
        legalMoves += ' ';

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

        legalMoves += '*';                                          // for king's legal moves
        legalMoves += (currSquare->getCoordinates().at(0) + 1);  
        legalMoves += (currSquare->getCoordinates().at(1) - 1);
        legalMoves += ' ';

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