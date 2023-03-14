#include "AbilityDeck.hpp"

#include "../Card/PermenCard.hpp"
#include "../Ability/Ability.hpp"
#include "../Ability/Abilityless.hpp"
#include "../Ability/Multiplier.hpp"
#include "../Ability/ReRoll.hpp"
#include "../Ability/ReverseDirection.hpp"
#include "../Ability/SwapCard.hpp"
#include "../Ability/Switch.hpp"

#include "../InventoryHolder/InventoryHolder.hpp"
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

AbilityDeck::AbilityDeck()
{
    deckAbility.push_back(new Quadruple());
    deckAbility.push_back(new Quarter());
    deckAbility.push_back(new Switch());
    deckAbility.push_back(new ReRoll());
    deckAbility.push_back(new ReverseDirection());
    deckAbility.push_back(new SwapCard());
    deckAbility.push_back(new Abilityless());
}

AbilityDeck::~AbilityDeck()
{
    for (auto &elem : deckAbility)
    {
        delete elem;
    }
}

AbilityDeck::AbilityDeck(const AbilityDeck &other)
{
    deckAbility.push_back(new Quadruple());
    // deckAbility.push_back(new Quarter());
    // deckAbility.push_back(new Switch());
    // deckAbility.push_back(new ReRoll());
    // deckAbility.push_back(new ReverseDirection());
    // deckAbility.push_back(new ReRoll());
    // deckAbility.push_back(new Abilityless());
}

AbilityDeck &AbilityDeck::operator=(const AbilityDeck &other)
{
    if (&other != this)
    {
        deckAbility.push_back(new Quadruple());
        // deckAbility.push_back(new Quarter());
        // deckAbility.push_back(new Switch());
        // deckAbility.push_back(new ReRoll());
        // deckAbility.push_back(new ReverseDirection());
        // deckAbility.push_back(new ReRoll());
        // deckAbility.push_back(new Abilityless());
    }
    return *this;
}

int AbilityDeck::getSize()
{
    return deckAbility.size();
}

void AbilityDeck::shuffleDeck()
{
    shuffle(deckAbility.begin(), deckAbility.end(), random_device());
}

vector<Ability *> AbilityDeck::dealCard(int n)
{
    if (deckAbility.size() < n)
        throw "Deck too small";

    vector<Ability *> baru;
    for (int i = 0; i < n; i++)
    {
        baru.push_back(deckAbility.back());
        deckAbility.pop_back();
    }
    return baru;
}