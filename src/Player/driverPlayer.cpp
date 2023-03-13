#include "PlayerQueue.hpp"
#include "../Card/PermenCard.cpp"

int main()
{
    Player p1(1, "ayam");
    Player p2(2, "kucing");
    Player p3(3, "bebek");
    Player p4(4, "singa");
    Player p5(5, "kuda");
    Player p6(6, "anjing");
    Player p7(7, "babi");

    PlayerQueue pq = PlayerQueue();
    pq.enqueue(p1);
    pq.enqueue(p2);
    pq.enqueue(p3);
    pq.enqueue(p4);
    pq.enqueue(p5);
    pq.enqueue(p6);
    pq.enqueue(p7);

    pq.displayQueue();

    pq.next();
    pq.displayQueue();
    pq.next();
    pq.displayQueue();
    pq.reverse();
    pq.displayQueue();
    // p1.addPoint(25);
    // p2.addPoint(18);
    // p3.addPoint(10);
    pq.displayGiliran();
    pq.displayQueue();

    return 0;
}