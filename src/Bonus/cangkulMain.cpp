#include "../GameState/Bonus/CangkulState.hpp"

// g++ cangkulMain.cpp ../Card/Bonus/*.cpp ../GameState/Bonus/*.cpp ../Deck/Bonus/*.cpp ../Exception/*.cpp -o main -std=c++17
int main()
{
    int again = 1;
    while (again)
    {
        CangkulState game;
        again = game.start();
    }
    return 0;
}