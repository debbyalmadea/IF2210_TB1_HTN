#include "PlayerQueue.hpp"
#include "../Card/PermenCard.cpp"

// g++ driverPlayer.cpp -o driverPlayer && ./driverPlayer

int main()
{
    Player p1(1, "ayam");
    Player p2(2, "kucing");
    Player p3(3, "bebek");
    Player p4(4, "singa");
    Player p5(5, "kuda");
    Player p6(6, "anjing");
    Player p7(7, "babi");

    PlayerQueue<Player> pq;
    pq.enqueue(p3);
    pq.enqueue(p4);
    pq.enqueue(p5);
    pq.enqueue(p6);
    pq.enqueue(p7);
    pq.enqueue(p1);
    pq.enqueue(p2);

    pq.next();
    pq.next();
    pq.next();
    pq.reverse();
    pq.next();
    pq.next();
    pq.next();
    pq.next(); // harusnya udah selesai
    pq.newRound();
    pq.displayGiliran();

    return 0;
}