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
    int idAbility;
    int idPemilik;
    bool isDead;
    string abilityName[7] = {"Abilityless", "Quadruple", "Quarter", "ReRoll", "ReverseDirection", "SwapCard", "Switch"};
    static bool available[7];

public:
    // ctor
    Ability();
    Ability(int _idAbility, int _idPemilik, bool isDead);

    int getIdAbility() const;
    string getAbilityName() const;
    bool getAbilityAvailability() const;
    int getIdPemilik() const;
    bool getDeadStatus() const;

    void setIdAbility(int _idAbility);
    void setAbilityAvailability(bool _available);
    void setIdPemilik(int _idPemilik);
    void setDeadStatus(bool _isDead);

    virtual void use(int _idAbility);
};
#endif