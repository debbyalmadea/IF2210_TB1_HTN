#ifndef MULTIPLIER_HPP
#define MULTIPLIER_HPP

#include "Ability.hpp"

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
    virtual void use(PlayerQueue *p, Gamestate *g)
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
    void use(int _idAbility, PlayerQueue *p, Gamestate *g)
    {
        // cek ability
        Multiplier::use(p, g);
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
    void use(int _idAbility, PlayerQueue *p, Gamestate *g)
    {
        // cek ability
        Multiplier::use(p, g);
    }
};

class Double : public Multiplier
{
public:
    Double() : Multiplier(2)
    {
    }
    void use(PlayerQueue *p, Gamestate *g)
    {
        Multiplier::use(p, g);
        // print pemain yg melakukannya
    }
};

class Half : public Multiplier
{
public:
    Half() : Multiplier(-2)
    {
    }
    void use(PlayerQueue *p, Gamestate *g)
    {
        Multiplier::use(p, g);
        // print pemain yg melakukannya
    }
};

#endif