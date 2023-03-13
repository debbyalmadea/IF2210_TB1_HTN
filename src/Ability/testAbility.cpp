#include "Ability.hpp"
#include "Abilityless.hpp"
#include "Multiplier.hpp"
#include "Ability.cpp"

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int com;
    Abilityless a1(0);
    Quadruple a2(1);
    Quarter a3(2);

    Half c1;
    Double c2;
    Gamestate g;

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
    // test multiplier
    cout << "Point now " << g.getGiftPoint() << endl;
    a2.use(1, &pq, &g);
    cout << "Point now " << g.getGiftPoint() << endl;
    a3.use(2, &pq, &g);
    cout << "Point now " << g.getGiftPoint() << endl;
    c2.use(&pq, &g);
    cout << "Point now " << g.getGiftPoint() << endl;
    c1.use(&pq, &g);
    cout << "Point now " << g.getGiftPoint() << endl;

    // Ability a3(2, 0, false);
    // Ability a4(3, 6, false);
    // Ability a5(4, 2, false);
    // Ability a6(5, 3, false);
    // Ability a7(6, 4, false);

    // PAKAI COMMAND BUAT
    // cout << "Enter ur command : ";
    // cin >> com;
    // cout << com << endl;

    // // mula -mula
    // cout << "MULA-MULA" << endl;
    // cout << "ini availability a1 " << a1.getAbilityAvailability() << endl;
    // cout << "ini availability a5 " << a5.getAbilityAvailability() << endl;
    // if (com == 1)
    // {
    //     if (a1.hasUsedAllAbility())
    //     {
    //         cout << "Eits, ternyata semua pemain sudah memakai kartu kemampuan. Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Yah, pengunaan kartu ini sia-sia" << endl;
    //         a1.setAbilityAvailability(false);
    //         // a1.setDeadStatus(true);
    //     }
    //     else
    //     {
    //         a1.use(0, &a5);
    //         cout << "ini availability a1 " << a1.getAbilityAvailability() << endl;
    //         cout << "ini availability a5 " << a5.getAbilityAvailability() << endl;
    //     }
    // }
}