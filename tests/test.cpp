#include "../header/game.h"
#include "gtest/gtest.h"
using namespace std;

TEST(TestingLegalMoves, Pawn)
{
    Game a;

    EXPECT_TRUE(a.isLegalMove(true, " e3 "));
    EXPECT_TRUE(a.isLegalMove(true, " e4 "));
    EXPECT_TRUE(a.isLegalMove(true, " xf3 "));
    EXPECT_TRUE(a.isLegalMove(true, " exf3 "));
    EXPECT_FALSE(a.isLegalMove(true, " xd3 "));
    EXPECT_FALSE(a.isLegalMove(true, " exd3 "));
    EXPECT_FALSE(a.isLegalMove(false, " e3 "));
    EXPECT_FALSE(a.isLegalMove(false, " e4 "));
    EXPECT_FALSE(a.isLegalMove(false, " xf3 "));
    EXPECT_FALSE(a.isLegalMove(false, " exf3 "));
}