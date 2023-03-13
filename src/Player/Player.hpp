#ifndef _PLAYER_
#define _PLAYER_
#include "../Card/PermenCard.hpp"
#include <utility>
//  PLAYER class

class Player
{
protected:
    int id;
    int point;
    pair<PermenCard, PermenCard> cards;
    int idAbility;
    bool sudahGiliran;

public:
    Player() : id(0), point(0), sudahGiliran(false), idAbility(-1)
    {
        cards.first = PermenCard();
        cards.second = PermenCard();
    };
    Player(int _id) : id(_id), point(0), sudahGiliran(false), idAbility(-1)
    {
        cards.first = PermenCard();
        cards.second = PermenCard();
    };
    int getID() const
    {
        return id;
    }
    int getPoint() const
    {
        return point;
    }
    PermenCard getFirstCard() const
    {
        return cards.first;
    }
    PermenCard getSecondCard() const
    {
        return cards.second;
    }
    int getIdAbility() const
    {
        return idAbility;
    }
    pair<PermenCard, PermenCard> getBothCard() const
    {
        return cards;
    }
    void setBothCard(pair<PermenCard, PermenCard> _cards)
    {
        cards = _cards;
    }
    void setPoint(int _point)
    {
        point = _point;
    }
    void setIdAbility(int _idAbility)
    {
        idAbility = _idAbility;
    }
    void addPoint(int _point)
    {
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