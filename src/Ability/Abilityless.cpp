
#include "../Player/PlayerQueue.hpp"
#include "../Player/Player.hpp"
#include "../GameState/GameState.hpp"
#include "Ability.hpp"
#include <iostream>
#include "Abilityless.hpp"

using namespace std;

Abilityless::Abilityless() : Ability(0, -1)
{
}
Abilityless::Abilityless(int _idPemilik) : Ability(0, _idPemilik)
{
}
bool Abilityless::hasUsedAllAbility()
{
    bool hasUsed = true;
    for (int i = 0; i < 7; i++)
    {
        if (available[i] == 1 && i != getIdAbility())
        {
            hasUsed = false;
            break;
        }
    }
    return hasUsed;
}

void Abilityless::use(Gamestate &g)
{
    ConsoleInput cli;
    string input;
    int idDeadPlayer;
    if (available[getIdAbility()] == 0)
    {
        cout << "Kartu Abilityless sudah pernah dipakai" << endl;
    }
    else
    {
        if (hasUsedAllAbility())
        {
            cout << "Eits, ternyata semua pemain sudah memakai kartu kemampuan. Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Yah, pengunaan kartu ini sia-sia" << endl;
            setAbilityAvailability(0);
            PlayerQueue<Player> p = g.getPlayerQueue();
            p.next();
            g.setPlayerQueue(p);
        }
        else
        {
            if (available[getIdAbility()] == 1)
            {
                cout << "Kamu akan mematikan kartu ability dari salah satu pemain lain" << endl;
                /*print semua player*/
                cout << endl;
                for (int i = 0; i < 7; i++)
                {
                    if (getIdPemilik() != g.getPlayerQueue().getPlayer(i).getID())
                    {
                        cout << "Pemain " << g.getPlayerQueue().getPlayer(i).getID() << " - "
                             << g.getPlayerQueue().getPlayer(i).getName() << endl;
                    }
                }
                cout << endl
                     << "Silahkan pilih id pemain yang kartunya ingin kamu matikan: " << endl;
                vector<int> except = {getIdPemilik()};
                idDeadPlayer = cli.getInputInt(1, 7, except);
                if (available[idPemilikidAbility[idDeadPlayer]] == 1)
                {
                    setAbilityAvailability(idPemilikidAbility[idDeadPlayer], 2);
                    cout << "Kartu ability pemain " << idDeadPlayer << " berhasil dimatikan" << endl;
                }
                else
                {
                    cout << "Kartu ability pemain "
                         << "telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia." << endl;
                }
                setAbilityAvailability(0);
                PlayerQueue<Player> p = g.getPlayerQueue();
                p.next();
                g.setPlayerQueue(p);
            }
        }
    }
}