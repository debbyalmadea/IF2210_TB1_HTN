#include "GameState/GameState.hpp"

int main()
{
    int again = 1;
    while (again == 1)
    {
        Gamestate game;
        again = game.start();
    }
    return 0;
}