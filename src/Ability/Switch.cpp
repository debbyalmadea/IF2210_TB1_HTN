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
    ConsoleInput cli;
    if (available[getIdAbility()] == 1)
    {
        string input;
        pair<PermenCard, PermenCard> temp;
        int idToSwitch;
        int index1, index2;
        cout << "Pemain " << getIdPemilik() << " melakukan switch! \n";
        cout << "Kartumu sekarang adalah: " << endl;
        // cout << g.getPlayerQueue().getnPlayers() << endl;
        for (int i = 0; i < g.getPlayerQueue().getnPlayers(); i++)
        {
            if (g.getPlayerQueue().getPlayer(i).getID() == getIdPemilik())
            {
                temp = g.getPlayerQueue().getPlayer(i).getBothCard();
                index1 = i;
            }
        }
        temp.first.printInfo();
        temp.second.printInfo();
        cout << endl;
        for (int i = 0; i < g.getPlayerQueue().getnPlayers(); i++)
        {
            if (g.getPlayerQueue().getPlayer(i).getID() != getIdPemilik())
            {
                cout << "Pemain " << g.getPlayerQueue().getPlayer(i).getID() << " - "
                     << g.getPlayerQueue().getPlayer(i).getName() << endl;
            }
        }
        cout << endl
             << "Masukkan id pemain yang kartunya ingin anda tukar: " << endl;
        vector<int> except = {getIdPemilik()};
        idToSwitch = cli.getInputInt(1, 7, except);
        for (int i = 0; i < g.getPlayerQueue().getnPlayers(); i++)
        {
            if (g.getPlayerQueue().getPlayer(i).getID() == idToSwitch)
            {
                index2 = i;
            }
        }
        g.getPlayerQueue().getPlayer(index1).setBothCard(g.getPlayerQueue().getPlayer(index2).getBothCard());
        // g.getPlayerQueue().getPlayer(index1).getFirstCard().printInfo();
        g.getPlayerQueue().getPlayer(index2).setBothCard(temp);
        PlayerQueue<Player> p = g.getPlayerQueue();
        p.next();
        g.setPlayerQueue(p);
        available[getIdAbility()] = 0;
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