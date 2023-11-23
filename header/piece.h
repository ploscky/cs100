#pragma once

#include <string>
#include <queue>

using namespace std;

class Piece
{
    protected:
        char color;
        char notation;
        bool moved;

    public:
        Piece(char, char); // (color, notation)
        char getColor()             {return color;}
        char getNotation()          {return notation;}
        void setNotation(char n)    {notation = n;}
        void move()                 {moved = true;}
        bool hasMoved()             {return moved;}
};