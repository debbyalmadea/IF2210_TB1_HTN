#ifndef TABLE_HPP
#define TABLE_HPP

#include <vector>
#include <iostream>

using namespace std;
#include "../Card/PermenCard.hpp"
#include "../InventoryHolder/InventoryHolder.hpp"
// INVENTORYHOLDER class

template <typename T>
class Table : public InventoryHolder<T>
{
protected:
    vector<T> tableCards;

public:
    void addCard(T kartu)
    {
        tableCards.push_back(kartu);
    }

    vector<T> getInventory()
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