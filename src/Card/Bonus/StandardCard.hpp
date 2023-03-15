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
    StandardCard(int _shape, int _color, int _value) : Card(_shape, _color, _value, false)
    {
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

ostream &operator<<(ostream &os, const StandardCard &dt)
{
    os << "Kartu: " << dt.value << " " << dt.StandardShapes[dt.shape] << " " << dt.StandardColors[dt.color];
    return os;
}
#endif