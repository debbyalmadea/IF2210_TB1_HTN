#ifndef _PLAYER_
#define _PLAYER_
#include "../Card/PermenCard.hpp"
#include "../Ability/Ability.hpp"
#include "../InventoryHolder/InventoryHolder.hpp"

#include <utility>
#include <climits>
//  PLAYER class

class Player : public InventoryHolder<PermenCard>
{
protected:
    int id;
    unsigned int point;
    string name;
    pair<PermenCard, PermenCard> cards;
    Ability *ability;
    bool sudahGiliran;

public:
    Player() : id(0), point(0), sudahGiliran(false), name(""){
    }

    Player(int _id, string _name) : id(_id), point(0), sudahGiliran(false), name(_name)
    {
    }

    int getID() const
    {
        return id;
    }

    int getSize()
    {
        return 2;
    }

    string getName() const
    {
        return name;
    }

    unsigned int getPoint() const
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
        cout << "Pemain " << getName() << " mendapatkan kartu ability " << _ability->getAbilityName() << endl;
        ability = _ability;
    }

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
        cout << "Pemain " << name << " menerima kartu:" << endl;
        cout << _cards.first << endl;
        cout << _cards.second << endl
             << endl;
        cards.first = _cards.first;
        cards.second = _cards.second;
    }
    void displayInv()
    {
        cout << "Pemain " << name << " memiliki point sebesar " << point << endl;
        cout << "Kartu yang dimiliki:" << endl;
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
    void setPoint(unsigned int _point)
    {
        point = _point;
    }

    void addPoint(unsigned long long _point)
    {
        if (point + _point < point || _point > (UINT_MAX))
        {
            this->point = UINT_MAX;
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

    bool operator==(const Player &other) const
    {
        return this->point == other.point;
    }

    bool operator<(const Player &other) const
    {
        return this->point < other.point;
    }

    bool operator>(const Player &other) const
    {
        return this->point > other.point;
    }

    Player operator+(const PermenCard& other) {
        Player baru = *this;
        if (baru.cards.first.getValue() == -1) {
            baru.setFirstCard(other);
        } else if (baru.cards.second.getValue() == -1) {
            baru.setSecondCard(other);
        }
        return baru;
    }

    Player operator-(const PermenCard& other) {
        Player baru = *this;
        if (baru.cards.first == other) {
            baru.setFirstCard(PermenCard());
        } else if (cards.second == other) {
            baru.setSecondCard(PermenCard());
        }
        return baru;
    }
};

#endif