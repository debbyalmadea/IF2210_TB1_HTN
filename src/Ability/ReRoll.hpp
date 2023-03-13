#ifndef REROLL_HPP
#define REROLL_HPP

#include "Ability.hpp"
#include <iostream>

using namespace std;

class ReRoll : public Ability
{
protected:
public:
    void use(int
                 _idAbility,
             PlayerQueue *p, Gamestate *g)
    {
        if (getIdAbility() == _idAbility)
        {
        }
    }
};

#endif