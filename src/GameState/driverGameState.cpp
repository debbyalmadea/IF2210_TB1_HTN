#include "GameState.hpp"

int main()
{
    int again = 1;
    while (again)
    {
        Gamestate game;
        again = game.start();
    }
    return 0;
}