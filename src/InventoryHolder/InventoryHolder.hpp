#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <vector>
#include "../Card/PermenCard.hpp"
// INVENTORYHOLDER class

class InventoryHolder
{
public:
    virtual vector<PermenCard> getInventory() = 0;
    virtual void displayInv() = 0;
};
#endif