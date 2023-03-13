#ifndef NEXT_HPP
#define NEXT_HPP
#include <iostream>
#include "BasicCommand.hpp"

using namespace std;

class Next : public BasicCommand
{
public:
    Next() : BasicCommand("Next")
    {
    }
    void use(Gamestate *g)
    {
        PlayerQueue p = g->getPlayerQueue();
        p.next();
        p.displayQueue();
        g->setPlayerQueue(p);
    }
};

#endif