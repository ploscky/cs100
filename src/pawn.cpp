#include "../header/pawn.h"

Pawn::Pawn(char c)
{
    color = c;
    notation = 'P';
}

string Pawn::getMoves(string coordinates)
{
    return "FIXME";
}

void Pawn::move()
    {moved = true;}

bool Pawn::hasMoved()
    {return moved;}