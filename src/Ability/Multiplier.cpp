#include "Multiplier.hpp"
#include "../GameState/GameState.hpp"
Multiplier::Multiplier(int _multiplyBy)
{
    multiplyBy = _multiplyBy;
}
int Multiplier::getMultiplyBy() const
{
    return multiplyBy;
}
void Multiplier::use(Gamestate &g)
{
    if (multiplyBy < 0)
    {
        g.setGiftPoint(g.getGiftPoint() / (getMultiplyBy() * (-1)));
    }
    else
    {
        g.setGiftPoint(getMultiplyBy() * g.getGiftPoint());
    }
    PlayerQueue<Player> p = g.getPlayerQueue();
    p.next();
    g.setPlayerQueue(p);
}

Quadruple::Quadruple() : Ability(1, -1), Multiplier(4)
{
}
Quadruple::Quadruple(int _idPemilik) : Ability(1, _idPemilik), Multiplier(4)
{
}
void Quadruple::use(Gamestate &g)
{
    // cek ability
    if (available[getIdAbility()] == 1)
    {
        cout << "Kartu quadruple berhasil dipakai" << endl;
        Multiplier::use(g);
        available[getIdAbility()] = 0;
    }
    else if (available[getIdAbility()] == 2)
    {
        cout << "Kartu quadruple sudah mati" << endl;
    }
    else
    {
        cout << "Kartu quadruple sudah pernah dipakai" << endl;
    }
}

Quarter::Quarter() : Ability(2, -1), Multiplier(-4) // -4 artinya 1/4
{
}
Quarter::Quarter(int _idPemilik) : Ability(2, _idPemilik), Multiplier(-4)
{
}
void Quarter::use(Gamestate &g)
{
    // cek ability
    if (g.getGiftPoint() == 1)
    {
        return;
    }
    if (available[getIdAbility()] == 1)
    {
        cout << "Berhasil menggunakan Quarter" << endl;
        Multiplier::use(g);
        available[getIdAbility()] = 0;
    }
    else if (available[getIdAbility()] == 2)
    {
        cout << "Kartu quarter sudah mati" << endl;
    }
    else
    {
        cout << "Kartu quarter sudah pernah dipakai" << endl;
    }
}

Double::Double() : Multiplier(2), BasicCommand("Double")
{
}
void Double::use(Gamestate &g)
{
    Multiplier::use(g);
    // print pemain yg melakukannya
}

Half::Half() : Multiplier(-2), BasicCommand("Half")
{
}
void Half::use(Gamestate &g)
{
    cout << "Berhasil menggunakan Half" << endl;
    if (g.getGiftPoint() == 1)
    {
        return;
    }
    Multiplier::use(g);
    // print pemain yg melakukannya
}