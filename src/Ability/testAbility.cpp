#include "Ability.hpp"
#include "Abilityless.hpp"
#include "Multiplier.hpp"
#include "Ability.cpp"
#include "Next.hpp"
#include "../GameState/GameState.hpp"

#include <iostream>
#include <string>
using namespace std;

int main()
{

    PlayerQueue pq;
    Player p1(1);
    Player p2(2);
    Player p3(3);
    Player p4(4);
    Player p5(5);
    Player p6(6);
    Player p7(7);
    pq.enqueue(p1);
    pq.enqueue(p2);
    pq.enqueue(p3);
    pq.enqueue(p4);
    pq.enqueue(p5);
    pq.enqueue(p6);
    pq.enqueue(p7);
    pq.displayQueue();
    Gamestate g(pq);
    // g.getPlayerQueue().displayQueue();

    // Abilityless
    Abilityless a(1);
    Quadruple b(0);
    b.use(&g);
    a.use(&g);

    // coba multiplier
    Double d;
    d.use(&g);
    cout << "Skor " << g.getGiftPoint() << endl;
    Quadruple q;
    q.use(&g);
    cout << "Skor " << g.getGiftPoint() << endl;
    Half h;
    h.use(&g);
    cout << "Skor " << g.getGiftPoint() << endl;
    Quarter q1;
    q1.use(&g);
    cout << "Skor " << g.getGiftPoint() << endl;
    // to do : matiin availabilitynya

    // coba next
    Next n;
    n.use(&g);
    n.use(&g);
    cout << "yey" << endl;
}