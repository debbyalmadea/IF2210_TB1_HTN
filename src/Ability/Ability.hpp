#ifndef ABILITY_HPP
#define ABILITY_HPP

#include <iostream>
#include <string>
#include "../Player/PlayerQueue.hpp"
#include "../GameState/GameState.hpp"

using namespace std;

// ABILITY class
class Ability
{
protected:
    int idAbility;
    int idPemilik;
    string abilityName[7] = {"Abilityless", "Quadruple", "Quarter", "ReRoll", "ReverseDirection", "SwapCard", "Switch"};
    static int available[7]; // 0 : ga punya, 1 : ada, 2 : mati
    static map<int, int> idPemilikidAbility;

public:
    // ctor
    Ability();
    Ability(int _idAbility, int _idPemilik);

    int getIdAbility() const;
    string getAbilityName() const;
    int getAbilityAvailability() const;
    int getIdPemilik() const;
    bool getDeadStatus() const;

    void setIdAbility(int _idAbility);
    void setAbilityAvailability(int _available);
    void setIdPemilik(int _idPemilik);

    virtual void use(int _idAbility, PlayerQueue *p, Gamestate *g) = 0;
};
#endif