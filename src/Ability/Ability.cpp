#include "Ability.hpp"
#include <iostream>

using namespace std;

int Ability ::available[7] = {1, 1, 1, 1, 1, 1, 1};
map<int, int> Ability ::idPemilikidAbility;

Ability::Ability() : idAbility(-1), idPemilik(-1), Command("ability")
{
    idPemilikidAbility[idPemilik] = idAbility;
}
Ability ::Ability(int _idAbility, int _idPemilik) : idAbility(_idAbility), idPemilik(_idPemilik), Command("ability")
{
    idPemilikidAbility[idPemilik] = idAbility;
}
int Ability ::getIdAbility() const
{
    return idAbility;
}
string Ability ::getAbilityName() const
{
    return abilityName[idAbility];
}
int Ability ::getAbilityAvailability() const
{
    return available[idAbility];
}
int Ability ::getIdPemilik() const
{
    return idPemilik;
}
bool Ability ::getDeadStatus() const
{
    return (available[idAbility] == 2);
}
void Ability ::setIdAbility(int _idAbility)
{
    idAbility = _idAbility;
}
void Ability ::setAbilityAvailability(int _available)
{
    available[idAbility] = _available;
}
void Ability ::setIdPemilik(int _idPemilik)
{
    idPemilik = _idPemilik;
}
