#ifndef REVERSEDIRECTION_HPP
#define REVERSEDIRECTION_hpp

#include "Ability.hpp"
#include "../GameState/GameState.hpp"
#include <iostream>

using namespace std;

class ReverseDirection : public Ability
{
public:
    ReverseDirection();
    ReverseDirection(int _idPemilik);
    void use(Gamestate &g);
};

#endif