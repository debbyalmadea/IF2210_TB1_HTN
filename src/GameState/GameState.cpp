#include "GameState.hpp"

Gamestate::Gamestate() : giftPoint(64), round(1), win(false), reverseSkip(-1)
{
    system("clear");
    cout << endl
         << " SELAMAT DATANG DI" << endl
         << "   ▄ .▄       ▐ ▄ ▄▄▄▄▄      ▄• ▄▌ ▐ ▄ ▪    " << endl
         << "  ██▪▐█▪     •█▌▐█•██  ▪     █▪██▌•█▌▐███   " << endl
         << "  ██▀▐█ ▄█▀▄ ▐█▐▐▌ ▐█.▪ ▄█▀▄ █▌▐█▌▐█▐▐▌▐█·  " << endl
         << "  ██▌▐▀▐█▌.▐▌██▐█▌ ▐█▌·▐█▌.▐▌▐█▄█▌██▐█▌▐█▌  " << endl
         << "  ▀▀▀ · ▀█▄▀▪▀▀ █▪ ▀▀▀  ▀█▄▀▪ ▀▀▀ ▀▀ █▪▀▀▀  " << endl
         << endl;
}

unsigned long long Gamestate::getGiftPoint() const
{
    return giftPoint;
}

void Gamestate::setGiftPoint(unsigned long long _giftPoint)
{
    giftPoint = _giftPoint;
}

PlayerQueue<Player> &Gamestate::getPlayerQueue()
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
void Gamestate::setPlayerQueue(const PlayerQueue<Player> &_playerQueue)
{
    playerQueue = _playerQueue;
}

void Gamestate::setNewPlayer()
{
    for (int i = 0; i < 7; i++)
    {
        cout << "Masukkan Nama Pemain " << i + 1 << endl;
        cli.getInputCLI();
        playerQueue.enqueue(Player(i + 1, cli.getInput()));
        cout << endl;
    }

    cli.clearInput();
}

void Gamestate::displayCurrentState()
{
    cout << endl
         << "--------------------------------------------" << endl
         << "Ronde: " << round << endl
         << "Poin Hadiah: " << giftPoint << endl;
    playerQueue.displayGiliran();
    cout << "--------------------------------------------" << endl;
}

void Gamestate::nextRound()
{
    // system("clear");
    playerQueue.newRound();
    if (reverseSkip != -1)
    {
        if (reverseSkip < 2)
        {
            playerQueue.silentNext(reverseSkip + 5);
        }
        else if (reverseSkip == 6)
        {
            playerQueue.silentNext(3);
        }
        else
        {
            playerQueue.silentNext(reverseSkip - 2);
        }
    }
    reverseSkip = -1;
    round++;
}

void Gamestate::resetSession()
{
    cli.clearInput();
    tableCards = Table<PermenCard>();
    abilityDeck = AbilityDeck();
    Ability::resetAbilityState();
    playerQueue.resetRound();
    round = 1;
    setGiftPoint(64);
    abilityDeck.shuffleDeck();
    cout << " ------------------------------------------ " << endl
         << "| Pilih metode membaca deck                |" << endl
         << "|                                          |" << endl
         << "| 1. Baca dari file                        |" << endl
         << "| 2. Random                                |" << endl
         << " ------------------------------------------ " << endl;

    // ? SUGGESTION: Place it in another method?
    while (cli.getInput() == "" || cli.getInput() == "1")
    {
        try
        {
            if (cli.getInput() != "1")
            {
                cli.getInputInt(1, 2);
            }

            if (cli.getInput() == "1")
            {
                FileReader reader;
                cout << "Masukkan nama file" << endl;
                mainDeck = reader.readBasicCard(cli.getInputCLI());
            }
            else if (cli.getInput() == "2")
            {
                mainDeck = MainDeck();
                mainDeck.shuffleDeck();
            }
            system("clear");
            cout << "   ▄▄ •  ▄▄▄· • ▌ ▄ ·. ▄▄▄ .    .▄▄ · ▄▄▄▄▄ ▄▄▄· ▄▄▄  ▄▄▄▄▄▄▄  " << endl
                 << "  ▐█ ▀ ▪▐█ ▀█ ·██ ▐███▪▀▄.▀·    ▐█ ▀. •██  ▐█ ▀█ ▀▄ █·•██  ██▌ " << endl
                 << "  ▄█ ▀█▄▄█▀▀█ ▐█ ▌▐▌▐█·▐▀▀▪▄    ▄▀▀▀█▄ ▐█.▪▄█▀▀█ ▐▀▀▄  ▐█.▪▐█· " << endl
                 << "  ▐█▄▪▐█▐█ ▪▐▌██ ██▌▐█▌▐█▄▄▌    ▐█▄▪▐█ ▐█▌·▐█ ▪▐▌▐█•█▌ ▐█▌·.▀  " << endl
                 << "  ·▀▀▀▀  ▀  ▀ ▀▀  █▪▀▀▀ ▀▀▀      ▀▀▀▀  ▀▀▀  ▀  ▀ .▀  ▀ ▀▀▀  ▀  " << endl;
        }
        catch (ExceptionFile &err)
        {
            err.print();
            cli.getInput() = "1";
        }
        catch (Exception &err)
        {
            err.print();
            cli.clearInput();
        }
        catch (invalid_argument &err)
        {
            cout << "Masukan Tidak Valid. Tidak bisa diubah ke Integer" << endl;
            cli.clearInput();
        }
    }
}

void Gamestate::executeCommand()
{
    Command *command;
    vector<string> ability = {"ABILITYLESS", "QUADRUPLE", "QUARTER", "REROLL", "REVERSEDIRECTION", "SWAPCARD", "SWITCH"};
    command = NULL;
    string input = cli.getInput();
    if (input == "NEXT")
    {
        command = new Next();
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
            throw ExceptionCard(0, input);
        }
        else
        {
            Player currentPlayer = playerQueue.getFirst();
            Ability *ability = currentPlayer.getAbility();
            if (ability->getAbilityName() == input)
            {
                ability->use(*this);
                if (input == "REVERSEDIRECTION")
                {
                    reverseSkip = playerQueue.countGiliranDone();
                }
            }
            else
            {
                throw ExceptionCard(0, input);
            }
        }
    }
    else if (input == "DISPLAY")
    {
        tableCards.displayInv();
        cout << endl;
        Player currentPlayer = playerQueue.getFirst();
        currentPlayer.displayInv();
        if (round > 1)
        {
            cout << "Ability: " << currentPlayer.getAbility()->getAbilityName() << endl;
        }
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
}

int Gamestate::start()
{
    setNewPlayer();
    while (!win)
    {
        resetSession();
        dealPlayers();
        bool dealt = false;
        while (round <= 6)
        {
            if (round != 6 && playerQueue.rondeBaruMulai() && dealt == false)
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
                cli.getInputCLI();
                executeCommand();
                if (playerQueue.rondeSelesai())
                {
                    nextRound();
                    dealt = false;
                }
            }
            catch (Exception &err)
            {
                err.print();
            }
            catch (...)
            {
                cout << "Something is wrong" << endl; //! CHANGE
            }
        }
        evaluateSession();
    }
    int newgame;
    cout << "Lanjut?" << endl;
    cout << "   1. Main lagi" << endl;
    cout << "   2. Exit" << endl;
    newgame = cli.getInputInt(1, 2);

    return newgame;
}

void Gamestate::dealAbility()
{
    cout << endl;
    cout << "           .-----. D e a l i n g " << endl;
    cout << "   ' /   _/    )/  A b i l i t y " << endl;
    cout << "- ( ) -('---''--)  . . .         " << endl;
    cout << " / . \((() ^_^ )()               " << endl;
    cout << "  \\_  (()_)-((()()              " << endl
         << endl;
    // cout << "Dealing ability ..." << endl;
    for (int i = 0; i < playerQueue.getnPlayers(); i++)
    {
        Ability *card = abilityDeck.dealCard(1)[0];
        // cout << card->getIdAbility() << endl;
        Player &currentPlayer = playerQueue.getPlayer(i);
        currentPlayer.setAbility(card);
        cout << endl;
        card->setIdPemilik(currentPlayer.getID());
    }
}
void Gamestate::dealPlayers()
{
    cout << endl
         << endl;
    cout << "    _____  D e a l i n g C a r d s ... " << endl;
    cout << "   |A .  | _____                       " << endl;
    cout << "   | /.  ||A ^  | _____                " << endl;
    cout << "   |(_._)||     ||A _  | _____         " << endl;
    cout << "   |  |  ||     || ( ) ||A_ _ |        " << endl;
    cout << "   |____V||  .  ||(_'_)||( v )|        " << endl;
    cout << "          |____V||  |  ||  V  |        " << endl;
    cout << "                 |____V||  .  |        " << endl;
    cout << "                        |____V|        " << endl;
    cout << endl
         << endl;
    // cout << "Dealing cards..." << endl;
    for (int i = 0; i < playerQueue.getnPlayers(); i++)
    {
        vector<PermenCard> cards = mainDeck.dealCard(2);
        Player &currentPlayer = playerQueue.getPlayer(i);
        currentPlayer.setBothCard(pair<PermenCard, PermenCard>(cards[0], cards[1]));
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
    cout << "Kondisi akhir..." << endl;
    tableCards.displayInv();
    cout << endl;
    playerQueue.displayPlayers();
    cout << "Melakukan Evaluasi Combo.." << endl;
    for (int i = 0; i < playerQueue.getnPlayers(); i++)
    {
        Player currPlayer = playerQueue.getFirst();
        cout << "Evaluasi Combo P" << currPlayer.getID() << " " << currPlayer.getName() << endl;
        ComboTable playerCombo = ComboTable(currPlayer, tableCards);
        playerCombo.calculatePossibleCombos();
        playerCombos.push_back(playerCombo);
        playerQueue.next();
        cout << endl;
    }
    ComboTable winningCombo = max<ComboTable>(playerCombos);
    Player winner = winningCombo.getPlayer();
    cout << "Pemain P" << winner.getID() << " " << winner.getName() << " memenangkan sesi ini!" << endl;
    try
    {
        playerQueue.awardPlayer(winner, giftPoint);
        playerQueue.displayLeaderboard();
        cout << "Pemain belum menyentuh 2^32. Permainan dilanjutkan." << endl;
        cout << "Memulai ronde baru..." << endl;
    }
    catch (...)
    {
        win = true;
        cout << "POINTS OVERFLOWED! Permainan berakhir." << endl;
        playerQueue.displayLeaderboard();
        winner = playerQueue.getWinner();
        cout << "Permainan dimenangkan oleh Pemain P" << winner.getID() << " " << winner.getName() << endl;
    }
};