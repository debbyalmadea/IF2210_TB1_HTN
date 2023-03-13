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
    PermenCard();
    PermenCard(int _value, int _color);

    void printInfo();
    bool operator<(const Card &other) const;
    bool operator>(const Card &other) const;
    bool operator==(const Card &other) const;

    static string intToColorString(int code);

    static int stringToColorInt(string color);
};

#endif