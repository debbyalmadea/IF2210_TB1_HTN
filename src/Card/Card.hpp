#ifndef _CARD_
#define _CARD_

#include "Valuable.hpp"
#include <map>

class Card : public Valuable
{
protected:
    int shape;
    int color;

public:
    Card(int _shape, int _color, int _value) : shape(_shape), color(_color), Valuable(_value){};

    float getValue() const
    {
        return value;
    }

    int getColor() const
    {
        return color;
    }
    int getShape() const
    {
        return shape;
    }
    void virtual printInfo() = 0;

    bool virtual operator<(const Card &other) const = 0;
    bool virtual operator>(const Card &other) const = 0;
    bool virtual operator==(const Card &other) const = 0;
};

#endif