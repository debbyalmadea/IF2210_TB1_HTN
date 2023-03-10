#ifndef _PLAYERQUEUE_
#define _PLAYERQUEUE_
#define CAPACITY 7

#include <bits/stdc++.h>
#include "Player.hpp"
#include <iostream>

using namespace std;

class PlayerQueue
{
protected:
    Player *players;
    int nPlayer;

public:
    PlayerQueue()
    {
        players = new Player[CAPACITY];
        nPlayer = 0;
    }

    ~PlayerQueue()
    {
        delete[] players;
    }

    void enqueue(const Player player)
    {
        if (nPlayer == CAPACITY)
        {
            cout << "Player maksimal hanya berjumlah 7" << endl;
        }
        else
        {
            players[nPlayer] = player;
            nPlayer++;
        }
    }

    Player dequeue()
    {
        Player player = players[0];
        for (int i = 0; i < nPlayer; i++)
        {
            players[i] = players[i + 1];
        }
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

    void shuffleQueue() // for new game
    {
        unsigned seed = 0;
        shuffle(players, players + nPlayer, default_random_engine(seed));
    }

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

        cout << "Giliran dilanjut ke pemain selanjutnya" << endl;
        cout << "Giliran saat ini: P" << players[0].getID() << "\n\n";
    }
    void displayQueue()
    {
        cout << "Urutan permainan saat ini:" << endl;
        for (int i = 0; i < nPlayer; i++)
        {
            cout << "Player #" << players[i].getID() << " dengan point " << players[i].getPoint() << endl;
        }
        cout << endl;
    }

    void displayGiliran()
    {
        cout << "Giliran saat ini: P" << players[0].getID() << endl;
        cout << "Urutan giliran selanjutnya: ";
        for (int i = 1; i < nPlayer; i++)
        {
            if (!players[i].cekGiliran())
            {
                cout << "P" << players[i].getID() << " ";
            }
        }
        cout << "\n\n";
    }
};

#endif