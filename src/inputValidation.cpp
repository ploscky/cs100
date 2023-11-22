#include "../header/inputValidation.h"
#include <iostream>
using namespace std;

//Default constructor
InputValidation::InputValidation()
  : errorMessage (""),
	userInput (""),
	piece (""),
	pieceChar (' '),
	locationLetter (' '),
	locationNumber (' ')
  {}



//Prompts user for input, resets variables, calls validatePiece()
void InputValidation::getInput(){
	//reinitialize variables before each input because this function may be called after an invalid input is entered
	userInput = "";
    pieceChar = ' ';
    locationLetter = ' ';
	locationNumber = ' ';

	cin.clear(); //make sure input buffer is cleared

	cout << "Insert move: ";
	cin >> userInput;

	//check first if piece is valid
	validatePiece();
}



//Checks if piece character (i.e. 'R' in "Re4") is one of the defined pieces
void InputValidation::validatePiece() {
	pieceChar = userInput.at(0);
	errorMessage = "Invalid piece, try again";

	if (pieceChar == 'B'){ //check for Bishop
		piece = "Bishop";
		validateLocationLetter();

	} else if (pieceChar == 'R'){ //check for Rook
		piece = "Rook";
		validateLocationLetter();

	} else if (pieceChar == 'N'){ //check for Knight
		piece = "Knight";
		validateLocationLetter();

	} else if (pieceChar == 'Q'){ //check for Queen
		piece = "Queen";
		validateLocationLetter();

	} else if (pieceChar == 'K'){ //check for King
		piece = "King";
		validateLocationLetter();

	} else if (pieceChar > 64 && pieceChar < 73 || pieceChar > 96 && pieceChar < 105){ //check for pawn (no letter, see if it's between A and H)
		piece = "Pawn";
		pieceChar = ' '; //no piece character for pawn in chess notation
		validateLocationLetter();

	} else {
		cout << errorMessage << endl;
		cin.clear();
		getInput();	
	}

	//call to validateLocationLetter() is made at the end of every valid piece input
	//checks the next character in userInput string
}



//Checks if location letter (i.e. 'e' in "e4") is within the bounds of the board (between A and H)
void InputValidation::validateLocationLetter() {
	errorMessage = "Invalid location, try again";

	if (piece == "Pawn"){
		locationLetter = userInput.at(0);
		validateLocationNumber();
		return;
	}

	// ASCII for between A and H
	if (userInput.at(1) > 64 && userInput.at(1) < 73 || userInput.at(1) > 96 && userInput.at(1) < 105){
		locationLetter = userInput.at(1);
		validateLocationNumber();
	} else {
		cout << errorMessage << endl;
		getInput();
	}

	//call to validateLocationNumber() is made at the end of every valid location letter input
	//checks the next character in userInput string
}



//Checks if location number (i.e. '4' in "e4") is within the bounds of the board (between 1 and 8)
void InputValidation::validateLocationNumber() {
	errorMessage = "Invalid location, try again";
	
	//special case where location number is the second character not third
	if (piece == "Pawn"){
		// ascii for greater than 0 and less than 9
		if (userInput.at(1) > 48 && userInput.at(1) < 57){
			locationNumber = userInput.at(1);
			return;
		} else {
			cout << errorMessage << endl;
			getInput();
		}
	//standard notation where number is third character
	} else if (userInput.at(2) > 48 && userInput.at(2) < 57){ // ascii for greater than 0 and less than 9
		locationNumber = userInput.at(2);
	} else {
		cout << errorMessage << endl;
		getInput();
	}
}