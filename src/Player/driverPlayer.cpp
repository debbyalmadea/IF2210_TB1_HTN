#include "PlayerQueue.hpp"

int main()
{
    Player p1(1);
    Player p2(2);
    Player p3(3);
    Player p4(4);
    Player p5(5);
    Player p6(6);
    Player p7(7);

    PlayerQueue pq = PlayerQueue();
    pq.enqueue(p2);
    pq.enqueue(p3);
    pq.enqueue(p4);
    pq.enqueue(p5);
    pq.enqueue(p6);
    pq.enqueue(p7);
    pq.enqueue(p1);
    pq.displayQueue();

    pq.next();
    pq.next();
    pq.reverse();
    // p1.addPoint(25);
    // p2.addPoint(18);
    // p3.addPoint(10);
    pq.displayGiliran();
    pq.displayQueue();

    return 0;
}