#ifndef REROLL_HPP
#define REROLL_HPP

#include "Ability.hpp"
#include "../GameState/GameState.hpp"
#include <iostream>

using namespace std;

class ReRoll : public Ability
{
protected:
public:
    ReRoll();
    ReRoll(int _idPemilik);
    void use(Gamestate &g);
};

#endif