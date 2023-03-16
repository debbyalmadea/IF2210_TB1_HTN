#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <vector>
// INVENTORYHOLDER class

template <class T>
class InventoryHolder
{
public:
    virtual vector<T> getInventory() = 0;
    virtual void displayInv() = 0;
};
#endif