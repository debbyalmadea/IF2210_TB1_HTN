#include "GameState.hpp"

Gamestate::Gamestate() : giftPoint(64), round(1), playerCount(0), win(false), input("")
{
    cout << endl
         << " SELAMAT DATANG DI" << endl
         << "   ▄ .▄       ▐ ▄ ▄▄▄▄▄      ▄• ▄▌ ▐ ▄ ▪    " << endl
         << "  ██▪▐█▪     •█▌▐█•██  ▪     █▪██▌•█▌▐███   " << endl
         << "  ██▀▐█ ▄█▀▄ ▐█▐▐▌ ▐█.▪ ▄█▀▄ █▌▐█▌▐█▐▐▌▐█·  " << endl
         << "  ██▌▐▀▐█▌.▐▌██▐█▌ ▐█▌·▐█▌.▐▌▐█▄█▌██▐█▌▐█▌  " << endl
         << "  ▀▀▀ · ▀█▄▀▪▀▀ █▪ ▀▀▀  ▀█▄▀▪ ▀▀▀ ▀▀ █▪▀▀▀  " << endl
         << endl;
}

int Gamestate::getGiftPoint() const
{
    return giftPoint;
}

void Gamestate::setGiftPoint(int _giftPoint)
{
    giftPoint = _giftPoint;
}

PlayerQueue &Gamestate::getPlayerQueue()
{
    return playerQueue;
}
MainDeck &Gamestate ::getMainDeck()
{
    return mainDeck;
}
void Gamestate::setMainDeck(const MainDeck &_mainDeck)
{
    mainDeck = _mainDeck;
}
void Gamestate::setPlayerQueue(const PlayerQueue &_playerQueue)
{
    playerQueue = _playerQueue;
}

void Gamestate::setNewPlayer()
{
    for (int i = 0; i < 7; i++)
    {
        cout << "Masukkan Nama Pemain " << i + 1 << endl;
        getInputCLI();
        playerQueue.enqueue(Player(i + 1, input));
        cout << endl;
    }

    clearInput();
}

void Gamestate::displayCurrentState()
{
    cout << "--------------------------------------------" << endl
         << "Ronde: " << round << endl
         << "Poin Hadiah: " << giftPoint << endl;
    playerQueue.displayGiliran();
    cout << "--------------------------------------------" << endl;
}

void Gamestate::getInputCLI()
{
    cout << ">> ";
    cin >> input;
}

void Gamestate::getInputCLI(int min, int max)
{
    getInputCLI();
    try
    {
        if (stoi(input) < min || stoi(input) > max)
        {
            throw ExceptionIO(input);
        }
    }
    catch (invalid_argument &err)
    {
        throw ExceptionIO(input);
    }
}

void Gamestate::clearInput()
{
    input = "";
}
void Gamestate::nextRound()
{
    playerCount = 0;
    round++;
}

void Gamestate::resetSession()
{
    clearInput();
    tableCards = Table();
    abilityDeck = AbilityDeck();
    abilityDeck.shuffleDeck();
    Ability::resetAbilityState();
    cout << " ------------------------------------------ " << endl
         << "| Pilih metode membaca deck                |" << endl
         << "|                                          |" << endl
         << "| 1. Baca dari file                        |" << endl
         << "| 2. Random                                |" << endl
         << " ------------------------------------------ " << endl;

    // ? SUGGESTION: Place it in another method?
    while (input == "" || input == "1")
    {
        try
        {
            if (input != "1")
            {
                getInputCLI(1, 2);
            }

            if (input == "1")
            {
                FileReader reader;
                cout << "Masukkan nama file" << endl;
                getInputCLI();
                mainDeck = reader.readBasicCard(input);
            }
            else if (input == "2")
            {
                mainDeck = MainDeck();
            }
            mainDeck.shuffleDeck();
            cout << "   ▄▄ •  ▄▄▄· • ▌ ▄ ·. ▄▄▄ .    .▄▄ · ▄▄▄▄▄ ▄▄▄· ▄▄▄  ▄▄▄▄▄▄▄  " << endl
                 << "  ▐█ ▀ ▪▐█ ▀█ ·██ ▐███▪▀▄.▀·    ▐█ ▀. •██  ▐█ ▀█ ▀▄ █·•██  ██▌ " << endl
                 << "  ▄█ ▀█▄▄█▀▀█ ▐█ ▌▐▌▐█·▐▀▀▪▄    ▄▀▀▀█▄ ▐█.▪▄█▀▀█ ▐▀▀▄  ▐█.▪▐█· " << endl
                 << "  ▐█▄▪▐█▐█ ▪▐▌██ ██▌▐█▌▐█▄▄▌    ▐█▄▪▐█ ▐█▌·▐█ ▪▐▌▐█•█▌ ▐█▌·.▀  " << endl
                 << "  ·▀▀▀▀  ▀  ▀ ▀▀  █▪▀▀▀ ▀▀▀      ▀▀▀▀  ▀▀▀  ▀  ▀ .▀  ▀ ▀▀▀  ▀  " << endl;
        }
        catch (ExceptionFile &err)
        {
            err.print();
            input = "1";
        }
        catch (Exception &err)
        {
            err.print();
            clearInput();
        }
        catch (invalid_argument &err)
        {
            cout << "Masukan Tidak Valid. Tidak bisa diubah ke Integer" << endl;
            clearInput();
        }
    }
}

void Gamestate::executeCommand()
{
    bool shouldNext = true;
    vector<string> ability = {"Abilityless", "Quadruple", "Quarter", "ReRoll", "ReverseDirection", "SwapCard", "Switch"};
    command = NULL;
    if (input == "NEXT")
    {
        command = new Next();
        shouldNext = false;
    }
    else if (input == "HALF")
    {
        command = new Half();
    }
    else if (input == "DOUBLE")
    {
        command = new Double();
    }
    else if (
        find(ability.begin(), ability.end(), input) != ability.end())
    {
        if (round == 1)
        {
            throw "Masih round 1";
        }
        else
        {
            Player currentPlayer = playerQueue.getFirst();
            Ability *ability = currentPlayer.getAbility();
            if (ability->getAbilityName() == input)
            {
                ability->use(*this);
            }
            else
            {
                cout << "You dont have the card" << endl;
            }
            return;
        }
    }
    else if (input == "DISPLAY")
    {
        Player currentPlayer = playerQueue.getFirst();
        currentPlayer.displayInv();
        shouldNext = false;
    }
    else
    {
        throw ExceptionIO(input);
    }

    if (command != NULL)
    {
        command->use(*this);
        delete command;
    }
    if (shouldNext)
    {
        playerQueue.next();
    }
}

int Gamestate::start()
{
    resetSession();
    setNewPlayer();
    while (!win)
    {
        resetSession();
        cout << "HAIHIDF";
        dealPlayers();
        bool dealt = false;
        // dealTable();
        // dealTable();
        // dealTable();
        // dealTable();
        // dealTable();
        // round = 6;
        // playerCount = 6;
        while (round <= 6)
        {
            if (round != 6 && playerCount == 0 && dealt == false)
            {
                if (round == 2)
                {
                    dealAbility();
                }
                dealTable();
                dealt = true;
            }
            try
            {
                displayCurrentState();
                getInputCLI();
                executeCommand();
                playerCount++;
                if (playerCount == 7)
                {
                    nextRound();
                    dealt = false;
                }
                if (round == 7)
                {
                    evaluateSession();
                    resetSession();
                }
            }
            catch (...)
            {
                cout << "Something is wrong" << endl; //! CHANGE
            }
        }
    }
    int newgame;
    cout << "New game (1) or No (0)";
    getInputCLI(0, 1);
    return newgame;
}

void Gamestate::dealAbility()
{
    cout << "Dealing ability ..." << endl;
    for (int i = 0; i < playerQueue.getnPlayers(); i++)
    {
        Ability *card = abilityDeck.dealCard(1)[0];
        Player &currentPlayer = playerQueue.getFirst();
        currentPlayer.setAbility(card);
        card->setIdPemilik(currentPlayer.getID());
        playerQueue.next();
    }
}
void Gamestate::dealPlayers()
{
    cout << "Dealing cards..." << endl;
    for (int i = 0; i < playerQueue.getnPlayers(); i++)
    {
        vector<PermenCard> cards = mainDeck.dealCard(2);
        Player &currentPlayer = playerQueue.getFirst();
        currentPlayer.setBothCard(pair<PermenCard, PermenCard>(cards[0], cards[1]));
        playerQueue.next();
    }
}

void Gamestate::dealTable()
{
    cout << "Dealing table at round " << round << endl;
    vector<PermenCard> card = mainDeck.dealCard(1);
    tableCards.addCard(card[0]);
    tableCards.displayInv();
};

void Gamestate::evaluateSession()
{
    vector<ComboTable> playerCombos;
    cout << "Evaluating combos.." << endl;
    for (int i = 0; i < playerQueue.getnPlayers(); i++)
    {
        Player currPlayer = playerQueue.getFirst();
        ComboTable playerCombo = ComboTable(currPlayer, tableCards);
        playerCombo.calculatePossibleCombos();
        playerCombo.displayCombos();
        playerCombos.push_back(playerCombo);
        playerQueue.next();
    }
    cout << "hitung maks" << endl;
    ComboTable winningCombo = max<ComboTable>(playerCombos);
    // ComboTable winningCombo = playerCombos[0];
    // cout << "hii";
    // for (auto &elem : playerCombos)
    // {
    //     if (elem > winningCombo)
    //         winningCombo = elem;
    // }
    Player winner = winningCombo.getPlayer();
    cout << "Player " << winner.getName() << " " << winner.getID() << " wins this round!";
    try
    {
        playerQueue.awardPlayer(winner, giftPoint);
    }
    catch (...)
    {
        win = true;
        cout << "Player " << winner.getName() << " " << winner.getID() << " points overflowed, winning the game!";
    }
};