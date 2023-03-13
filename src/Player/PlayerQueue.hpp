#ifndef _PLAYERQUEUE_
#define _PLAYERQUEUE_
#define CAPACITY 7

#include <bits/stdc++.h>
#include "Player.hpp"
#include "../Ability/Ability.hpp"
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

    // ~PlayerQueue()
    // {
    //     delete[] players;
    // }

    void enqueue(const Player &player)
    {
        if (nPlayer == CAPACITY)
        {
            cout << "Player maksimal hanya berjumlah 7" << endl;
        }
        else
        {
            // players[nPlayer] = player;
            players.push_back(player);
            nPlayer++;
        }
    }

    Player &getFirst()
    {
        return players[0];
    }
    vector<Player> getPlayers()
    {
        return players;
    }
    int getnPlayers()
    {
        return nPlayer;
    }

    Player dequeue()
    {
        Player player = players[0];
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

    // void shuffleQueue() // for new game
    // {
    //     unsigned seed = 0;
    //     shuffle(players, players + nPlayer, default_random_engine(seed));
    // }

    void maintainQueue()
    {
        while (players[0].cekGiliran())
        {
            Player giliran = dequeue();
            enqueue(giliran);
        }
    }

    void next()
    {
        Player giliran = dequeue();
        giliran.giliranSelesai();
        enqueue(giliran);
        checkNewRound();

        cout << "Giliran dilanjut ke pemain selanjutnya" << endl;
        displayCurrentGiliran();
    }
    void checkNewRound()
    {
        bool notPlayed = false;
        for (auto &player : players)
        {
            notPlayed |= !player.cekGiliran();
        }

        if (!notPlayed)
        {
            for (auto &player : players)
            {
                player.belumGiliran();
            }
        }
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