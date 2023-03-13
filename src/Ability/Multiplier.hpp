#ifndef MULTIPLIER_HPP
#define MULTIPLIER_HPP

#include "Ability.hpp"
#include "BasicCommand.hpp"

#include <iostream>

using namespace std;

class Multiplier
{
protected:
    int multiplyBy;

public:
    Multiplier(int _multiplyBy)
    {
        multiplyBy = _multiplyBy;
    }
    int getMultiplyBy() const
    {
        return multiplyBy;
    }
    virtual void use(Gamestate *g)
    {
        if (multiplyBy < 0)
        {
            g->setGiftPoint(g->getGiftPoint() / (getMultiplyBy() * (-1)));
        }
        else
        {
            g->setGiftPoint(getMultiplyBy() * g->getGiftPoint());
        }
    }
};

class Quadruple : public Ability, public Multiplier
{
public:
    Quadruple() : Ability(1, -1), Multiplier(4)
    {
    }
    Quadruple(int _idPemilik) : Ability(1, _idPemilik), Multiplier(4)
    {
    }
    void use(Gamestate *g)
    {
        // cek ability
        if (available[getIdAbility()] == 1)
        {
            Multiplier::use(g);
            available[getIdAbility()] = 0;
            cout << "Kartu quadruple berhasil dipakai" << endl;
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
};

class Quarter : public Ability, public Multiplier
{
public:
    Quarter() : Ability(2, -1), Multiplier(-4) // -4 artinya 1/4
    {
    }
    Quarter(int _idPemilik) : Ability(2, _idPemilik), Multiplier(-4)
    {
    }
    void use(Gamestate *g)
    {
        // cek ability
        if (available[getIdAbility()] == 1)
        {
            Multiplier::use(g);
            available[getIdAbility()] = 0;
            cout << "Berhasil menggunakan Quarter" << endl;
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
};

class Double : public Multiplier, public BasicCommand
{
public:
    Double() : Multiplier(2), BasicCommand("Double")
    {
    }
    void use(Gamestate *g)
    {
        Multiplier::use(g);
        // print pemain yg melakukannya
    }
};

class Half : public Multiplier, public BasicCommand
{
public:
    Half() : Multiplier(-2), BasicCommand("Half")
    {
    }
    void use(Gamestate *g)
    {
        Multiplier::use(g);
        // print pemain yg melakukannya
    }
};

#endif