#ifndef BASIC_COMMAND_HPP
#define BASIC_COMMAND_HPP

#include <iostream>
#include <string>
#include "Command.hpp"
#include "../Player/PlayerQueue.hpp"
#include "../Player/Player.hpp"

class BasicCommand : public Command
{
protected:
    string name;

public:
    BasicCommand(string _name) : Command("basic")
    {
        name = _name;
    }
    virtual void use(Gamestate *g) = 0;
};

#endif