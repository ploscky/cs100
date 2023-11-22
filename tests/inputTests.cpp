#include "../header/inputValidation.h"
#include "gtest/gtest.h"
using namespace std;

//Constructor test
TEST (ConstructorTests, DefaultConstructor){
    EXPECT_NO_THROW (InputValidation(inputTest));
}



//No error message cases
TEST (ValidInput, PieceTest){
    InputValidation inputTest;
    inputTest.userInput = "Qb6";
    inputTest.validatePiece();
    EXPECT_TRUE (inputTest.pieceChar == 'Q');
}

TEST (ValidInput, LocationLetterTest){
    InputValidation inputTest;
    inputTest.userInput = "Kf7";
    inputTest.validateLocationLetter();
    EXPECT_TRUE (inputTest.locationLetter == 'f');
}

TEST (ValidInput, LocationNumberTest){
    InputValidation inputTest;
    inputTest.userInput = "Rd8";
    inputTest.validateLocationNumber();
    EXPECT_TRUE (inputTest.locationNumber == '8');
}



//Pawn special cases
TEST (PawnTests, PawnPieceTest){
    InputValidation inputTest;
    inputTest.userInput = "e4";
    inputTest.validatePiece();

    //No piece character for pawn chess notation
    EXPECT_EQ (inputTest.pieceChar, ' ');
}

TEST (PawnTests, PawnLocationLetterTest){
    InputValidation inputTest;
    inputTest.userInput = "e4";
    inputTest.validatePiece(); //invokes both locationLetter and locationNumber
    
    //locationLetter char can only be updated if locationLetter() and locationNumber() work properly
    EXPECT_EQ (inputTest.locationLetter, 'e');
}

TEST (PawnTests, PawnLocationNumberTest){
    InputValidation inputTest;
    inputTest.userInput = "e4";
    inputTest.validatePiece(); //invokes both locationLetter and locationNumber

    //locationNumber char can only be updated if locationLetter() and locationNumber() work properly
    EXPECT_EQ (inputTest.locationNumber, '4');
}