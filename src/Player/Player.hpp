#ifndef _PLAYER_
#define _PLAYER_
#include "../Ability/Ability.hpp"
// PLAYER class

class Player
{
protected:
    int id;
    int point;
    // todo : Ability Card
    Ability ability;
    bool sudahGiliran;

public:
    Player() : id(0), point(0), sudahGiliran(false)
    {
        ability = Ability();
    };
    Player(int _id) : id(_id), point(0), sudahGiliran(false)
    {
        ability = Ability();
    };
    int getID() const
    {
        return id;
    }
    int getPoint() const
    {
        return point;
    }
    Ability getAbility() const
    {
        return ability;
    }
    void setAbility(Ability _ability)
    {
        ability = _ability;
    }
    void setPoint(int _point)
    {
        point = _point;
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