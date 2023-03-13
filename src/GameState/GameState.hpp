#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

// game state class

class Gamestate
{
protected:
    int giftPoint = 1;

public:
    Gamestate() : giftPoint(1)
    {
    }
    int getGiftPoint() const
    {
        return giftPoint;
    }
    void setGiftPoint(int _giftPoint)
    {
        giftPoint = _giftPoint;
    }
}

;

#endif