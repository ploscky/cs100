#include "../header/board.h"
#include "gtest/gtest.h"
#include <string>

TEST(Bishop, NoCapture) {
    Board testBoard;
    testBoard.getSquare(4, 4)->setPiece(new Piece('w', 'B'));   //set Bishop piece in middle for testing
    
    string bishopString = testBoard.getLegalMoves(4, 4);

    //Movement, based on bishop at d4
    EXPECT_NE(bishopString.find(" Bc3 "), string::npos);  //back left
    EXPECT_NE(bishopString.find(" Bc5 "), string::npos);  //forward left 1
    EXPECT_NE(bishopString.find(" Bb6 "), string::npos);  //forward left 2
    EXPECT_NE(bishopString.find(" Be3 "), string::npos);  //backward right
    EXPECT_NE(bishopString.find(" Be5 "), string::npos);  //forward right 1
    EXPECT_NE(bishopString.find(" Bf6 "), string::npos);  //forward right 2
}

TEST(Bishop, Capture) {
    Board testBoard;
    testBoard.getSquare(4, 4)->setPiece(new Piece('w', 'B'));

    string bishopString = testBoard.getLegalMoves(4, 4);
    
    // can capture pawns at a7 and g7
    EXPECT_NE(bishopString.find(" Bxa7 "), string::npos);  //forward left 3
    EXPECT_NE(bishopString.find(" Bxg7 "), string::npos);  //forward right 3
}