#ifndef ABILITYLESS_HPP
#define ABILITYLESS_HPP

#include "Ability.hpp"
#include <iostream>

using namespace std;

class Abilityless : public Ability
{
public:
    Abilityless() : Ability("Abilityless", true, false)
    {
    }
    void use(int idPemain, PlayerQueue p)
    {
        for (int i = 0; i < p.getnPlayers(); i++)
        {
            if (p.getPlayers()[i].getID() == idPemain)
            {
                if (p.getPlayers()[i].getAbility().getUsedStatus() == true)
                {
                    cout << "Kartu ability " << p.getPlayers()[i].getID() << " telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia" << endl;
                }
                else
                {
                }
            }
        }
    }
}

;

#endif