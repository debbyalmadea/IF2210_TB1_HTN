#include "Ability.hpp"
#include <iostream>

using namespace std;

bool Ability ::available[7] = {true, true, true, true, true, true, true};

Ability::Ability() : idAbility(-1), idPemilik(-1), isDead(false)
{
}
Ability ::Ability(int _idAbility, int _idPemilik, bool _isDead) : idAbility(_idAbility), idPemilik(_idPemilik), isDead(_isDead)
{
}
int Ability ::getIdAbility() const
{
    return idAbility;
}
string Ability ::getAbilityName() const
{
    return abilityName[idAbility];
}
bool Ability ::getAbilityAvailability() const
{
    return available[idAbility];
}
int Ability ::getIdPemilik() const
{
    return idPemilik;
}
bool Ability ::getDeadStatus() const
{
    return isDead;
}
void Ability ::setIdAbility(int _idAbility)
{
    idAbility = _idAbility;
}
void Ability ::setAbilityAvailability(bool _available)
{
    available[idAbility] = _available;
}
void Ability ::setIdPemilik(int _idPemilik)
{
    idPemilik = _idPemilik;
}
void Ability ::setDeadStatus(bool _isDead)
{
    isDead = _isDead;
}

void Ability ::use(int _idAbility)
{
    if (idAbility != _idAbility)
    {
        cout << "Eits, kamu tidak punya kartunya" << endl;
    }
}