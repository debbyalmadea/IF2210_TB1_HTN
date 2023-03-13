#ifndef ABILITYLESS_HPP
#define ABILITYLESS_HPP

#include "../Player/PlayerQueue.hpp"
#include "../Player/Player.hpp"
#include "Ability.hpp"
#include <iostream>

using namespace std;

class Abilityless : public Ability
{
public:
    Abilityless() : Ability(0, -1)
    {
    }
    Abilityless(int _idPemilik) : Ability(0, idPemilik)
    {
    }
    bool hasUsedAllAbility()
    {
        bool hasUsed = true;
        for (int i = 0; i < 7; i++)
        {
            if (available[i] == 1 && i != getIdAbility())
            {
                hasUsed = false;
                break;
            }
        }
        return hasUsed;
    }

    void use(int _idAbility, PlayerQueue *p, Gamestate *g)
    {
        int idDeadPlayer;
        if (hasUsedAllAbility())
        {
            cout << "Eits, ternyata semua pemain sudah memakai kartu kemampuan. Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Yah, pengunaan kartu ini sia-sia" << endl;
            setAbilityAvailability(2);
        }
        else
        {
            if (idAbility != _idAbility || getAbilityAvailability() != 1)
            {
                cout << "Eits, kamu tidak punya kartunya" << endl;
            }
            else
            {
                cout << "Silahkan pilih pemain yang kartunya ingin kamu matikan:" << endl;
                /*print semua player*/
                int count = 1;
                for (int i = 1; i <= 7; i++)
                {
                    if (idPemilik != i)
                    {
                        cout << count << ". Pemain " << i << endl;
                        count++;
                    }
                }

                cin >> idDeadPlayer;
                available[idPemilikidAbility[idDeadPlayer]] = 2;
            }
        }
    }
}

;

#endif