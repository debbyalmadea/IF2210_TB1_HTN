#include "GameState.hpp"

Gamestate::Gamestate() : giftPoint(64), round(1) {}

int Gamestate::getGiftPoint() const
{
    return giftPoint;
}

void Gamestate::setGiftPoint(int _giftPoint)
{
    giftPoint = _giftPoint;
}

PlayerQueue Gamestate::getPlayerQueue() const
{
    return playerQueue;
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
    if (stoi(input) < min || stoi(input) > max)
    {
        throw "Masukan Tidak Valid";
    }
}

void Gamestate::clearInput()
{
    input = "";
}

void Gamestate::executeCommand()
{
    vector<string> ability = {"ABILITYLESS",
                              "RE-ROLL",
                              "REVERSE DIRECTION",
                              "SWAP CARD",
                              "SWITCH"};
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

    if (find(ability.begin(), ability.end(), input) != ability.end())
    {
        if (round == 1)
        {
            throw "Masih round 1";
        }
        else
        {
            Player currentPlayer = playerQueue.getFirst();
            command = currentPlayer.getAbility();
        }
    }

    command->use(*this);
}

void Gamestate::start()
{
    cout << endl
         << " SELAMAT DATANG DI" << endl
         << "   ▄ .▄       ▐ ▄ ▄▄▄▄▄      ▄• ▄▌ ▐ ▄ ▪    " << endl
         << "  ██▪▐█▪     •█▌▐█•██  ▪     █▪██▌•█▌▐███   " << endl
         << "  ██▀▐█ ▄█▀▄ ▐█▐▐▌ ▐█.▪ ▄█▀▄ █▌▐█▌▐█▐▐▌▐█·  " << endl
         << "  ██▌▐▀▐█▌.▐▌██▐█▌ ▐█▌·▐█▌.▐▌▐█▄█▌██▐█▌▐█▌  " << endl
         << "  ▀▀▀ · ▀█▄▀▪▀▀ █▪ ▀▀▀  ▀█▄▀▪ ▀▀▀ ▀▀ █▪▀▀▀  " << endl
         << endl;

    //! CHANGE This to something else
    while (true)
    {
        setNewPlayer();
        cout << " ------------------------------------------ " << endl
             << "| Pilih metode memulai game                |" << endl
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
                mainDeck.shuffleDeck();
                cout << "   ▄▄ •  ▄▄▄· • ▌ ▄ ·. ▄▄▄ .    .▄▄ · ▄▄▄▄▄ ▄▄▄· ▄▄▄  ▄▄▄▄▄▄▄  " << endl
                     << "  ▐█ ▀ ▪▐█ ▀█ ·██ ▐███▪▀▄.▀·    ▐█ ▀. •██  ▐█ ▀█ ▀▄ █·•██  ██▌ " << endl
                     << "  ▄█ ▀█▄▄█▀▀█ ▐█ ▌▐▌▐█·▐▀▀▪▄    ▄▀▀▀█▄ ▐█.▪▄█▀▀█ ▐▀▀▄  ▐█.▪▐█· " << endl
                     << "  ▐█▄▪▐█▐█ ▪▐▌██ ██▌▐█▌▐█▄▄▌    ▐█▄▪▐█ ▐█▌·▐█ ▪▐▌▐█•█▌ ▐█▌·.▀  " << endl
                     << "  ·▀▀▀▀  ▀  ▀ ▀▀  █▪▀▀▀ ▀▀▀      ▀▀▀▀  ▀▀▀  ▀  ▀ .▀  ▀ ▀▀▀  ▀  " << endl;
            }
            catch (const char *err)
            {
                cout << err << endl;
                input = "";
            } // TODO: FileException Handling
            catch (...)
            {
                cout << "Masukan Tidak Valid" << endl;
                input = "";
            }
        }

        while (round <= 6)
        {
            try
            {
                displayCurrentState();
                getInputCLI();
                executeCommand();
            }
            catch (...)
            {
                cout << "Something is wrong" << endl; //! CHANGE
            }
        }
    }
}