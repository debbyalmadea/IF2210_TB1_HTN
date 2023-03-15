#ifndef _CANGKULPLAYER_
#define _CANGKULPLAYER_
#include "../../Card/Bonus/StandardCard.hpp"
#include "../../InventoryHolder/InventoryHolder.hpp"

#include <utility>
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

    vector<StandardCard> getBothCard() const
    {
        return cards;
    }

    void addCard(StandardCard _card1)
    {
        cards.push_back(_card1);
    }

    void displayInv()
    {
        cout << "Pemain " << name << " mempunyai kartu:" << endl;
        for (auto &card : cards)
        {
            cout << card << endl;
        }
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