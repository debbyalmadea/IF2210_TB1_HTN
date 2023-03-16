#ifndef DECK_HPP
#define DECK_HPP

#include "../InventoryHolder/InventoryHolder.hpp"
#include <vector>
#include <algorithm>
#include <random>

template <class T>
class Deck : public InventoryHolder<T>
{
protected:
    vector<T> deckCard;

public:
    Deck() {}
    Deck(vector<T> cards)
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

    vector<T> dealCard(int n)
    {
        if (deckCard.size() < n) {
            cout << n << endl;
            throw "Deck too small";
        }

        vector<T> baru;
        for (int i = 0; i < n; i++)
        {
            baru.push_back(deckCard.back());
            deckCard.pop_back();
        }
        return baru;
    }

    vector<T> getInventory()
    {
        return deckCard;
    }

    void displayInv()
    {
        for (auto &it : deckCard)
        {
            cout << it << endl;
        }
    }
};
#endif