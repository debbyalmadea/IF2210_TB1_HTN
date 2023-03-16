#include "PermenCard.hpp"

map<string, int> PermenCard::PermenColors = {{"HIJAU", 0}, {"BIRU", 1}, {"KUNING", 2}, {"MERAH", 3}};

PermenCard::PermenCard() : Card(-1, -1, -1, -1)
{
}
PermenCard::PermenCard(int _value, int _color) : Card(-1, _color, _value, -1)
{
}

void PermenCard::printInfo()
{
    cout << "Kartu: " << value << " " << intToColorString(color) << "." << endl;
}

bool PermenCard::operator<(const Card &other) const
{
    if (this->value == other.getValue())
    {
        return this->color < other.getColor();
    }
    return this->value < other.getValue();
}
bool PermenCard::operator>(const Card &other) const
{
    if (this->value == other.getValue())
    {
        return this->color > other.getColor();
    }
    return this->value > other.getValue();
}
bool PermenCard::operator==(const Card &other) const
{
    if (this->value == other.getValue() && this->color == other.getColor())
    {
        return true;
    }
    return false;
}

string PermenCard::getColorString() const
{

    map<string, int>::iterator it;
    for (it = PermenColors.begin(); it != PermenColors.end(); ++it)
    {
        if (it->second == color)
        {
            return it->first;
        }
    }

    return "";
}

string PermenCard::intToColorString(int code)
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

int PermenCard::stringToColorInt(string color)
{
    if (PermenColors.find(color) != PermenColors.end())
    {
        return PermenColors[color];
    }
    return -1;
}

ostream &operator<<(ostream &os, const PermenCard &dt)
{
    os << "Kartu: " << dt.value << " " << dt.getColorString();
    return os;
};