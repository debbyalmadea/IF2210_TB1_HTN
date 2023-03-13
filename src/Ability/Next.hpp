#ifndef NEXT_HPP
#define NEXT_HPP
#include <iostream>
#include "BasicCommand.hpp"
#include "../GameState/GameState.hpp"

using namespace std;

class Next : public BasicCommand
{
public:
    Next();
    void use(Gamestate &g);
};

#endif