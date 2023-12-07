#include "../header/game.h"
#include <iostream>
using namespace std;

int main() 
{
    Game g;
    string input;

    while (true)
    {
        g.mainMenu();

        cin >> input;

        if (input == "1")
            {g.play();}
        else if (input == "2")
            {g.printInstructions();}
        else if (input == "3")
            {break;}
        else
            {cout << "Invalid input, please try again.\n";}
    }
    return 0;
}