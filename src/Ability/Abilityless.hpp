#ifndef ABILITYLESS_HPP
#define ABILITYLESS_HPP

#include "Ability.hpp"
#include <iostream>

using namespace std;

class Abilityless : public Ability
{
public:
    Abilityless() : Ability(0, -1, false)
    {
    }
    Abilityless(int _idPemilik) : Ability(0, idPemilik, false)
    {
    }
    bool hasUsedAllAbility()
    {
        bool hasUsed = true;
        for (int i = 0; i < 7; i++)
        {
            if (available[i] == true && i != getIdAbility())
            {
                hasUsed = false;
                break;
            }
        }
        return hasUsed;
    }
    void use(int _idAbility, Ability *target)
    {
        Ability ::use(_idAbility);
        if (_idAbility == _idAbility)
        {
            if (target->getAbilityAvailability() == false)
            {
                cout << "Kartu ability pemain" << target->getIdPemilik() << " telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia." << endl;
            }
            else
            {
                cout << "Kartu ability pemain " << target->getIdPemilik() << " telah dimatikan." << endl;
                target->setAbilityAvailability(false);
            }
        }
        available[idAbility] = false;
    }
}

;

#endif