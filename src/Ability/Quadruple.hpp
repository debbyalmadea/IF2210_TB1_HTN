#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include "Ability.hpp"
#include <iostream>

using namespace std;

class Quadruple : public Ability
{
public:
    Quadruple() : Ability(1, -1, false)
    {
    }
}

;

#endif