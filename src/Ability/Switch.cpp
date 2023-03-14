#include "Switch.hpp"

#include <iostream>
using namespace std;

Switch::Switch() : Ability(6, -1)
{
}
Switch::Switch(int _idPemilik) : Ability(6, _idPemilik)
{
}
void Switch::use(Gamestate &g)
{
    // Player temp;
    if (available[getIdAbility()] == 1)
    {
        pair<PermenCard, PermenCard> temp;
        int idToSwitch;
        int index1, index2;
        cout << "Pemain " << getIdPemilik() << " melakukan switch! \n";
        cout << "Kartumu sekarang adalah: " << endl;
        cout << g.getPlayerQueue().getnPlayers() << endl;
        for (int i = 0; i < g.getPlayerQueue().getnPlayers(); i++)
        {
            cout << "idPemilik1 " << g.getPlayerQueue().getPlayer(i).getID() << endl;
            cout << "idPemilik2 " << getIdPemilik() << endl;
            if (g.getPlayerQueue().getPlayer(i).getID() == getIdPemilik())
            {
                temp = g.getPlayerQueue().getPlayer(i).getBothCard();
                index1 = i;
            }
        }
        cout << "index1 " << index1 << endl;
        temp.first.printInfo();
        temp.second.printInfo();
        cout << "Silahkan pilih pemain yang kartunya ingin anda tukar: " << endl;
        int count = 0;
        for (int i = 0; i < g.getPlayerQueue().getnPlayers(); i++)
        {
            cout << count + 1 << ". "
                 << "Pemain " << g.getPlayerQueue().getPlayer(i).getID() << endl;
            count++;
        }
        cin >> idToSwitch;
        // todo : add exception handling
        for (int i = 0; i < g.getPlayerQueue().getnPlayers(); i++)
        {
            if (g.getPlayerQueue().getPlayer(i).getID() == idToSwitch)
            {
                index2 = i;
            }
        }
        g.getPlayerQueue().getPlayer(index1).setBothCard(g.getPlayerQueue().getPlayer(index2).getBothCard());
        g.getPlayerQueue().getPlayer(index1).getFirstCard().printInfo();
        g.getPlayerQueue().getPlayer(index2).setBothCard(temp);
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