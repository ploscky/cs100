#include "../header/board.h"
#include "gtest/gtest.h"
#include <string>

TEST(Rook, NoCapture) {
    Board testBoard;
    testBoard.getSquare(4, 4)->setPiece(new Piece('w', 'R'));   //set Rook piece to middle for testing
    
    string rookString = testBoard.getLegalMoves(4, 4);


    //Movement, based on rook at d3
    EXPECT_NE(rookString.find(" Rd6 "), string::npos);  //forward
    EXPECT_NE(rookString.find(" Rg4 "), string::npos);  //right
    EXPECT_NE(rookString.find(" Rd3 "), string::npos);  //backward
    EXPECT_NE(rookString.find(" Rb4 "), string::npos);  //left
}

TEST(Rook, Capture) {
    Board testBoard;
    testBoard.getSquare(4, 4)->setPiece(new Piece('w', 'R'));

    string rookString = testBoard.getLegalMoves(4, 4);
    
    EXPECT_NE(rookString.find(" Rxd7 "), string::npos); //forward capture
}

