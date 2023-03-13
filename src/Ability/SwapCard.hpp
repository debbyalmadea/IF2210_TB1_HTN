#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP
#include "Ability.hpp"

// SWAPCARD class
class SwapCard : public Ability
{
public:
    SwapCard() : Ability(5, -1)
    {
    }
    SwapCard(int _idPemilik) : Ability(5, _idPemilik)
    {
    }
    static void swap(int choice1, int choice2, int idx1, int idx2, PlayerQueue *p)
    {
        PermenCard temp;
        if (choice1 == 1)
        {
            temp = p->getPlayers()[idx1].getFirstCard();
            if (choice2 == 1)
            {
                p->getPlayers()[idx1].setFirstCard(p->getPlayers()[idx2].getFirstCard());
                p->getPlayers()[idx2].setFirstCard(temp);
            }
            else if (choice2 == 2)
            {
                p->getPlayers()[idx1].setFirstCard(p->getPlayers()[idx2].getSecondCard());
                p->getPlayers()[idx2].setSecondCard(temp);
            }
        }
        else if (choice1 == 2)
        {
            temp = p->getPlayers()[idx1].getSecondCard();
            if (choice2 == 1)
            {
                p->getPlayers()[idx1].setSecondCard(p->getPlayers()[idx2].getFirstCard());
                p->getPlayers()[idx2].setFirstCard(temp);
            }
            else if (choice2 == 2)
            {
                p->getPlayers()[idx1].setSecondCard(p->getPlayers()[idx2].getSecondCard());
                p->getPlayers()[idx2].setSecondCard(temp);
            }
        }
    }
    void use(int _idAbility, PlayerQueue *p, Gamestate *g)
    {
        int idToSwitch1, index1;
        int idToSwitch2, index2;
        cout << "Silahkan pilih pemain yang kartunya ingin anda tukar: " << endl;
        int count = 0;
        for (int i = 0; i < p->getnPlayers(); i++)
        {
            cout << count + 1 << ". "
                 << "Pemain " << p->getPlayers()[i].getID() << endl;
            count++;
        }
        cin >> idToSwitch1;
        cout << "Silahkan pilih pemain lain yang kartunya ingin anda tukar: " << endl;
        int count = 0;
        for (int i = 0; i < p->getnPlayers(); i++)
        {
            cout << count + 1 << ". "
                 << "Pemain " << p->getPlayers()[i].getID() << endl;
            count++;
        }
        cin >> idToSwitch2;
        for (int i = 0; i < p->getnPlayers(); i++)
        {
            if (p->getPlayers()[i].getID() == idToSwitch1)
            {
                index1 = i;
            }
            else if (p->getPlayers()[i].getID() == idToSwitch2)
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
        swap(choice1, choice2, index1, index2, p);
    }
};

#endif