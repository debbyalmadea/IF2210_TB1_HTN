#include "Ability.hpp"
#include "Abilityless.hpp"
// #include "Multiplier.hpp"
#include "Multiplier.cpp"
#include "Ability.cpp"
#include "Switch.hpp"
#include "SwapCard.hpp"
#include "Next.hpp"
#include "Next.cpp"
#include "ReRoll.hpp"
#include "ReverseDirection.hpp"
#include "../IO/FileReader.cpp"
#include "../Card/PermenCard.cpp"
#include "../Player/PlayerQueue.hpp"
#include "../Gamestate/GameState.hpp"
#include "../GameState/GameState.cpp"

#include <iostream>
#include <string>
using namespace std;

int main()
{

    PlayerQueue pq;
    Player p1(1, "ayam");
    PermenCard permen1(3, 0);
    PermenCard permen2(6, 2);
    p1.setFirstCard(permen1);
    p1.setSecondCard(permen2);
    Player p2(2, "kucing");
    PermenCard permen3(8, 1);
    PermenCard permen4(7, 3);
    p2.setFirstCard(permen3);
    p2.setSecondCard(permen4);
    Player p3(3, "bebek");
    PermenCard permen5(10, 2);
    PermenCard permen6(11, 1);
    p3.setFirstCard(permen5);
    p3.setSecondCard(permen6);
    Player p4(4, "singa");
    Player p5(5, "kuda");
    Player p6(6, "anjing");
    Player p7(7, "babi");

    pq.enqueue(p1);
    pq.enqueue(p2);
    pq.enqueue(p3);
    pq.enqueue(p4);
    pq.enqueue(p5);
    pq.enqueue(p6);
    pq.enqueue(p7);
    pq.displayQueue();
    Gamestate g;
    g.setPlayerQueue(pq);
    g.getPlayerQueue().displayQueue();

    // // Abilityless
    // Abilityless a(1);
    // Quadruple b(0);
    // b.use(&g);
    // a.use(&g);

    // // coba multiplier
    // Double d;
    // d.use(&g);
    // cout << "Skor " << g.getGiftPoint() << endl;
    // Quadruple q;
    // q.use(&g);
    // cout << "Skor " << g.getGiftPoint() << endl;
    // Half h;
    // h.use(&g);
    // cout << "Skor " << g.getGiftPoint() << endl;
    // Quarter q1;
    // q1.use(&g);
    // cout << "Skor " << g.getGiftPoint() << endl;
    // // to do : matiin availabilitynya

    // // coba next
    // Next n;
    // n.use(g);
    // n.use(g);

    // ReverseDirection r(3);
    // r.use(g);
    // g.getPlayerQueue().displayQueue();

    // Switch s(1);
    // s.use(g);
    // cout << "kartu p1-1" << endl;
    // g.getPlayerQueue().getPlayer(0).getFirstCard().printInfo();
    // cout << "kartu p1-2" << endl;
    // g.getPlayerQueue().getPlayer(1).getFirstCard().printInfo();

    SwapCard sw(3);
    sw.use(g);
    cout << "kartu p1-1" << endl;
    g.getPlayerQueue().getPlayer(0).getFirstCard().printInfo();
    cout << "kartu p1-2" << endl;
    g.getPlayerQueue().getPlayer(0).getSecondCard().printInfo();
    cout << "kartu p3-1" << endl;
    g.getPlayerQueue().getPlayer(2).getFirstCard().printInfo();
    cout << "kartu p3-2" << endl;
    g.getPlayerQueue().getPlayer(2).getSecondCard().printInfo();

    ReRoll r(1);
    r.use(g);
    g.getPlayerQueue().getPlayer(0).getFirstCard().printInfo();
    g.getPlayerQueue().getPlayer(0).getSecondCard().printInfo();

    // p1.getSecondCard().printInfo();

    // cout << "kartu p2-1" << endl;
    // p2.getFirstCard().printInfo();
    // cout << "kartu p2-2" << endl;
    // p2.getSecondCard().printInfo();

    // n.use(&g);
    // cout << "yey" << endl;
}