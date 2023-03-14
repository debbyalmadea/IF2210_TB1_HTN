#ifndef TABLE_HPP
#define TABLE_HPP

#include <vector>
#include <iostream>

using namespace std;
#include "../Card/PermenCard.hpp"
#include "../InventoryHolder/InventoryHolder.hpp"
// INVENTORYHOLDER class

class Table : public InventoryHolder<PermenCard>
{
protected:
    vector<PermenCard> tableCards;

public:
    void addCard(PermenCard kartu)
    {
        tableCards.push_back(kartu);
    }

    vector<PermenCard> getInventory()
    {
        return tableCards;
    };
    void displayInv()
    {
        cout << "Kartu di meja adalah sebagai berikut" << endl;
        int index = 1;
        for (auto &card : tableCards)
        {
            cout << index << ". " << card << endl;
            index += 1;
        }
    };
};
#endif