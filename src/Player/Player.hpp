#ifndef _PLAYER_
#define _PLAYER_

// PLAYER class

class Player
{
protected:
    int id;
    int point;
    // todo : Ability Card
    bool sudahGiliran;

public:
    Player() : id(0), point(0), sudahGiliran(false){};
    Player(int _id) : id(_id), point(0), sudahGiliran(false){};
    int getID() const
    {
        return id;
    }
    int getPoint() const
    {
        return point;
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