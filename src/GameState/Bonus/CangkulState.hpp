#ifndef _Gamestate_HPP_
#define _Gamestate_HPP_

#include "../../Card/Bonus/StandardCard.hpp"
#include "../../Player/PlayerQueue.hpp"
#include "../../Deck/Bonus/CangkulDeck.hpp"
#include "../../Table/Table.hpp"
#include "../../IO/ConsoleInput.hpp"
#include "../../Player/Bonus/CangkulPlayer.hpp"
#include <iostream>

using namespace std;
// game state class

class CangkulState
{
protected:
    int round;
    bool win;
    PlayerQueue<CangkulPlayer> playerQueue;
    CangkulDeck mainDeck;
    Table<StandardCard> tableCards;
    vector<pair<CangkulPlayer, StandardCard>> tablePrio;
    int game;
    ConsoleInput cli;

public:
    CangkulState();
    PlayerQueue<CangkulPlayer> &getPlayerQueue();
    CangkulDeck &getMainDeck();
    CangkulPlayer getMaxPlayer();
    bool isValid(const StandardCard &other);
    void setMainDeck(const CangkulDeck &_mainDeck);
    void setPlayerQueue(const PlayerQueue<CangkulPlayer> &_p);
    void setNewPlayer();
    void executeCommand();
    void displayCurrentState();
    void nextRound();
    void dealPlayers();
    void dealTable();
    void resetSession();
    void evaluateWinner();
    int start();
};

#endif