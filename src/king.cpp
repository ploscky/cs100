#include "../header/board.h"

void Board::getKingLegalMoves(string &legalMoves, Square *currSquare, Piece *currPiece, int file, int rank)
{
    string coveredSquares;
    string enemyKingCoordinates;
    string pawnCoveredSquare;

    for (int i = 1; i <= 8; ++i)
    {
        for (int j = 1; j <= 8; ++j)
        {
            if (getSquare(i, j)->getPiece() != nullptr &&               // populating coveredSquares with all coordinates enemy covers
                getSquare(i, j)->getPiece()->getNotation() != 'K' &&
                getSquare(i, j)->getPiece()->getNotation() != 'P' &&
                getSquare(i, j)->getPiece()->getColor() != currPiece->getColor())
                {coveredSquares += getLegalMoves(i, j);}

            if (getSquare(i, j)->getPiece() != nullptr &&               // finding enemy king square
                getSquare(i, j)->getPiece()->getNotation() == 'K' &&
                getSquare(i, j)->getPiece()->getColor() != currPiece->getColor())
                {enemyKingCoordinates = getSquare(i, j)->getCoordinates();}

            if (getSquare(i, j)->getPiece() != nullptr &&
                getSquare(i, j)->getPiece()->getNotation() == 'P' &&
                getSquare(i, j)->getPiece()->getColor() != currPiece->getColor())
            {
                pawnCoveredSquare = getSquare(i, j)->getCoordinates();


                if (getSquare(i, j)->getPiece()->getColor() == 'w')
                {
                    coveredSquares += pawnCoveredSquare.at(0) - 1;
                    coveredSquares += pawnCoveredSquare.at(1) + 1;
                    coveredSquares += pawnCoveredSquare.at(0) + 1;
                    coveredSquares += pawnCoveredSquare.at(1) + 1;
                }
                else
                {
                    coveredSquares += pawnCoveredSquare.at(0) - 1;
                    coveredSquares += pawnCoveredSquare.at(1) - 1;
                    coveredSquares += pawnCoveredSquare.at(0) + 1;
                    coveredSquares += pawnCoveredSquare.at(1) - 1;
                }
            }
        }
    }

    enemyKingCoordinates.at(0) -= 1;            // for other king's covered squares
    coveredSquares += enemyKingCoordinates;
    enemyKingCoordinates.at(1) += 1;
    coveredSquares += enemyKingCoordinates;
    enemyKingCoordinates.at(0) += 1;
    coveredSquares += enemyKingCoordinates;
    enemyKingCoordinates.at(0) += 1;
    coveredSquares += enemyKingCoordinates;
    enemyKingCoordinates.at(1) -= 1;
    coveredSquares += enemyKingCoordinates;
    enemyKingCoordinates.at(1) -= 1;
    coveredSquares += enemyKingCoordinates;
    enemyKingCoordinates.at(0) -= 1;
    coveredSquares += enemyKingCoordinates;
    enemyKingCoordinates.at(0) -= 1;
    coveredSquares += enemyKingCoordinates;

    if (coveredSquares.find(board[file - 2][rank - 1]->getCoordinates()) == string::npos &&
        file - 1 >= 1 && file - 1 <= 8 &&
        rank >= 1 && rank <= 8) // left 1
    {
        if (board[file - 2][rank - 1]->empty())
        {
            legalMoves += 'K';
            legalMoves += currSquare->getCoordinates().at(0) - 1;
            legalMoves += currSquare->getCoordinates().at(1);
            legalMoves += ' ';
        }
        else if (board[file - 2][rank - 1]->getPiece()->getColor() != currPiece->getColor())
        {
            legalMoves += 'K';
            legalMoves += 'x';
            legalMoves += currSquare->getCoordinates().at(0) - 1;
            legalMoves += currSquare->getCoordinates().at(1);
            legalMoves += ' ';
        }
    }

    if (coveredSquares.find(board[file - 2][rank]->getCoordinates()) == string::npos &&
        file - 1 >= 1 && file - 1 <= 8 &&
        rank + 1 >= 1 && rank + 1 <= 8) // left 1, up 1
    {
        if (board[file - 2][rank]->empty())
        {
            legalMoves += 'K';
            legalMoves += currSquare->getCoordinates().at(0) - 1;
            legalMoves += currSquare->getCoordinates().at(1) + 1;
            legalMoves += ' ';
        }
        else if (board[file - 2][rank]->getPiece()->getColor() != currPiece->getColor())
        {
            legalMoves += 'K';
            legalMoves += 'x';
            legalMoves += currSquare->getCoordinates().at(0) - 1;
            legalMoves += currSquare->getCoordinates().at(1) + 1;
            legalMoves += ' ';
        }
    }

    if (coveredSquares.find(board[file - 1][rank]->getCoordinates()) == string::npos &&
        file >= 1 && file <= 8 &&
        rank + 1 >= 1 && rank + 1 <= 8) // up 1
    {
        if (board[file - 1][rank]->empty())
        {
            legalMoves += 'K';
            legalMoves += currSquare->getCoordinates().at(0);
            legalMoves += currSquare->getCoordinates().at(1) + 1;
            legalMoves += ' ';
        }
        else if (board[file - 1][rank]->getPiece()->getColor() != currPiece->getColor())
        {
            legalMoves += 'K';
            legalMoves += 'x';
            legalMoves += currSquare->getCoordinates().at(0);
            legalMoves += currSquare->getCoordinates().at(1) + 1;
            legalMoves += ' ';
        }
    }

    if (coveredSquares.find(board[file][rank]->getCoordinates()) == string::npos &&
        file + 1 >= 1 && file + 1 <= 8 &&
        rank + 1 >= 1 && rank + 1 <= 8) // right 1, up 1
    {
        if (board[file][rank]->empty())
        {
            legalMoves += 'K';
            legalMoves += currSquare->getCoordinates().at(0) + 1;
            legalMoves += currSquare->getCoordinates().at(1) + 1;
            legalMoves += ' ';
        }
        else if (board[file][rank]->getPiece()->getColor() != currPiece->getColor())
        {
            legalMoves += 'K';
            legalMoves += 'x';
            legalMoves += currSquare->getCoordinates().at(0) + 1;
            legalMoves += currSquare->getCoordinates().at(1) + 1;
            legalMoves += ' ';
        }
    }

    if (coveredSquares.find(board[file][rank - 1]->getCoordinates()) == string::npos &&
        file + 1 >= 1 && file + 1 <= 8 &&
        rank >= 1 && rank <= 8) // right 1
    {
        if (board[file][rank - 1]->empty())
        {
            legalMoves += 'K';
            legalMoves += currSquare->getCoordinates().at(0) + 1;
            legalMoves += currSquare->getCoordinates().at(1);
            legalMoves += ' ';
        }
        else if (board[file][rank - 1]->getPiece()->getColor() != currPiece->getColor())
        {
            legalMoves += 'K';
            legalMoves += 'x';
            legalMoves += currSquare->getCoordinates().at(0) + 1;
            legalMoves += currSquare->getCoordinates().at(1);
            legalMoves += ' ';
        }
    }

    if (coveredSquares.find(board[file][rank - 2]->getCoordinates()) == string::npos &&
        file + 1 >= 1 && file + 1 <= 8 &&
        rank - 1 >= 1 && rank - 1 <= 8) // right 1, down 1
    {
        if (board[file][rank - 2]->empty())
        {
            legalMoves += 'K';
            legalMoves += currSquare->getCoordinates().at(0) + 1;
            legalMoves += currSquare->getCoordinates().at(1) - 1;
            legalMoves += ' ';
        }
        else if (board[file][rank - 2]->getPiece()->getColor() != currPiece->getColor())
        {
            legalMoves += 'K';
            legalMoves += 'x';
            legalMoves += currSquare->getCoordinates().at(0) + 1;
            legalMoves += currSquare->getCoordinates().at(1) - 1;
            legalMoves += ' ';
        }
    }

    if (coveredSquares.find(board[file - 1][rank - 2]->getCoordinates()) == string::npos &&
        file >= 1 && file <= 8 &&
        rank - 1 >= 1 && rank - 1 <= 8) // down 1
    {
        if (board[file - 1][rank - 2]->empty())
        {
            legalMoves += 'K';
            legalMoves += currSquare->getCoordinates().at(0);
            legalMoves += currSquare->getCoordinates().at(1) - 1;
            legalMoves += ' ';
        }
        else if (board[file - 1][rank - 2]->getPiece()->getColor() != currPiece->getColor())
        {
            legalMoves += 'K';
            legalMoves += 'x';
            legalMoves += currSquare->getCoordinates().at(0);
            legalMoves += currSquare->getCoordinates().at(1) - 1;
            legalMoves += ' ';
        }
    }

    if (coveredSquares.find(board[file - 2][rank - 2]->getCoordinates()) == string::npos &&
        file - 1 >= 1 && file - 1 <= 8 &&
        rank - 1 >= 1 && rank - 1 <= 8) // left 1, down 1
    {
        if (board[file - 2][rank - 2]->empty())
        {
            legalMoves += 'K';
            legalMoves += currSquare->getCoordinates().at(0) - 1;
            legalMoves += currSquare->getCoordinates().at(1) - 1;
            legalMoves += ' ';
        }
        else if (board[file - 2][rank - 2]->getPiece()->getColor() != currPiece->getColor())
        {
            legalMoves += 'K';
            legalMoves += 'x';
            legalMoves += currSquare->getCoordinates().at(0) - 1;
            legalMoves += currSquare->getCoordinates().at(1) - 1;
            legalMoves += ' ';
        }
    }

    if (!currPiece->hasMoved())
    {
        if (currPiece->getColor() == 'w')
        {
            if (getSquare(1, 1)->getPiece() != nullptr &&
                !getSquare(1, 1)->getPiece()->hasMoved() &&
                getSquare(2, 1)->empty() &&
                getSquare(3, 1)->empty() &&
                coveredSquares.find("d1") == string::npos &&
                coveredSquares.find("c1") == string::npos &&
                coveredSquares.find("b1") == string::npos)
                {legalMoves += "O-O ";}
           
            if (getSquare(8, 1)->getPiece() != nullptr &&
                !getSquare(8, 1)->getPiece()->hasMoved() &&
                getSquare(5, 1)->empty() &&
                getSquare(6, 1)->empty() &&
                getSquare(7, 1)->empty() &&
                coveredSquares.find("d1") == string::npos &&
                coveredSquares.find("e1") == string::npos &&
                coveredSquares.find("f1") == string::npos)
                {legalMoves += "O-O-O ";}
        }
        else
        {
            if (getSquare(1, 8)->getPiece() != nullptr &&
                !getSquare(1, 8)->getPiece()->hasMoved() &&
                getSquare(2, 8)->empty() &&
                getSquare(3, 8)->empty() &&
                getSquare(4, 8)->empty() &&
                coveredSquares.find("e8") == string::npos &&
                coveredSquares.find("d8") == string::npos &&
                coveredSquares.find("c8") == string::npos)
                {legalMoves += "O-O-O ";}
           
            if (getSquare(8, 8)->getPiece() != nullptr &&
                !getSquare(8, 8)->getPiece()->hasMoved() &&
                getSquare(6, 8)->empty() &&
                getSquare(7, 8)->empty() &&
                coveredSquares.find("e8") == string::npos &&
                coveredSquares.find("f8") == string::npos &&
                coveredSquares.find("g8") == string::npos)
                {legalMoves += "O-O ";}
        }
    }
}
