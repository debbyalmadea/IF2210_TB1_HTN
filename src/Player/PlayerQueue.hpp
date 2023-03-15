#ifndef _PLAYERQUEUE_
#define _PLAYERQUEUE_
#define CAPACITY 7

#include "Player.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class PlayerQueue
{
protected:
    vector<T> players;
    int nPlayer;

public:
    friend class Ability;
    PlayerQueue()
    {
        nPlayer = 0;
    }

    void enqueue(const T &player)
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

    T &getFirst()
    {
        return players[0];
    }

    vector<T> getPlayers() const
    {
        return players;
    }

    T &getPlayer(int idx)
    {
        return players[idx];
    }

    int getnPlayers()
    {
        return nPlayer;
    }

    T dequeue()
    {
        T player = getFirst();
        players.erase(players.begin());
        nPlayer--;
        return player;
    }

    void reverse()
    {
        T temp;
        int j = nPlayer - 1;
        for (int i = 1; i < j; i++, j--)
        {
            temp = players[i];
            players[i] = players[j];
            players[j] = temp;
        }
        maintainQueue();
    }

    // Apabila queue terdepan sudah mendapat giliran, maka ia akan langsung dipindah ke belakang
    void maintainQueue()
    {
        if (!rondeSelesai())
        {
            while (players[0].cekGiliran())
            {
                T giliran = dequeue();
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

    bool rondeBaruMulai()
    {
        bool check = true;
        int i = 0;
        while (check && i < nPlayer)
        {
            check = check && !players[i].cekGiliran();
            i++;
        }
        return check;
    }

    int countGiliranDone()
    {
        int count = 0;
        for (int i = 0; i < nPlayer; i++)
        {
            if (players[i].cekGiliran())
            {
                count++;
            }
        }
        return count;
    }

    // Lanjut ke giliran player selanjutnya. Kalau sudah semua, maka otomatis akan terbuat ronde baru
    void next()
    {
        if (!rondeSelesai())
        {
            T giliran = dequeue();
            giliran.giliranSelesai();
            enqueue(giliran);
            maintainQueue();

            if (!rondeSelesai())
            {
                cout << "Giliran dilanjut ke pemain selanjutnya" << endl;
            }
        }
    }

    void silentNext(int skip)
    {
        for (int i = 0; i < skip; i++)
        {
            T giliran = dequeue();
            enqueue(giliran);
        }
    }

    void newRound()
    {
        for (auto &player : players)
        {
            player.belumGiliran();
        }
        T nextGiliran = dequeue();
        enqueue(nextGiliran);
    }

    // Melihat isi queue
    // void displayQueue() const
    // {
    //     // cout << "Urutan permainan saat ini:" << endl;
    //     for (int i = 0; i < nPlayer; i++)
    //     {
    //         cout << "Player #" << players[i].getID() << " dengan point " << players[i].getPoint() << endl;
    //     }
    //     cout << endl;
    // }

    // Melihat player giliran saat ini
    void displayCurrentGiliran()
    {
        cout << "Giliran saat ini: " << players[0].getName() << endl;
    }

    // Melihat semua sisa giliran, termasuk yang saat ini.
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
                    cout << "<" << players[i].getName() << "> ";
                }
            }
            cout << "\n";
        }
        else
        {
            cout << "Semua player sudah mendapat giliran" << endl;
        }
    }

    // Memberi point pada player yang menang
    void awardPlayer(T winner, unsigned long long giftPoints)
    {
        for (auto &player : players)
        {
            if (player.getID() == winner.getID())
                winner.addPoint(giftPoints);
        }
    };

    void displayLeaderboard()
    {
        sort(players.begin(), players.end());
        cout << "Leaderboard:" << endl;
        for (int i = 0; i < players.size(); i++)
        {
            cout << "   " << i + 1 << ". Pemain P" << players[i].getID() << " " << players[i].getName() << ": " << players[i].getPoint() << endl;
        }
    }
};

#endif