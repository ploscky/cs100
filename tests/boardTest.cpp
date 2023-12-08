#include "../header/board.h"
#include "gtest/gtest.h"

TEST(Board, Constructor) {
    EXPECT_NO_THROW(Board testBoard);
}

TEST(Board, Getters) {
    Board testBoard;
    Square* testSquare = testBoard.getSquare(4, 1);  //a1 (white queen)
    Piece* testPiece = testSquare->getPiece();
    
    EXPECT_TRUE(testPiece->getNotation() == 'Q');
}

TEST(Board, MovePiece) {
    Board testBoard;
    testBoard.movePiece("e2", "e3");    //move pawn from e2 to e3
    Square* testSquare = testBoard.getSquare(4, 2);
    EXPECT_TRUE(testSquare->getPiece()->getNotation() == 'P');  //check if pawn moved
}