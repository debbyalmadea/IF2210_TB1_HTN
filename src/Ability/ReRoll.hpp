#ifndef REROLL_HPP
#define REROLL_HPP

#include "Ability.hpp"
#include <iostream>

using namespace std;

class ReRoll : public Ability
{
protected:
public:
    ReRoll() : Ability(3, -1)
    {
    }
    ReRoll(int _idPemilik) : Ability(3, _idPemilik)
    {
    }
    void use(int _idAbility, PlayerQueue *p, Gamestate *g)
    {
        if (getIdAbility() == _idAbility)
        {
        }
    }
};

#endif