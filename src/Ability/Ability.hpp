#ifndef ABILITY_HPP
#define ABILITY_HPP

#include <iostream>
#include <string>
#include <map>
#include "Command.hpp"

using namespace std;

// ABILITY class
class Ability : public Command
{
protected:
    int idAbility;
    int idPemilik;
    string abilityName[7] = {"ABILITYLESS", "QUADRUPLE", "QUARTER", "REROLL", "REVERSEDIRECTION", "SWAPCARD", "SWITCH"};
    static int available[7]; // 0 : ga punya atau pernah punya terus dipake, 1 : ada bs dipake, 2 : mati (kena abilityless), indeksnya berdasarkan idAbility
    static map<int, int> idPemilikidAbility;

public:
    // ctorSS
    Ability();
    Ability(int _idAbility, int _idPemilik);
    virtual ~Ability() {}

    void static resetAbilityState()
    {
        for (int i = 0; i < 7; i++)
        {
            available[i] = 1;
        }
        idPemilikidAbility.clear();
    }

    int getIdAbility() const;
    string getAbilityName() const;
    int getAbilityAvailability() const;
    int getIdPemilik() const;
    bool getDeadStatus() const;

    void setIdAbility(int _idAbility);
    void setAbilityAvailability(int _available);
    void setAbilityAvailability(int _idAbility, int _available);
    void setIdPemilik(int _idPemilik);

    virtual void use(Gamestate &g) = 0;
};
#endif