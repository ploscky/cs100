#pragma once

using namespace std;

class Piece
{
    private:
        char color;
        char notation;

    public:
        Piece(char n, char c) : notation(n), color(c) {}
        
        char getColor()
            {return color;}
        
        char getNotation()
            {return notation;}
        
        void setNotation(char n)
            {notation = n;}

};