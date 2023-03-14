#ifndef _PLAYER_
#define _PLAYER_
#include "../Card/PermenCard.hpp"
#include "../Ability/Ability.hpp"
#include "../InventoryHolder/InventoryHolder.hpp"

#include <utility>
//  PLAYER class

class Player : public InventoryHolder
{
protected:
    int id;
    int point;
    string name;
    pair<PermenCard, PermenCard> cards;
    Ability *ability;
    bool sudahGiliran;

public:
    Player() : id(0), point(0), sudahGiliran(false), name("")
    {
    }

    Player(int _id, string _name) : id(_id), point(0), sudahGiliran(false), name(_name)
    {
    }

    Player(const Player &other)
    {
        this->id = other.id;
        this->point = other.point;
        this->name = other.name;
        this->cards = other.cards;
        this->ability = other.ability;
        this->sudahGiliran = other.sudahGiliran;
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
    PermenCard getFirstCard() const
    {
        return cards.first;
    }
    PermenCard getSecondCard() const
    {
        return cards.second;
    }

    Ability *getAbility()
    {
        return ability;
    }

    void setAbility(Ability *_ability)
    {
        cout << "Player " << getName() << " has received ability " << _ability->getAbilityName() << endl;
        ability = _ability;
    }
    // int getIdAbility() const
    // {
    //     return idAbility;
    // }
    pair<PermenCard, PermenCard> getBothCard() const
    {
        return cards;
    }
    void setFirstCard(PermenCard _card1)
    {
        cards.first = _card1;
    }
    void setSecondCard(PermenCard _card2)
    {
        cards.second = _card2;
    }
    void setBothCard(pair<PermenCard, PermenCard> _cards)
    {
        cout << "Player " << name << " has received the following cards:" << endl;
        cout << _cards.first << endl;
        cout << _cards.second << endl
             << endl;
        cards.first = _cards.first;
        cards.second = _cards.second;
    }
    void displayInv()
    {
        cout << "Player " << name << " has the following cards:" << endl;
        cout << cards.first << endl;
        cout << cards.second << endl;
    }
    vector<PermenCard> getInventory()
    {
        vector<PermenCard> listCard;
        listCard.push_back(cards.first);
        listCard.push_back(cards.second);
        return listCard;
    }
    void setPoint(int _point)
    {
        point = _point;
    }
    // void setIdAbility(int _idAbility)
    // {
    //     idAbility = _idAbility;
    // }
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

    Player &operator=(const Player &other)
    {
        id = other.id;
        point = other.point;
        name = other.name;
        cards = other.cards;
        ability = other.ability;
        sudahGiliran = other.sudahGiliran;
        return *this;
    }
};

#endif