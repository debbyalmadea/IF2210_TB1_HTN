#include "PermenCard.hpp"
#include "../Combo/Combo.hpp"
#include <vector>
using namespace std;
int main()
{
    PermenCard baru = PermenCard(12, 2);
    PermenCard baru2 = PermenCard(1, 1);
    PermenCard baru4 = PermenCard(12, 3);
    vector<PermenCard> tes;
    tes.push_back(baru);
    tes.push_back(baru2);
    tes.push_back(baru4);
    vector<PermenCard> tes2;
    tes2.push_back(baru);
    Combo kom = Combo(tes, tes2);
    kom.display();
}