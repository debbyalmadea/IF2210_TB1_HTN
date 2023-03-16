#ifndef _STDCARD_
#define _STDCARD_

#include "../Card.hpp"
#include <string>
#include <iostream>

using namespace std;

class StandardCard : public Card
{
protected:
    string StandardShapes[4] = {"Club", "Diamond", "Heart", "Spades"};
    string StandardColors[2] = {"Black", "Red"};

public:
    StandardCard(int _shape, int _color, int _value) : Card(_shape, 1, _value)
    {
        if (_shape == 1 || _shape == 2)
        {
            color = 1;
        }
        else
        {
            color = 0;
        }
    }

    string getStrShape() const
    {
        return StandardShapes[this->getShape()];
    }

    string getStrColor() const
    {
        return StandardColors[this->getColor()];
    }

    void printInfo()
    {
        cout << "Kartu anda adalah " << value << " " << StandardShapes[shape] << " " << StandardColors[color];
    }

    bool operator<(const Card &other) const
    {
        if (this->value == other.getValue())
        {
            return this->shape < other.getShape();
        }
        return this->value < other.getValue();
    };
    bool operator>(const Card &other) const
    {
        if (this->value == other.getValue())
        {
            return this->shape > other.getShape();
        }
        return this->value > other.getValue();
    };
    bool operator==(const Card &other) const
    {
        if (this->value == other.getValue() && this->shape == other.getShape() && this->color == other.getColor())
        {
            return true;
        }
        return false;
    };

    friend ostream &operator<<(ostream &os, const StandardCard &dt);
};

#endif