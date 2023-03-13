#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include "../Player/PlayerQueue.hpp"

// game state class

class Gamestate
{
protected:
    int giftPoint = 1;
    PlayerQueue p;

public:
    Gamestate(PlayerQueue _p) : giftPoint(1)
    {
        p = PlayerQueue();
        // p = _p;
    }
    int getGiftPoint() const
    {
        return giftPoint;
    }
    void setGiftPoint(int _giftPoint)
    {
        giftPoint = _giftPoint;
    }
    PlayerQueue getPlayerQueue() const
    {
        return p;
    }
    void setPlayerQueue(PlayerQueue _p)
    {
        p = _p;
    }
}

;

#endif