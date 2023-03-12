#include "Ability.hpp"
#include "Abilityless.hpp"
#include "Ability.cpp"

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int com;
    Abilityless a1(1);
    Ability a2(1, 5, false);
    Ability a3(2, 0, false);
    Ability a4(3, 6, false);
    Ability a5(4, 2, false);
    Ability a6(5, 3, false);
    Ability a7(6, 4, false);

    a2.setAbilityAvailability(false);
    a3.setAbilityAvailability(false);
    a4.setAbilityAvailability(false);
    a5.setAbilityAvailability(false);
    a6.setAbilityAvailability(false);
    a7.setAbilityAvailability(false);
    // PAKAI COMMAND BUAT
    cout << "Enter ur command : ";
    cin >> com;
    cout << com << endl;

    // mula -mula
    cout << "MULA-MULA" << endl;
    cout << "ini availability a1 " << a1.getAbilityAvailability() << endl;
    cout << "ini availability a5 " << a5.getAbilityAvailability() << endl;
    if (com == 1)
    {
        if (a1.hasUsedAllAbility())
        {
            cout << "Eits, ternyata semua pemain sudah memakai kartu kemampuan. Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Yah, pengunaan kartu ini sia-sia" << endl;
            a1.setAbilityAvailability(false);
            a1.setDeadStatus(true);
        }
        else
        {
            a1.use(0, &a5);
            cout << "ini availability a1 " << a1.getAbilityAvailability() << endl;
            cout << "ini availability a5 " << a5.getAbilityAvailability() << endl;
        }
    }
}