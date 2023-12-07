#include "../header/board.h"
#include "gtest/gtest.h"
#include <string>

TEST(Queen, NoCapture) {
    Board testBoard;
    testBoard.getSquare(4, 4)->setPiece(new Piece('w', 'Q'));   //set Queen piece in middle for testing
    
    string queenString = testBoard.getLegalMoves(4, 4);


    //Movement, based on queen at d3
    EXPECT_NE(queenString.find(" Qd6 "), string::npos);  //forward
    EXPECT_NE(queenString.find(" Qg4 "), string::npos);  //right
    EXPECT_NE(queenString.find(" Qd3 "), string::npos);  //backward
    EXPECT_NE(queenString.find(" Qb4 "), string::npos);  //left
    EXPECT_NE(queenString.find(" Qf6 "), string::npos);  //forward right diagonal
    EXPECT_NE(queenString.find(" Qb6 "), string::npos);  //forward left diagonal
    EXPECT_NE(queenString.find(" Qe3 "), string::npos);  //backward right diagonal
    EXPECT_NE(queenString.find(" Qc3 "), string::npos);  //backward left diagonal
}

TEST(Queen, Capture) {
    Board testBoard;
    testBoard.getSquare(4, 4)->setPiece(new Piece('w', 'Q'));

    string queenString = testBoard.getLegalMoves(4, 4);
    
    EXPECT_NE(queenString.find(" Qxd7 "), string::npos);    //forward capture
    EXPECT_NE(queenString.find(" Qxg7 "), string::npos);    //forward right capture
    EXPECT_NE(queenString.find(" Qxa7 "), string::npos);    //forward left capture
}