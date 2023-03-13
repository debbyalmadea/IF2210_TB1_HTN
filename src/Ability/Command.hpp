#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <string>
using namespace std;

class Gamestate;
class Command
{
protected:
    string type;

public:
    Command(string _type) : type(_type)
    {
    }
    virtual void use(Gamestate &g) = 0;
};

#endif