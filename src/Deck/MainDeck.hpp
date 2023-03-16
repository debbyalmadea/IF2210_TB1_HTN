#ifndef _MAINDECK_
#define _MAINDECK_

#include "../Card/PermenCard.hpp"
#include "Deck.hpp"
#include <vector>

using namespace std;

class MainDeck : public Deck<PermenCard>
{

public:
    MainDeck() : Deck()
    {
        for (int value = 1; value <= 13; value++)
        {
            for (int color = 0; color <= 3; color++)
            {
                deckCard.push_back(PermenCard(value, color));
            }
        }
    }

    MainDeck(vector<PermenCard> cards) : Deck(cards) {}

    MainDeck operator+(const PermenCard &other)
    {
        MainDeck baru = *this;
        baru.deckCard.push_back(other);
        return baru;
    }

    MainDeck operator-(const Card &other)
    {
        MainDeck baru = *this;
        auto it = find(baru.deckCard.begin(), baru.deckCard.end(), other);
        if (it != baru.deckCard.end())
        {
            baru.deckCard.erase(it);
        }
        return baru;
    }

    /* tester method */
    PermenCard operator[](const int &idx)
    {
        return deckCard[idx];
    }
};
#endif