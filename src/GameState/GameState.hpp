#ifndef Gamestate_HPP
#define Gamestate_HPP
#include "../Player/PlayerQueue.hpp"
#include "../IO/FileReader.hpp"
#include "../IO/ConsoleInput.hpp"
#include "../Deck/MainDeck.hpp"
#include "../Deck/AbilityDeck.hpp"
#include "../Ability/CommandInclude.hpp"
#include "../Table/Table.hpp"
#include "../Exception/exception.hpp"
#include "../Exception/ExceptionIO.hpp"
#include "../Exception/exceptionCard.hpp"
#include "../Combo/ComboTable.hpp"
#include "../Template/MaxTemp.h"

#include <iostream>
using namespace std;
// game state class

class Gamestate
{
protected:
    int round;
    int playerCount;
    unsigned int giftPoint;
    bool win;
    PlayerQueue playerQueue;
    AbilityDeck abilityDeck;
    MainDeck mainDeck;
    Table tableCards;
    ConsoleInput cli;
    int game;

public:
    Gamestate();
    int getGiftPoint() const;
    void setGiftPoint(int _giftPoint);
    PlayerQueue &getPlayerQueue();
    MainDeck &getMainDeck();
    void setMainDeck(const MainDeck &_mainDeck);
    void setPlayerQueue(const PlayerQueue &_p);
    void setNewPlayer();
    void executeCommand();
    string getInput();
    void getInputCLI();
    void clearInput();
    void getInputCLI(int min, int max);
    void displayCurrentState();
    void nextRound();
    void dealPlayers();
    void dealTable();
    void dealAbility();
    void evaluateSession();
    void resetSession();
    int start();
};

#endif