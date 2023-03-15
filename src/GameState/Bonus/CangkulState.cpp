#include "CangkulState.hpp"

CangkulState::CangkulState() : win(false), round(1)
{
    system("clear");
    cout << endl
         << " SELAMAT DATANG DI" << endl
         << "   ▄ .▄       ▐ ▄ ▄▄▄▄▄      ▄• ▄▌ ▐ ▄ ▪    " << endl
         << "  ██▪▐█▪     •█▌▐█•██  ▪     █▪██▌•█▌▐███   " << endl
         << "  ██▀▐█ ▄█▀▄ ▐█▐▐▌ ▐█.▪ ▄█▀▄ █▌▐█▌▐█▐▐▌▐█·  " << endl
         << "  ██▌▐▀▐█▌.▐▌██▐█▌ ▐█▌·▐█▌.▐▌▐█▄█▌██▐█▌▐█▌  " << endl
         << "  ▀▀▀ · ▀█▄▀▪▀▀ █▪ ▀▀▀  ▀█▄▀▪ ▀▀▀ ▀▀ █▪▀▀▀  " << endl
         << "CANGKUL EDITION (c)" << endl
         << endl;
}

PlayerQueue<CangkulPlayer> &CangkulState::getPlayerQueue()
{
    return playerQueue;
}
CangkulDeck &CangkulState::getMainDeck()
{
    return mainDeck;
}
void CangkulState::setMainDeck(const CangkulDeck &_mainDeck)
{
    mainDeck = _mainDeck;
}
void CangkulState::setPlayerQueue(const PlayerQueue<CangkulPlayer> &_playerQueue)
{
    playerQueue = _playerQueue;
}

void CangkulState::setNewPlayer()
{
    for (int i = 0; i < 4; i++)
    {
        cout << "Masukkan Nama Pemain " << i + 1 << endl;
        cli.getInputCLI();
        playerQueue.enqueue(CangkulPlayer(i + 1, cli.getInput()));
        cout << endl;
    }

    cli.clearInput();
}

void CangkulState::displayCurrentState()
{
    cout << endl
         << "--------------------------------------------" << endl
         << "Ronde: " << round << endl;
    playerQueue.displayGiliran();
    cout << "Kartu di meja: " << tableCards.seeTop() << endl;
    cout << "--------------------------------------------" << endl;
}

void CangkulState::nextRound()
{
    system("clear");
    if (tablePrio.empty())
    {
        playerQueue.newRound();
    }
    else
    {
        CangkulPlayer tertinggi = getMaxPlayer();
        cout << "Ronde akan dimulai dengan pemain dengan kartu tertinggi " << tertinggi.getName();
        playerQueue.newRound(getMaxPlayer());
    }
    tablePrio.clear();
    round++;
}

CangkulPlayer CangkulState::getMaxPlayer()
{
    pair<CangkulPlayer, StandardCard> maks = tablePrio[0];
    for (auto &pair : tablePrio)
    {
        if (pair.second > maks.second)
        {
            maks = pair;
        }
    }
    return maks.first;
}
void CangkulState::executeCommand()
{
    // bool shouldNext = true;
    CangkulPlayer &currPlayer = playerQueue.getFirst();
    string input = cli.getInput();
    StandardCard top = tableCards.seeTop();

    if (input == "CANGKUL")
    {
        if (currPlayer.canDeal(top))
        {
            cout << "Sorry, kamu sudah bisa melakukan aksi PLAY. Kenapa cangkul terus?" << endl;
        }
        else
        {
            if (mainDeck.getSize() > 0)
            {
                vector<StandardCard> dealt = mainDeck.dealCard(1);
                currPlayer.addCards(dealt);
            }
            else
            {
                cout << "Main deck sudah kehabisan card dan kamu mengambil kartu paling atas di meja...";
                currPlayer.addCard(tableCards.takeTop());
            }
        }
    }
    else if (input == "PLAY")
    {
        try
        {
            currPlayer.displayInv();
            cout << "Silahkan input angka dari kartu yang anda inginkan" << endl;
            int cardChoice = cli.getInputInt(1, currPlayer.getSize());
            StandardCard card = currPlayer.getCardIdx(cardChoice);
            if (isValid(card))
            {
                currPlayer.removeCardIdx(cardChoice);
                tableCards.addCard(card);
                playerQueue.next();
                tablePrio.push_back({currPlayer, card});
            }
            else
            {
                cout << "Kartu di atas meja: " << top << endl;
                cout << "Simbol kartumu tidak sama. Kartumu invalid!" << endl;
            }
        }
        catch (...)
        {
            cout << "Maaf input invalid" << endl;
        }
    }
    else
    {
        throw "You need to either CANGKUL or PLAY!";
    }
}

bool CangkulState::isValid(const StandardCard &other)
{
    if (tableCards.seeTop().getShape() == other.getShape())
    {
        return true;
    }
    return false;
}

int CangkulState::start()
{
    setNewPlayer();
    mainDeck.shuffleDeck();
    dealPlayers();
    dealTable();
    while (playerQueue.getnPlayers() != 1)
    {
        try
        {
            displayCurrentState();
            cli.getInputCLI();
            executeCommand();
            if (playerQueue.rondeSelesai())
            {
                nextRound();
            }
            evaluateWinner();
        }
        catch (char const *s)
        {
            cout << s << endl;
        }
    }
    int newgame;
    cout << "Lanjut?";
    cout << "   1. Main lagi" << endl;
    cout << "   0. Exit" << endl;
    newgame = cli.getInputInt(0, 1);
    return newgame;
}

void CangkulState::dealPlayers()
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
    cout << "How many cards per player?" << endl;
    int size;
    size = cli.getInputInt(1, 7);
    for (int i = 0; i < playerQueue.getnPlayers(); i++)
    {
        vector<StandardCard> cards = mainDeck.dealCard(size);
        CangkulPlayer &currentPlayer = playerQueue.getPlayer(i);
        currentPlayer.addCards(cards);
    }
}

void CangkulState::dealTable()
{
    cout << "Dealing initial card on table... " << round << endl;
    vector<StandardCard> card = mainDeck.dealCard(1);
    tableCards.addCard(card[0]);
    tableCards.displayInv();
};

void CangkulState::evaluateWinner()
{
    playerQueue.handleCangkulWin();
}