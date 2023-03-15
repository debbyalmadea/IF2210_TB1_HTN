#include "ReRoll.hpp"
ReRoll::ReRoll() : Ability(3, -1)
{
}
ReRoll::ReRoll(int _idPemilik) : Ability(3, _idPemilik)
{
}
void ReRoll::use(Gamestate &g)
{
    if (available[getIdAbility()] == 1)
    {
        for (int i = 0; i < g.getPlayerQueue().getnPlayers(); i++)
        {
            if (g.getPlayerQueue().getPlayer(i).getID() == getIdPemilik())
            {
                g.getMainDeck().operator+(g.getPlayerQueue().getPlayer(i).getFirstCard());
                g.getMainDeck().operator+(g.getPlayerQueue().getPlayer(i).getSecondCard());
                g.getMainDeck().shuffleDeck();
                PermenCard temp1 = g.getMainDeck()[0];
                PermenCard temp2 = g.getMainDeck()[1];
                g.getPlayerQueue().getPlayer(i).setFirstCard(temp1);
                g.getPlayerQueue().getPlayer(i).setSecondCard(temp2);
                g.setMainDeck(g.getMainDeck() - temp1);
                g.setMainDeck(g.getMainDeck() - temp2);
                cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
                cout << "Kamu mendapatkan 2 kartu baru yaitu : " << endl;
                g.getPlayerQueue().getPlayer(i).getFirstCard().printInfo();
                g.getPlayerQueue().getPlayer(i).getSecondCard().printInfo();
                break;
            }
        }
        available[getIdAbility()] = 0;
        PlayerQueue p = g.getPlayerQueue();
        p.next();
        g.setPlayerQueue(p);
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