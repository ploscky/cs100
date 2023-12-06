#include "../header/board.h"

void Board::getQueenLegalMoves(string &legalMoves, Square *currSquare, Piece *currPiece, int file, int rank) 
{   
    //default: file-1, rank-1
    for (int i = 1; i <= 7; ++i)   //moving forward
    {
       if (rank + i <= 8 && board[file - 1][rank - 1 + i]->empty()) // if not off board and square is empty (not capturing)
       {
            legalMoves += 'Q';
            legalMoves += currSquare->getCoordinates().at(0);
            legalMoves += (currSquare->getCoordinates().at(1) + i);
            legalMoves += ' ';
        } 
        else
        {
            if (rank + i <= 8 && board[file - 1][rank - 1 + i]->getPiece()->getColor() != currPiece->getColor()) //if capturing opposing color
            {
                legalMoves += 'Q';
                legalMoves += 'x';                                        // for notation x<coordinates>
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += (currSquare->getCoordinates().at(1) + i);
                legalMoves += ' ';

                legalMoves += 'Q';
                legalMoves += currSquare->getCoordinates().at(0);           // for notation <file>x<coordinates>
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += (currSquare->getCoordinates().at(1) + i);
                legalMoves += ' ';

                legalMoves += 'Q';
                legalMoves += currSquare->getCoordinates().at(1);           // for notation <rank>x<coordinates>
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += (currSquare->getCoordinates().at(1) + i);
                legalMoves += ' ';
            }
            break;
        }
    }

    for (int i = 1; i <= 7; ++i) // moving backward
    {
        if (rank - i >= 1 && board[file - 1][rank - 1 - i]->empty()) // if not off board and square is empty (not capturing)
        {
            legalMoves += 'Q';
            legalMoves += currSquare->getCoordinates().at(0);
            legalMoves += (currSquare->getCoordinates().at(1) - i);
            legalMoves += ' ';
        }
        else
        {
            if (rank - i >= 1 && board[file - 1][rank - 1 - i]->getPiece()->getColor() != currPiece->getColor()) //if capturing opposing color
            {
                legalMoves += 'Q';
                legalMoves += 'x';                                        // for notation x<coordinates>
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += (currSquare->getCoordinates().at(1) - i);
                legalMoves += ' ';

                legalMoves += 'Q';
                legalMoves += currSquare->getCoordinates().at(0);           // for notation <file>x<coordinates>
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += (currSquare->getCoordinates().at(1) - i);
                legalMoves += ' ';

                legalMoves += 'Q';
                legalMoves += currSquare->getCoordinates().at(1);           // for notation <rank>x<coordinates>
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0);
                legalMoves += (currSquare->getCoordinates().at(1) - i);
                legalMoves += ' ';
            }
            break;
        }
    }

    for (int i = 1; i <= 7; ++i) // moving left
    {
        if (file - i >= 1 && board[file - 1 - i][rank - 1]->empty()) // if not off board and square is empty (not capturing)
        {
            legalMoves += 'Q';
            legalMoves += currSquare->getCoordinates().at(0) - i;
            legalMoves += (currSquare->getCoordinates().at(1));
            legalMoves += ' ';
        }
        else
        {
            if (file - i >= 1 && board[file - 1 - i][rank - 1]->getPiece()->getColor() != currPiece->getColor()) //if capturing opposing color
            {
                legalMoves += 'Q';
                legalMoves += 'x';                                        // for notation x<coordinates>
                legalMoves += currSquare->getCoordinates().at(0) - i;
                legalMoves += (currSquare->getCoordinates().at(1));
                legalMoves += ' ';

                legalMoves += 'Q';
                legalMoves += currSquare->getCoordinates().at(0);           // for notation <file>x<coordinates>
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) - i;
                legalMoves += (currSquare->getCoordinates().at(1));
                legalMoves += ' ';

                legalMoves += 'Q';
                legalMoves += currSquare->getCoordinates().at(1);           // for notation <rank>x<coordinates>
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) - i;
                legalMoves += (currSquare->getCoordinates().at(1));
                legalMoves += ' ';
            }
            break;
        }
    }

    for (int i = 1; i <= 7; ++i) // moving right
    {
        if (file + i <= 8 && board[file - 1 + i][rank - 1]->empty()) // if not off board and square is empty (not capturing)
        {
            legalMoves += 'Q';
            legalMoves += currSquare->getCoordinates().at(0) + i;
            legalMoves += (currSquare->getCoordinates().at(1));
            legalMoves += ' ';
        }
        else
        {
            if (file + i <= 8 && board[file - 1 + i][rank - 1]->getPiece()->getColor() != currPiece->getColor()) //if capturing opposing color
            {
                legalMoves += 'Q';
                legalMoves += 'x';                                        // for notation x<coordinates>
                legalMoves += currSquare->getCoordinates().at(0) + i;
                legalMoves += (currSquare->getCoordinates().at(1));
                legalMoves += ' ';

                legalMoves += 'Q';
                legalMoves += currSquare->getCoordinates().at(0);           // for notation <file>x<coordinates>
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) + i;
                legalMoves += (currSquare->getCoordinates().at(1));
                legalMoves += ' ';

                legalMoves += 'Q';
                legalMoves += currSquare->getCoordinates().at(1);           // for notation <rank>x<coordinates>
                legalMoves += 'x';
                legalMoves += currSquare->getCoordinates().at(0) + i;
                legalMoves += (currSquare->getCoordinates().at(1));
                legalMoves += ' ';
            }
            break;
        }
    }

    for (int i = 1; i <= 7; ++i) // forward left diagonal i squares
    {
        if (rank + i <= 8 && file - i >= 1 && board[file - 1 - i][rank - 1 + i]->empty()) // if not off board and square is empty (not capturing)
        {
            legalMoves += 'Q';
            legalMoves += currSquare->getCoordinates().at(0) - i;
            legalMoves += (currSquare->getCoordinates().at(1) + i);
            legalMoves += ' ';
        }
        else
        {
            if (rank + i <= 8 && file - i >= 1  && board[file - 1 - i][rank - 1 + i]->getPiece()->getColor() != currPiece->getColor()) //if capturing opposing color
            {
                legalMoves += 'Q';
                legalMoves += 'x';                                        // for notation x<coordinates>
                legalMoves += (currSquare->getCoordinates().at(0) - i);
                legalMoves += (currSquare->getCoordinates().at(1) + i);
                legalMoves += ' ';

                legalMoves += 'Q';
                legalMoves += currSquare->getCoordinates().at(0);           // for notation <file>x<coordinates>
                legalMoves += 'x';
                legalMoves += (currSquare->getCoordinates().at(0) - i);
                legalMoves += (currSquare->getCoordinates().at(1) + i);
                legalMoves += ' ';

                legalMoves += 'Q';
                legalMoves += currSquare->getCoordinates().at(1);           // for notation <rank>x<coordinates>
                legalMoves += 'x';
                legalMoves += (currSquare->getCoordinates().at(0) - i);
                legalMoves += (currSquare->getCoordinates().at(1) + i);
                legalMoves += ' ';
            }
            break; // if enemy is in the way, stop the loop
        }
    }

    for (int i = 1; i <= 7; ++i) // forward right diagonal i squares
    {
        if (rank + i <= 8 && file + i <= 8 && board[file - 1 + i][rank - 1 + i]->empty()) // if not off board and square is empty (not capturing)
        {
            legalMoves += 'Q';
            legalMoves += currSquare->getCoordinates().at(0) + i;
            legalMoves += (currSquare->getCoordinates().at(1) + i);
            legalMoves += ' ';
        }
        else
        {
            if (rank + i <= 8 && file + i <= 8  && board[file - 1 + i][rank - 1 + i]->getPiece()->getColor() != currPiece->getColor()) //if capturing opposing color
            {
                legalMoves += 'Q';
                legalMoves += 'x';                                        // for notation x<coordinates>
                legalMoves += (currSquare->getCoordinates().at(0) + i);
                legalMoves += (currSquare->getCoordinates().at(1) + i);
                legalMoves += ' ';

                legalMoves += 'Q';
                legalMoves += currSquare->getCoordinates().at(0);           // for notation <file>x<coordinates>
                legalMoves += 'x';
                legalMoves += (currSquare->getCoordinates().at(0) + i);
                legalMoves += (currSquare->getCoordinates().at(1) + i);
                legalMoves += ' ';

                legalMoves += 'Q';
                legalMoves += currSquare->getCoordinates().at(1);           // for notation <rank>x<coordinates>
                legalMoves += 'x';
                legalMoves += (currSquare->getCoordinates().at(0) + i);
                legalMoves += (currSquare->getCoordinates().at(1) + i);
                legalMoves += ' ';
            }
            break; // if enemy is in the way, stop the loop
        }
    }

    for (int i = 1; i <= 7; ++i) // backward left diagonal i squares
    {
        if (rank - i >= 1 && file - i >= 1 && board[file - 1 - i][rank - 1 - i]->empty()) // if not off board and square is empty (not capturing)
        {
            legalMoves += 'Q';
            legalMoves += currSquare->getCoordinates().at(0) - i;
            legalMoves += (currSquare->getCoordinates().at(1) - i);
            legalMoves += ' ';
        }
        else
        {
            if (rank - i >= 1 && file - i >= 1  && board[file - 1 - i][rank - 1 - i]->getPiece()->getColor() != currPiece->getColor()) //if capturing opposing color
            {
                legalMoves += 'Q';
                legalMoves += 'x';                                        // for notation x<coordinates>
                legalMoves += (currSquare->getCoordinates().at(0) - i);
                legalMoves += (currSquare->getCoordinates().at(1) - i);
                legalMoves += ' ';

                legalMoves += 'Q';
                legalMoves += currSquare->getCoordinates().at(0);           // for notation <file>x<coordinates>
                legalMoves += 'x';
                legalMoves += (currSquare->getCoordinates().at(0) - i);
                legalMoves += (currSquare->getCoordinates().at(1) - i);
                legalMoves += ' ';

                legalMoves += 'Q';
                legalMoves += currSquare->getCoordinates().at(1);           // for notation <rank>x<coordinates>
                legalMoves += 'x';
                legalMoves += (currSquare->getCoordinates().at(0) - i);
                legalMoves += (currSquare->getCoordinates().at(1) - i);
                legalMoves += ' ';
            }
            break; 
        }
    }

    for (int i = 1; i <= 7; ++i) // backward right diagonal i squares
    {
        if (rank - i >= 1 && file + i <= 8 && board[file - 1 + i][rank - 1 - i]->empty()) // if not off board and square is empty (not capturing)
        {
            legalMoves += 'Q';
            legalMoves += currSquare->getCoordinates().at(0) + i;
            legalMoves += (currSquare->getCoordinates().at(1) - i);
            legalMoves += ' ';
        }
        else
        {
            if (rank - i >= 1 && file + i <= 8  && board[file - 1 + i][rank - 1 - i]->getPiece()->getColor() != currPiece->getColor()) //if capturing opposing color
            {
                legalMoves += 'Q';
                legalMoves += 'x';                                        // for notation x<coordinates>
                legalMoves += (currSquare->getCoordinates().at(0) + i);
                legalMoves += (currSquare->getCoordinates().at(1) - i);
                legalMoves += ' ';

                legalMoves += 'Q';
                legalMoves += currSquare->getCoordinates().at(0);           // for notation <file>x<coordinates>
                legalMoves += 'x';
                legalMoves += (currSquare->getCoordinates().at(0) + i);
                legalMoves += (currSquare->getCoordinates().at(1) - i);
                legalMoves += ' ';

                legalMoves += 'Q';
                legalMoves += currSquare->getCoordinates().at(1);           // for notation <rank>x<coordinates>
                legalMoves += 'x';
                legalMoves += (currSquare->getCoordinates().at(0) + i);
                legalMoves += (currSquare->getCoordinates().at(1) - i);
                legalMoves += ' ';
            }
            break;
        }
    }
}
