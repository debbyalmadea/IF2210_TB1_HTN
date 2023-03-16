#ifndef _ABILITYDECK_
#define _ABILITYDECK_

#include "../Ability/Ability.hpp"
#include "Deck.hpp"

#include <vector>

using namespace std;

class AbilityDeck : public Deck<Ability *>
{
public:
    AbilityDeck();

    ~AbilityDeck();

    AbilityDeck(const AbilityDeck &other);

    AbilityDeck &operator=(const AbilityDeck &other);
};
#endif