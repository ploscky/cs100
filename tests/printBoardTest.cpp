#include "../header/board.h"
#include "gtest/gtest.h"
#include <string>

TEST(PrintBoard, OutputFirstLine) {
    Board testBoard;

    stringstream firstLine; //create empty stringstream object
    streambuf* coutBuf = cout.rdbuf(firstLine.rdbuf()); //copies the cout output from print() to firstLine

    testBoard.print();
    cout.rdbuf(coutBuf);    //restores cout

    EXPECT_NE(firstLine.str().find("  A   B   C   D   E   F   G   H"), string::npos);   //checks if the line is found
}

TEST(PrintBoard, OutputEighthRank) {
    Board testBoard;

    stringstream eighthRank;    //creates empty stringstream object
    streambuf* coutBuf = cout.rdbuf(eighthRank.rdbuf());    //copies the cout output from print() to eighthRank

    testBoard.print();
    cout.rdbuf(coutBuf);    //restores cout

    EXPECT_NE(eighthRank.str().find("| r | n | b | q | k | b | n | r | 8 "), string::npos); //checks if the line is found
}

TEST(PrintBoard, MovePawn) {
    Board testBoard;
    testBoard.movePiece("e2", "e3");    //move black pawn to e3

    stringstream movePawn;  //creates empty stringstream object
    streambuf* coutBuf = cout.rdbuf(movePawn.rdbuf());  //copies the cout output from print() to movePawn

    testBoard.print();
    cout.rdbuf(coutBuf);    //restores cout
    EXPECT_NE(movePawn.str().find("|   |   |   |   | P |   |   |   | 3 "), string::npos);   //checks if the line is found
}