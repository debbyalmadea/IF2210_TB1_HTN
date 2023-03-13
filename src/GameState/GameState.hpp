#ifndef Gamestate_HPP
#define Gamestate_HPP
#include "../Player/PlayerQueue.hpp"
#include "../IO/FileReader.hpp"
#include "../Deck/MainDeck.hpp"
#include "../Ability/CommandInclude.hpp"

#include <iostream>
using namespace std;
// game state class

class Gamestate
{
protected:
    int round;
    int playerCount;
    int giftPoint;
    PlayerQueue playerQueue;
    MainDeck mainDeck;
    string input;
    Command *command;
    int game;

public:
    Gamestate();
    int getGiftPoint() const;
    void setGiftPoint(int _giftPoint);
    PlayerQueue getPlayerQueue() const;
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
    void start();
};

#endif