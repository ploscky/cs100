#pragma once

#include <string>

using namespace std;

class Piece
{
    protected:
        char color;
        char notation;

    public:
        char getColor()
            {return color;}
        
        char getNotation()
            {return notation;}
        
        void setNotation(char n)
            {notation = n;}

        virtual string getMoves(string) = 0;
};