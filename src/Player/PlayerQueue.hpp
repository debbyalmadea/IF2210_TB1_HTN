#ifndef _PLAYERQUEUE_
#define _PLAYERQUEUE_
#define CAPACITY 7

#include "Player.hpp"
#include <vector>
#include <iostream>

using namespace std;

class PlayerQueue
{
protected:
    vector<Player> players;
    int nPlayer;

public:
    friend class Ability;
    PlayerQueue()
    {
        nPlayer = 0;
    }

    void enqueue(const Player &player)
    {
        if (nPlayer == CAPACITY)
        {
            cout << "Player maksimal hanya berjumlah 7" << endl;
        }
        else
        {
            players.push_back(player);
            nPlayer++;
        }
    }

    Player &getFirst()
    {
        return players[0];
    }

    vector<Player> getPlayers() const
    {
        return players;
    }

    Player &getPlayer(int idx)
    {
        return players[idx];
    }

    int getnPlayers()
    {
        return nPlayer;
    }

    Player dequeue()
    {
        Player player = getFirst();
        players.erase(players.begin());
        nPlayer--;
        return player;
    }

    void reverse()
    {
        Player temp;
        int j = nPlayer - 1;
        for (int i = 1; i < j; i++, j--)
        {
            temp = players[i];
            players[i] = players[j];
            players[j] = temp;
        }
        maintainQueue(); // Mengurutkan kembali dari yang belum mendapat giliran
    }

    void maintainQueue()
    {
        if (!rondeSelesai())
        {
            while (players[0].cekGiliran())
            {
                Player giliran = dequeue();
                enqueue(giliran);
            }
        }
    }

    bool rondeSelesai()
    {
        bool check = true;
        int i = 0;
        while (check && i < nPlayer)
        {
            check = check && players[i].cekGiliran();
            i++;
        }
        return check;
    }
    bool checkNewRound()
    {
        bool check = true;
        int i = 0;
        while (check && i < nPlayer)
        {
            check = check && players[i].cekGiliran();
            i++;
        }
        return check;
    }

    void next()
    {
        if (!rondeSelesai())
        {
            Player giliran = dequeue();
            giliran.giliranSelesai();
            enqueue(giliran);
            maintainQueue();

            if (!rondeSelesai())
            {
                cout << "Giliran dilanjut ke pemain selanjutnya" << endl;
                displayCurrentGiliran();
            }
            else
            {
                cout << "Ronde selesai" << endl;
            }
        }
        else
        {
            cout << "Ronde sudah selesai. Ganti ke ronde selanjutnya" << endl;
        }
    }

    void newRound()
    {
        for (auto &player : players)
        {
            player.belumGiliran();
        }
        Player nextGiliran = dequeue();
        enqueue(nextGiliran);
    }

    void displayQueue() const
    {
        cout << "Urutan permainan saat ini:" << endl;
        for (int i = 0; i < nPlayer; i++)
        {
            cout << "Player #" << players[i].getID() << " dengan point " << players[i].getPoint() << endl;
        }
        cout << endl;
    }

    void displayCurrentGiliran()
    {
        cout << "Giliran saat ini: P" << players[0].getID() << " " << players[0].getName() << endl;
    }

    void displayGiliran()
    {
        if (!rondeSelesai())
        {
            displayCurrentGiliran();
            cout << "Urutan giliran selanjutnya: ";
            for (int i = 1; i < nPlayer; i++)
            {
                if (!players[i].cekGiliran())
                {
                    cout << "P" << players[i].getID() << " ";
                }
            }
            cout << "\n";
        }
        else
        {
            cout << "Semua player sudah mendapat giliran" << endl;
        }
    }

    void awardPlayer(Player winner, int giftPoints)
    {
        for (auto &player : players)
        {
            if (player.getID() == winner.getID())
                winner.addPoint(giftPoints);
        }
    };
};

#endif