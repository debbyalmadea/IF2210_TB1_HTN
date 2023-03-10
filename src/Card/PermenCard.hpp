#ifndef _STDCARD_
#define _STDCARD_

#include "Card.hpp"
#include <string>
#include <iostream>

using namespace std;

class PermenCard : public Card
{
protected:
    string PermenColors[4] = {"Hijau", "Biru", "Kuning", "Merah"};

public:
    PermenCard(int _value, int _color) : Card(-1, _color, _value, -1)
    {
    }

    void printInfo()
    {
        cout << "Kartu anda adalah " << value << " " << PermenColors[color] << ".";
    }

    bool operator<(const Card &other)
    {
        if (this->value == other.getValue())
        {
            return this->color < other.getColor();
        }
        return this->value < other.getValue();
    };
    bool operator>(const Card &other)
    {
        if (this->value == other.getValue())
        {
            return this->color > other.getColor();
        }
        return this->value > other.getValue();
    };
    bool operator==(const Card &other)
    {
        if (this->value == other.getValue() && this->color == other.getColor())
        {
            return true;
        }
        return false;
    };
};
#endif