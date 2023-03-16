#ifndef _MAINDECK_
#define _MAINDECK_

#include "../../Card/Bonus/StandardCard.hpp"
#include "../Deck.hpp"
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class CangkulDeck : public Deck<StandardCard>
{

public:
    CangkulDeck();
};
#endif