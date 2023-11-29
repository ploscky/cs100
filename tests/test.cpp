#include "../header/game.h"
#include "gtest/gtest.h"
using namespace std;

int main()
{
    Game g;

    cout << g.game->getLegalMoves(6,5) << endl;

    return 0;
}