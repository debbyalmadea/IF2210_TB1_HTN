#ifndef _ABILITYDECK_
#define _ABILITYDECK_

#include "../Ability/Ability.hpp"

#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class AbilityDeck
{
protected:
    vector<Ability *> deckAbility;

public:
    AbilityDeck();

    ~AbilityDeck();

    AbilityDeck(const AbilityDeck &other);

    AbilityDeck &operator=(const AbilityDeck &other);

    int getSize();

    void shuffleDeck();

    vector<Ability *> dealCard(int n);
};
#endif