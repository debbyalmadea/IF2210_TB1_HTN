#ifndef ABILITYLESS_HPP
#define ABILITYLESS_HPP

#include "../Player/PlayerQueue.hpp"
#include "../Player/Player.hpp"
#include "Ability.hpp"
#include <iostream>

using namespace std;

class Abilityless : public Ability
{
public:
    Abilityless();
    Abilityless(int _idPemilik);
    bool hasUsedAllAbility();
    void use(Gamestate &g);
};

#endif