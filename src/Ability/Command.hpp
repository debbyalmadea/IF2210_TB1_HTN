#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include "../GameState/GameState.hpp"
#include <string>
using namespace std;

class Command
{
protected:
    string type;

public:
    Command(string _type) : type(_type)
    {
    }
    virtual void use(Gamestate *g) = 0;
};

#endif