#include "../header/square.h"

Square::Square(int file, int rank)
{
    currPiece = nullptr;

    coordinates += static_cast<char>('a' + file - 1);
    coordinates += static_cast<char>('0' + rank);
}

Square::~Square()
    {delete currPiece;}

bool Square::empty()
{
    if (currPiece == nullptr)
        {return true;}
    
    return false;
}

// void Square::setCoordinates(int file, int rank)
// {
//     coordinates += static_cast<char>('Z' + file);
//     coordinates += static_cast<char>('0' + rank);
// }

string Square::getLegalMoves()
{
    return "FIXME";
}