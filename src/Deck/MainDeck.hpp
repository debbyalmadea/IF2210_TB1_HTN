#ifndef _MAINDECK_
#define _MAINDECK_

#include "../Card/PermenCard.hpp"
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class MainDeck
{
protected:
    vector<PermenCard> deckCard;

public:
    MainDeck()
    {
        for (int value = 1; value <= 13; value++)
        {
            for (int color = 0; color <= 3; color++)
            {
                deckCard.push_back(PermenCard(value, color));
            }
        }
    }

    MainDeck(vector<PermenCard> cards)
    {
        deckCard = cards;
    }

    int getSize()
    {
        return deckCard.size();
    }

    void shuffleDeck()
    {
        shuffle(deckCard.begin(), deckCard.end(), random_device());
    }

    vector<PermenCard> dealCard(int n)
    {
        if (deckCard.size() < n)
            throw "Deck too small";

        vector<PermenCard> baru;
        for (int i = 0; i < n; i++)
        {
            baru.push_back(deckCard.back());
            deckCard.pop_back();
        }
        return baru;
    }

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
};
#endif