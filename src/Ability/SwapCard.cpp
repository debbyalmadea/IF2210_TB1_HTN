#include "SwapCard.hpp"

SwapCard::SwapCard() : Ability(5, -1)
{
}
SwapCard::SwapCard(int _idPemilik) : Ability(5, _idPemilik)
{
}
void SwapCard::swap(int choice1, int choice2, int idx1, int idx2, Gamestate &g)
{
    PermenCard temp;
    if (choice1 == 1)
    {
        temp = g.getPlayerQueue().getPlayers()[idx1].getFirstCard();
        if (choice2 == 1)
        {
            g.getPlayerQueue().getPlayer(idx1).setFirstCard(g.getPlayerQueue().getPlayer(idx2).getFirstCard());
            g.getPlayerQueue().getPlayer(idx2).setFirstCard(temp);
        }
        else if (choice2 == 2)
        {
            g.getPlayerQueue().getPlayer(idx1).setFirstCard(g.getPlayerQueue().getPlayer(idx2).getSecondCard());
            g.getPlayerQueue().getPlayer(idx2).setSecondCard(temp);
        }
    }
    else if (choice1 == 2)
    {
        temp = g.getPlayerQueue().getPlayers()[idx1].getSecondCard();
        if (choice2 == 1)
        {
            g.getPlayerQueue().getPlayer(idx1).setSecondCard(g.getPlayerQueue().getPlayer(idx2).getFirstCard());
            g.getPlayerQueue().getPlayer(idx2).setFirstCard(temp);
        }
        else if (choice2 == 2)
        {
            g.getPlayerQueue().getPlayer(idx1).setSecondCard(g.getPlayerQueue().getPlayer(idx2).getSecondCard());
            g.getPlayerQueue().getPlayer(idx2).setSecondCard(temp);
        }
    }
}
void SwapCard::use(Gamestate &g)
{
    if (available[getIdAbility()] == 1)
    {
        int idToSwitch1, index1;
        int idToSwitch2, index2;
        cout << "Silahkan pilih pemain yang kartunya ingin anda tukar: " << endl;
        int count = 0;
        for (int i = 0; i < g.getPlayerQueue().getnPlayers(); i++)
        {
            cout << count + 1 << ". "
                 << "Pemain " << g.getPlayerQueue().getPlayer(i).getID() << endl;
            count++;
        }
        cin >> idToSwitch1;
        cout << "Silahkan pilih pemain lain yang kartunya ingin anda tukar: " << endl;
        count = 0;
        for (int i = 0; i < g.getPlayerQueue().getnPlayers(); i++)
        {
            cout << count + 1 << ". "
                 << "Pemain " << g.getPlayerQueue().getPlayer(i).getID() << endl;
            count++;
        }
        cin >> idToSwitch2;
        for (int i = 0; i < g.getPlayerQueue().getnPlayers(); i++)
        {
            if (g.getPlayerQueue().getPlayer(i).getID() == idToSwitch1)
            {
                index1 = i;
            }
            else if (g.getPlayerQueue().getPlayer(i).getID() == idToSwitch2)
            {
                index2 = i;
            }
        }
        int choice1, choice2;
        cout << "Pilih kartu kanan/kiri dari pemain " << idToSwitch1 << endl;
        cout << "1. Kiri\n2. Kanan\n";
        cin >> choice1;
        cout << "Pilih kartu kanan/kiri dari pemain " << idToSwitch2 << endl;
        cout << "1. Kiri\n2. Kanan\n";
        cin >> choice2;
        swap(choice1, choice2, index1, index2, g);
    }
    else if (available[getIdAbility()] == 0)
    {
        cout << "Kartu SwapCard sudah pernah dipakai" << endl;
    }
    else
    {
        cout << "Kartu ini sudah mati" << endl;
    }
}
