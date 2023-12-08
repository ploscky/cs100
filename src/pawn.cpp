#include "../header/board.h"
#include <iostream>

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

void Board::pawnPromotion()
{
    Piece *whitePromotion = nullptr;
    Piece *blackPromotion = nullptr;

    for (int i = 0; i < 8; ++i)
    {
        // set piece pointers to first and last ranks, then iterate through every file
        whitePromotion = board[i][7]->getPiece();
        blackPromotion = board[i][0]->getPiece();
        
        // check if a pawn has reached the other end
        if (whitePromotion && whitePromotion->getNotation() == 'P' || blackPromotion && blackPromotion->getNotation() == 'P')
        {
            int colorFlag = 0; // set to 1 if black pawn is promoting
            if (blackPromotion->getNotation() == 'P')
                {colorFlag = 1;}

            // validate user input for chosen piece to promote to
            bool isValidPromotion = false;
            while (!isValidPromotion)
            {
                char promotionPiece = ' ';
                cout << "Would you like to promote your pawn to a Queen(Q), Rook(R), Bishop(B), or Knight(N)?: ";
                cin.clear();
                cin >> promotionPiece;

                if (promotionPiece == 'Q' || promotionPiece == 'R' || promotionPiece == 'B' || promotionPiece == 'N')
                {
                    // input is correct, set notation to promoted piece
                    isValidPromotion = true;
                    if (colorFlag)
                        { blackPromotion->setNotation(promotionPiece); }
                    else
                        { whitePromotion->setNotation(promotionPiece); }
                }
                else
                {
                    cout << "Illegal move. Try again." << endl;
                }
            }
        } 
    }
}
