#include "../header/board.h"
#include <iostream>
using namespace std;


Board::Board() {
    //FIXME
}

Board::~Board() {
    //FIXME
}

void Board::print() {
    cout <<
        "-----------------------------------\n"
        "               BOARD               \n"
        "-----------------------------------\n"
        "Status: [Start of Game]\n"
        "\n"
        "    A   B   C   D   E   F   G   H  \n"
        "  ---------------------------------\n"
        "8 | r | n | b | q | k | b | n | r |\n"
        "  ---------------------------------\n"
        "7 | p | p | p | p | p | p | p | p |\n"
        "  ---------------------------------\n"
        "6 | . | . | . | . | . | . | . | . |\n"
        "  ---------------------------------\n"
        "5 | . | . | . | . | . | . | . | . |\n"
        "  ---------------------------------\n"
        "4 | . | . | . | . | . | . | . | . |\n"
        "  ---------------------------------\n"
        "3 | . | . | . | . | . | . | . | . |\n"
        "  ---------------------------------\n"
        "2 | P | P | P | P | P | P | P | P |\n"
        "  ---------------------------------\n"
        "1 | R | N | B | K | Q | B | N | R |\n"
        "  ---------------------------------\n";
}

Square* Board::getSquare (int file, int rank) {
    //FIXME
    Square* fixme;
    return fixme;
}

void Board::movePiece (string from, string to) {
    //FIXME
    return;
}

string Board::getLegalMoves(int file, int rank) {
    return "FIXME";
}