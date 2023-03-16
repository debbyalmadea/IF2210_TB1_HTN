#include "CangkulDeck.hpp"

#include "../../Card/Bonus/StandardCard.hpp"
#include "../Deck.hpp"
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

CangkulDeck::CangkulDeck() : Deck()
{
    for (int shape = 0; shape <= 3; shape++)
    {
        for (int value = 1; value <= 13; value++)
        {
            deckCard.push_back(StandardCard(shape, value));
        }
    }
};