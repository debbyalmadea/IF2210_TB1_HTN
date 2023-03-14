#include "Next.hpp"

Next::Next() : BasicCommand("Next")
{
}
void Next::use(Gamestate &g)
{
    PlayerQueue p = g.getPlayerQueue();
    p.next();
    // p.displayQueue();
    g.setPlayerQueue(p);
}