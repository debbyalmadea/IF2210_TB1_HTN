#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP
#include "Ability.hpp"
#include "../GameState/GameState.hpp"

// SWAPCARD class
class SwapCard : public Ability
{
public:
    SwapCard();
    SwapCard(int _idPemilik);
    static void swap(int choice1, int choice2, int idx1, int idx2, Gamestate &g);
    void use(Gamestate &g);
};

#endif