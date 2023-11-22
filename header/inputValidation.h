#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class InputValidation
{
    public:
    //Reset variables and prompt user for input
    void getInput();
    string userInput;
    
    //default constructor
    InputValidation();

    //helper functions that validate input
    void validatePiece();
    void validateLocationLetter();
    void validateLocationNumber();

    //store each component of the input in a char variable (piece, letter, number)
    char pieceChar;
    char locationLetter;
	char locationNumber;

    string errorMessage; //prints message specific to the invalid character


    private:
    //used as label for piece ('Q' = "Queen")
    string piece;

};