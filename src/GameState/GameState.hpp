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
    unsigned long long giftPoint;
    bool win;
    int reverseSkip;
    PlayerQueue<Player> playerQueue;
    AbilityDeck abilityDeck;
    MainDeck mainDeck;
    Table<PermenCard> tableCards;
    ConsoleInput cli;
    int game;

public:
    Gamestate();
    unsigned long long getGiftPoint() const;
    void setGiftPoint(unsigned long long _giftPoint);
    PlayerQueue<Player> &getPlayerQueue();
    MainDeck &getMainDeck();
    void setMainDeck(const MainDeck &_mainDeck);
    void setPlayerQueue(const PlayerQueue<Player> &_p);
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