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
        string input;
        int idToSwitch1, index1;
        int idToSwitch2, index2;
        cout << "Masukkan id pemain yang kartunya ingin anda tukar: " << endl;
        int count = 0;
        for (int i = 0; i < g.getPlayerQueue().getnPlayers(); i++)
        {
            if (getIdPemilik() != g.getPlayerQueue().getPlayer(i).getID())
            {
                cout << count + 1 << ". "
                     << "Pemain " << g.getPlayerQueue().getPlayer(i).getID() << endl;
                count++;
            }
        }
        cin >> input;
        try
        {
            if (stoi(input) < 1 || stoi(input) > 7 || stoi(input) == getIdPemilik())
            {
                throw ExceptionIO(input);
            }
        }
        catch (invalid_argument &err)
        {
            throw ExceptionIO(input);
        }
        idToSwitch1 = stoi(input);
        cout << "Masukkan id pemain lain yang kartunya ingin anda tukar: " << endl;
        count = 0;

        for (int i = 0; i < g.getPlayerQueue().getnPlayers(); i++)
        {
            if (getIdPemilik() != g.getPlayerQueue().getPlayer(i).getID() && idToSwitch1 != g.getPlayerQueue().getPlayer(i).getID())
            {
                cout << count + 1 << ". "
                     << "Pemain " << g.getPlayerQueue().getPlayer(i).getID() << endl;
                count++;
            }
        }
        cin >> input;
        try
        {
            if (stoi(input) < 1 || stoi(input) > 7 || stoi(input) == getIdPemilik() || stoi(input) == idToSwitch1)
            {
                throw ExceptionIO(input);
            }
        }
        catch (invalid_argument &err)
        {
            throw ExceptionIO(input);
        }
        idToSwitch2 = stoi(input);
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
        g.getInputCLI(1, 2);
        choice1 = stoi(g.getInput());
        cout << "Pilih kartu kanan/kiri dari pemain " << idToSwitch2 << endl;
        cout << "1. Kiri\n2. Kanan\n";
        g.getInputCLI(1, 2);
        choice2 = stoi(g.getInput());

        swap(choice1, choice2, index1, index2, g);
        PlayerQueue p = g.getPlayerQueue();
        p.next();
        g.setPlayerQueue(p);
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
