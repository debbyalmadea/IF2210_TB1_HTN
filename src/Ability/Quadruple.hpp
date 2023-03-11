#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include "Ability.hpp"
#include <iostream>

using namespace std;

class Quadruple : public Ability
{
public:
    Quadruple() : Ability("Quadruple", true, false)
    {
    }
}

;

#endif