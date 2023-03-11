#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP
#include "Ability.hpp"
#include "../Player/PlayerQueue.hpp"

// SWAPCARD class
class SwapCard : public Ability
{
public:
    void use(PlayerQueue p)
    {
        int choice1, choice2;
        if (available)
        {
            }
        else
        {
            cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability " << name << endl;
        }
    }
};

#endif