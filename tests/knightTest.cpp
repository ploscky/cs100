#include "../header/board.h"
#include "gtest/gtest.h"
#include <string>

TEST(Knight, NoCapture) {
    Board testBoard;
    testBoard.getSquare(4, 4)->setPiece(new Piece('b', 'N'));   //set Knight piece in middle for testing
    
    string knightString = testBoard.getLegalMoves(4, 4);

    //Movement, based on knight at d4
    EXPECT_NE(knightString.find(" Nb3 "), string::npos);
    EXPECT_NE(knightString.find(" Nb5 "), string::npos);
    EXPECT_NE(knightString.find(" Nc6 "), string::npos);
    EXPECT_NE(knightString.find(" Ne6 "), string::npos);
    EXPECT_NE(knightString.find(" Nf3 "), string::npos);
    EXPECT_NE(knightString.find(" Nf5 "), string::npos);
}

TEST(Knight, Capture) {
    Board testBoard;
    testBoard.getSquare(4, 4)->setPiece(new Piece('b', 'N'));

    string knightString = testBoard.getLegalMoves(4, 4);
    
    // can capture pawns at c2 and e2
    EXPECT_NE(knightString.find(" Nxc2 "), string::npos);  //forward left
    EXPECT_NE(knightString.find(" Nxe2 "), string::npos);  //forward right
}