#include "../header/board.h"

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
            legalMoves += '*';                                           // for king's legal moves
            legalMoves += currSquare->getCoordinates().at(0);
            legalMoves += (currSquare->getCoordinates().at(1) + i);
            legalMoves += ' ';

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
            legalMoves += '*';                                           // for king's legal moves
            legalMoves += currSquare->getCoordinates().at(0);
            legalMoves += (currSquare->getCoordinates().at(1) - i);
            legalMoves += ' ';

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
            legalMoves += '*';                                           // for king's legal moves
            legalMoves += currSquare->getCoordinates().at(0) - i;
            legalMoves += (currSquare->getCoordinates().at(1));
            legalMoves += ' ';

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
            legalMoves += '*';                                           // for king's legal moves
            legalMoves += currSquare->getCoordinates().at(0) + i;
            legalMoves += (currSquare->getCoordinates().at(1));
            legalMoves += ' ';

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