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
    Multiplier(int _multiplyBy);
    int getMultiplyBy() const;
    virtual void use(Gamestate &g);
};

class Quadruple : public Ability, public Multiplier
{
public:
    Quadruple();
    Quadruple(int _idPemilik);
    void use(Gamestate &g);
};

class Quarter : public Ability, public Multiplier
{
public:
    Quarter();
    Quarter(int _idPemilik);
    void use(Gamestate &g);
};

class Double : public Multiplier, public BasicCommand
{
public:
    Double();
    void use(Gamestate &g);
};

class Half : public Multiplier, public BasicCommand
{
public:
    Half();
    void use(Gamestate &g);
};

#endif