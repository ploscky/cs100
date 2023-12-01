#include "../header/game.h"
#include "gtest/gtest.h"
using namespace std;

TEST(TestingLegalMoves, KnightMovement)
{
    Game n;
    //Movement, based on knight at d5
    EXPECT_TRUE(n.isLegalMove(true, " Ne7 "));
    EXPECT_TRUE(n.isLegalMove(true, " Nc7 "));
    EXPECT_TRUE(n.isLegalMove(true, " Nb6 "));
    EXPECT_TRUE(n.isLegalMove(true, " Nb4 "));
    EXPECT_TRUE(n.isLegalMove(true, " Nf6 "));
    EXPECT_TRUE(n.isLegalMove(true, " Nf4 "));
    EXPECT_TRUE(n.isLegalMove(true, " Ne3 "));
    EXPECT_TRUE(n.isLegalMove(true, " Nc3 "));
    
    //Captures, false if square is not occupied
    EXPECT_FALSE(n.isLegalMove(true, " Nxe7 "));
    EXPECT_FALSE(n.isLegalMove(true, " Nxf4 "));
}