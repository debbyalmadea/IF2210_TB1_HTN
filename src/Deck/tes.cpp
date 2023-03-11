#include "MainDeck.hpp"
#include "../Card/PermenCard.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;
int main()
{
    MainDeck baru = MainDeck();
    baru.shuffleDeck();
    cout << baru.getSize();
    vector<PermenCard> hasil = baru.dealCard(7);
    for (auto &res : hasil)
    {
        res.printInfo();
    }
    cout << baru.getSize();
}