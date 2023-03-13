#ifndef SWITCH_HPP
#define SWITCH_HPP
#include "Ability.hpp"
#include "../Card/Card.hpp"
#include "../Card/PermenCard.hpp"

#include <iostream>
using namespace std;

class Switch : public Ability
{
public:
    Switch() : Ability(6, -1)
    {
    }
    Switch(int _idPemilik) : Ability(6, _idPemilik)
    {
    }
    void use(int _idAbility, PlayerQueue *p, Gamestate *g)
    {
        // Player temp;
        pair<PermenCard, PermenCard> temp;
        int idToSwitch;
        int index1, index2;
        if (_idAbility = getIdAbility() && getAbilityAvailability() == 1)
        {
            cout << "Pemain " << getIdPemilik() << " melakukan switch! \n";
            cout << "Kartumu sekarang adalah: " << endl;
            for (int i = 0; i < p->getnPlayers(); i++)
            {
                if (p->getPlayers()[i].getID() == getIdPemilik())
                {
                    temp = p->getPlayers()[i].getBothCard();
                    index1 = i;
                }
            }
            temp.first.printInfo();
            temp.second.printInfo();
            cout << "Silahkan pilih pemain yang kartunya ingin anda tukar: " << endl;
            int count = 0;
            for (int i = 0; i < p->getnPlayers(); i++)
            {
                cout << count + 1 << ". "
                     << "Pemain " << p->getPlayers()[i].getID() << endl;
                count++;
            }
            cin >> idToSwitch;
            // todo : add exception handling
            for (int i = 0; i < p->getnPlayers(); i++)
            {
                if (p->getPlayers()[i].getID() == idToSwitch)
                {
                    index2 = i;
                }
            }
            p->getPlayers()[index1].setBothCard(p->getPlayers()[index2].getBothCard());
            p->getPlayers()[index2].setBothCard(temp);
        }
    }
};

#endif