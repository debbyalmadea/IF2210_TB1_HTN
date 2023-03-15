#include "PermenCard.hpp"
#include "../Combo/Combo.hpp"
#include "../Combo/ComboTable.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;
int main()
{
     PermenCard baru = PermenCard(2, 2);
     PermenCard baru2 = PermenCard(3, 2);
     PermenCard baru3 = PermenCard(4, 2);
     PermenCard baru4 = PermenCard(5, 2);
     PermenCard baru5 = PermenCard(6, 2);
     vector<PermenCard> tes;
     tes.push_back(baru);
     tes.push_back(baru2);
     tes.push_back(baru3);
     tes.push_back(baru4);
     tes.push_back(baru5);

     baru = PermenCard(5, 3);
     baru2 = PermenCard(5, 3);
     baru3 = PermenCard(5, 3);
     baru4 = PermenCard(9, 3);
     baru5 = PermenCard(13, 3);
     vector<PermenCard>
         tes2;
     tes2.push_back(baru);
     tes2.push_back(baru2);
     tes2.push_back(baru3);
     tes2.push_back(baru4);
     tes2.push_back(baru5);

     Combo kom = Combo(tes);
     kom.display();
     kom.calculateValue();
     // cout << endl
     //      << kom.getDescription() << kom.getValue() << endl;
     // Combo kom2 = Combo(tes2);
     // kom2.display();
     // kom2.calculateValue();
     // cout << endl
     //      << kom2.getDescription() << kom2.getValue() << endl;
     // kom.displayCombi();
     vector<PermenCard> tes3;
     tes3.push_back(PermenCard(6, 3));
     tes3.push_back(PermenCard(13, 2));

     cout << endl
          << endl;
     // Jadi tes2 = table card, tes 3 = hand. combos itu semua kombinasi yang mungkin.
     // Di sort biar kombinasi dengan value paling gede jadi palin belakang.
     ComboTable table = ComboTable(tes2, tes3);
     table.calculatePossibleCombos();
     table.displayCombos();
     vector<PermenCard> tes4;
     tes4.push_back(PermenCard(8, 3));
     tes4.push_back(PermenCard(10, 1));

     cout << endl
          << endl;
     ComboTable table2 = ComboTable(tes2, tes4);
     table2.calculatePossibleCombos();
     table2.displayCombos();
     cout << (table > table2) << endl;
     cout << (table < table2) << endl;
}