#ifndef SWITCH_HPP
#define SWITCH_HPP
#include "Ability.hpp"
#include "../Card/Card.hpp"
#include "../Card/PermenCard.hpp"
#include "../GameState/GameState.hpp"

#include <iostream>
using namespace std;

class Switch : public Ability
{
public:
    Switch();
    Switch(int _idPemilik);
    void use(Gamestate &g);
};

#endif