#include <iostream>
#include "../header/board.h"
#include "gtest/gtest.h"
#include <string>


TEST(Pawn, NoCapture) {
	Board testBoard;
	string pawnString = testBoard.getLegalMoves(3, 2); //pawn at c2

	//Movement, based on pawn at c2
	EXPECT_NE(pawnString.find(" c3 "), string::npos);  //forward once
	EXPECT_NE(pawnString.find(" c4 "), string::npos);  //forward twice
}


TEST(Pawn, Capture) {
	Board testBoard;
	testBoard.getSquare(3, 4)->setPiece(new Piece('w', 'P'));
	//pawns to be captured
	testBoard.getSquare(2, 5)->setPiece(new Piece('b', 'P'));
	testBoard.getSquare(4, 5)->setPiece(new Piece('b', 'P'));


	string pawnString = testBoard.getLegalMoves(3, 4);
	
	EXPECT_NE(pawnString.find(" xb5 "), string::npos); //forward left capture
	EXPECT_NE(pawnString.find(" xd5 "), string::npos); //forward right capture
}

TEST(Pawn, friendlyFire) {
	Board testBoard;
	//black pawn in range of capture by another black pawn
	testBoard.getSquare(5, 6)->setPiece(new Piece('b', 'P'));


	//black pawn at f7 cannot capture another black pawn (e6)
	string pawnString = testBoard.getLegalMoves(6, 7);
	
	EXPECT_EQ(pawnString.find(" xe6 "), string::npos); //no forward right capture
}