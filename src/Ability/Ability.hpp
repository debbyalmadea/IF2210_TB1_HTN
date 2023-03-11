#ifndef ABILITY_HPP
#define ABILITY_HPP

#include <iostream>
#include <string>
// #include "../Player/PlayerQueue.hpp"

using namespace std;

// ABILITY class
class Ability
{
protected:
    string name;
    bool available;
    bool used;

public:
    Ability() : name(""), available(false), used(false)
    {
    }
    Ability(string _name, bool _available, bool _used) : name(_name), available(_available), used(_used)
    {
    }
    string getAbilityName()
    {
        return name;
    }
    bool getAbilityAvailability()
    {
        return available;
    }
    bool getUsedStatus()
    {
        return used;
    }
    // virtual void use() = 0;
};
#endif