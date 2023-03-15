#ifndef _CANGKULPLAYER_
#define _CANGKULPLAYER_
#include "../../Card/Bonus/StandardCard.hpp"
#include "../../InventoryHolder/InventoryHolder.hpp"
#include <iostream>
#include <utility>

using namespace std;
//  PLAYER class

class CangkulPlayer : public InventoryHolder<StandardCard>
{
protected:
    int id;
    int point;
    string name;
    vector<StandardCard> cards;
    bool sudahGiliran;

public:
    CangkulPlayer() : id(0), point(0), sudahGiliran(false), name("")
    {
    }

    CangkulPlayer(int _id, string _name) : id(_id), point(0), sudahGiliran(false), name(_name)
    {
    }

    int getID() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }

    int getPoint() const
    {
        return point;
    }

    int getSize()
    {
        return cards.size();
    }

    vector<StandardCard> getBothCard() const
    {
        return cards;
    }

    void addCard(StandardCard _card)
    {
        cards.push_back(_card);
    }

    void addCards(vector<StandardCard> _card1)
    {
        cout << "Player " << name << " has received: " << endl;
        for (auto &card : _card1)
        {
            cout << card << endl;
            cards.push_back(card);
        }
        cout << endl;
    }

    bool canDeal(StandardCard _top)
    {
        for (auto &card : cards)
        {
            if (_top.getShape() == card.getShape())
                return true;
        }
        return false;
    }

    void displayInv()
    {
        cout << "Pemain " << name << " mempunyai kartu: " << endl;
        int index = 1;
        for (auto &card : cards)
        {
            cout << index << ". " << card << endl;
            index += 1;
        }
    }

    StandardCard getCardIdx(int idx)
    {
        return cards[idx - 1];
    }
    void removeCardIdx(int idx)
    {
        cards.erase(cards.begin() + idx - 1);
    }

    vector<StandardCard> getInventory()
    {
        return cards;
    }
    void setPoint(int _point)
    {
        point = _point;
    }

    void addPoint(int _point)
    {
        if (point + _point < point)
        {
            throw "Overflow";
        }
        point += _point;
    }
    bool cekGiliran()
    {
        return sudahGiliran;
    }
    void giliranSelesai()
    {
        sudahGiliran = true;
    }
    void belumGiliran()
    {
        sudahGiliran = false;
    }
};

#endif