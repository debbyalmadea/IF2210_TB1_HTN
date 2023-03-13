#ifndef Gamestate_HPP
#define Gamestate_HPP
#include "../Player/PlayerQueue.hpp"
#include "../IO/FileReader.hpp"
#include "../Deck/MainDeck.hpp"
#include "../Ability/CommandInclude.hpp"
#include "../Table/Table.hpp"

#include <iostream>
using namespace std;
// game state class

class Gamestate
{
protected:
    int round;
    int playerCount;
    int giftPoint;
    bool win;
    PlayerQueue playerQueue;
    MainDeck mainDeck;
    string input;
    Table tableCards;
    Command *command;
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
    void setCommand(string _command);
    string getCommand();
    void executeCommand();
    void getInputCLI();
    void clearInput();
    void getInputCLI(int min, int max);
    void displayCurrentState();
    void nextRound();
    void dealPlayers();
    void dealTable();
    void evaluateSession();
    void resetSession();
    int start();
};

#endif