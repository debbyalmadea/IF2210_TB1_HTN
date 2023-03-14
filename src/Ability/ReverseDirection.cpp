#include "ReverseDirection.hpp"

ReverseDirection::ReverseDirection() : Ability(4, -1)
{
}
ReverseDirection::ReverseDirection(int _idPemilik) : Ability(4, _idPemilik)
{
}
void ReverseDirection::use(Gamestate &g)
{
    if (available[getIdAbility()] == 0)
    {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu ability REVERSE" << endl;
    }
    else if (available[getIdAbility()] == 1)
    {
        g.getPlayerQueue().reverse();
        cout << "Pemain " << getIdPemilik() << " melakukan reverse!" << endl;
        available[getIdAbility()] = 0;
        // urutan eksekusi next
    }
    else
    {
        cout << "Oops, kartu ability reversemu telah dimatikan sebelumnya :( \n Silahkan lanjutkan perintah lain" << endl;
    }
}