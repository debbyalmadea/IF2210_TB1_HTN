#ifndef _STDCARD_
#define _STDCARD_

#include "Card.hpp"
#include <string>
#include <iostream>

using namespace std;

class PermenCard : public Card
{
protected:
    static map<string, int> PermenColors;

public:
    PermenCard() : Card(-1, -1, -1, -1)
    {
    }
    PermenCard(int _value, int _color) : Card(-1, _color, _value, -1)
    {
    }

    void printInfo()
    {
        cout << "Kartu anda adalah " << value << " " << intToColorString(color) << ".";
    }

    bool operator<(const Card &other) const
    {
        if (this->value == other.getValue())
        {
            return this->color < other.getColor();
        }
        return this->value < other.getValue();
    }
    bool operator>(const Card &other) const
    {
        if (this->value == other.getValue())
        {
            return this->color > other.getColor();
        }
        return this->value > other.getValue();
    }
    bool operator==(const Card &other) const
    {
        if (this->value == other.getValue() && this->color == other.getColor())
        {
            return true;
        }
        return false;
    }

    static string intToColorString(int code)
    {
        map<string, int>::iterator it;
        for (it = PermenColors.begin(); it != PermenColors.end(); ++it)
        {
            if (it->second == code)
            {
                return it->first;
            }
        }

        return "";
    }

    static int stringToColorInt(string color)
    {
        if (PermenColors.find(color) != PermenColors.end())
        {
            return PermenColors[color];
        }
        return -1;
    }
};

map<string, int> PermenCard::PermenColors = {{"HIJAU", 0}, {"BIRU", 1}, {"KUNING", 2}, {"MERAH", 3}};
#endif