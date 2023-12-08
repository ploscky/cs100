#include "../header/board.h"
#include "gtest/gtest.h"
#include <string>

TEST(King, NoCapture) {
    Board testBoard;
    testBoard.getSquare(4, 5)->setPiece(new Piece('b', 'K'));   //set king piece in middle for testing
    
    string kingString = testBoard.getLegalMoves(4, 5);

    //Movement, based on king at d5
    EXPECT_NE(kingString.find(" Kd6 "), string::npos);  //forward
    EXPECT_NE(kingString.find(" Kc5 "), string::npos);  //left
    EXPECT_NE(kingString.find(" Ke5 "), string::npos);  //right
    EXPECT_NE(kingString.find(" Kd4 "), string::npos);  //down
    EXPECT_NE(kingString.find(" Kc6 "), string::npos);  //left up diagonal
    EXPECT_NE(kingString.find(" Ke6 "), string::npos);  //right up diagonal
    EXPECT_NE(kingString.find(" Kc4 "), string::npos);  //left down diagonal
    EXPECT_NE(kingString.find(" Ke4 "), string::npos);  //right down diagonal
}

TEST(King, Capture) {
    Board testBoard;
    testBoard.getSquare(4, 5)->setPiece(new Piece('b', 'K'));
    
    testBoard.movePiece("d2", "d4"); //move pawn to test capture
    string kingString = testBoard.getLegalMoves(4, 5);
    
    // possible captures
    EXPECT_NE(kingString.find(" Kxd4 "), string::npos);
}