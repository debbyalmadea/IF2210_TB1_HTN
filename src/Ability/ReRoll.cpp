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
                Player& player = g.getPlayerQueue().getPlayer(i);
                PermenCard firstCard = player.getFirstCard();
                player = player - firstCard;
                PermenCard secondCard = player.getSecondCard();
                player = player - secondCard;
                g.setMainDeck(g.getMainDeck() + firstCard);
                g.setMainDeck(g.getMainDeck() + secondCard);
                g.getMainDeck().shuffleDeck();

                PermenCard newCard1 = g.getMainDeck().getTop();
                g.setMainDeck(g.getMainDeck()-newCard1);
                PermenCard newCard2 = g.getMainDeck().getTop();
                g.setMainDeck(g.getMainDeck()-newCard2);

                player = player + newCard1;
                player = player + newCard2;

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