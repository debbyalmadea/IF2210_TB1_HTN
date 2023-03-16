#ifndef _PRMCARD_
#define _PRMCARD_

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
    string getColorString() const;
    bool operator<(const Card &other) const;
    bool operator>(const Card &other) const;
    bool operator==(const Card &other) const;

    friend ostream &operator<<(ostream &os, const PermenCard &dt);

    static string intToColorString(int code);

    static int stringToColorInt(string color);
};

#endif