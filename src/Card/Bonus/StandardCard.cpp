#include "StandardCard.hpp"

ostream &operator<<(ostream &os, const StandardCard &dt)
{
    os << "Kartu: " << dt.getValue() << " " << dt.getStrColor() << " " << dt.getStrShape();
    return os;
};