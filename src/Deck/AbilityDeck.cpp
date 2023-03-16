#include "AbilityDeck.hpp"

#include "../Ability/Ability.hpp"
#include "../Ability/Abilityless.hpp"
#include "../Ability/Multiplier.hpp"
#include "../Ability/ReRoll.hpp"
#include "../Ability/ReverseDirection.hpp"
#include "../Ability/SwapCard.hpp"
#include "../Ability/Switch.hpp"

using namespace std;

AbilityDeck::AbilityDeck()
{
    deckCard.push_back(new Quadruple());
    deckCard.push_back(new Quarter());
    deckCard.push_back(new Switch());
    deckCard.push_back(new ReRoll());
    deckCard.push_back(new ReverseDirection());
    deckCard.push_back(new SwapCard());
    deckCard.push_back(new Abilityless());
}

AbilityDeck::~AbilityDeck()
{
    for (auto &elem : deckCard)
    {
        delete elem;
    }
}

AbilityDeck::AbilityDeck(const AbilityDeck &other)
{
    deckCard.push_back(new Quadruple());
    deckCard.push_back(new Quarter());
    deckCard.push_back(new Switch());
    deckCard.push_back(new ReRoll());
    deckCard.push_back(new ReverseDirection());
    deckCard.push_back(new SwapCard());
    deckCard.push_back(new Abilityless());
}

AbilityDeck &AbilityDeck::operator=(const AbilityDeck &other)
{
    if (&other != this)
    {
        while (deckCard.size() != 0)
        {
            Ability *baru = deckCard.back();
            delete baru;
            deckCard.pop_back();
        }
    }
    deckCard.push_back(new Quadruple());
    deckCard.push_back(new Quarter());
    deckCard.push_back(new Switch());
    deckCard.push_back(new ReRoll());
    deckCard.push_back(new ReverseDirection());
    deckCard.push_back(new SwapCard());
    deckCard.push_back(new Abilityless());
    return *this;
}