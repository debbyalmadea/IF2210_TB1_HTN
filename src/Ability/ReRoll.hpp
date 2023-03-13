#ifndef REROLL_HPP
#define REROLL_HPP

#include "Ability.hpp"
#include <iostream>

using namespace std;

class ReRoll : public Ability
{
protected:
public:
    ReRoll() : Ability(3, -1)
    {
    }
    ReRoll(int _idPemilik) : Ability(3, _idPemilik)
    {
    }
    void use(Gamestate &g)
    {
        if (available[getIdAbility()] == 1)
        {
        }
        else if (available[getIdAbility()] == 0)
        {
            cout << "Kartu sudah pernah dipakai" << endl;
        }
        else
        {
            cout << "Kartu sudah mati" << endl;
        }
    }
};

#endif