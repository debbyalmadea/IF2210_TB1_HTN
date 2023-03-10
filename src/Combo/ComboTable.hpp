#ifndef _kombo_
#define _kombo_

#include <vector>
#include <algorithm>
#include <set>
#include <string>

#include "../Card/PermenCard.hpp"
#include "../Card/Valuable.hpp"
#include "./Combo.hpp"

#include <iostream>
#include <array>
#include <string>
using namespace std;

class ComboTable : public Combo
{
protected:
    vector<PermenCard> tableCards;
    vector<PermenCard> handCards;
    vector<PermenCard> totalCards;
    vector<vector<PermenCard>> combinations;
    float MAX_VAL_STRAIGHT_FLUSH = 512.09;

public:
    ComboTable(vector<PermenCard> _tableCard, vector<PermenCard> _handCard)
    {
        tableCards = _tableCard;
        handCards = _handCard;
        totalCards.reserve(_tableCard.size() + _handCard.size());
        totalCards.insert(totalCards.end(), _tableCard.begin(), _tableCard.end());
        totalCards.insert(totalCards.end(), _handCard.begin(), _handCard.end());
        generateCombinations(5);
    };

    vector<Combo> getCombos()
    {
        vector<Combo> combos;
        Combo tableCombo = Combo(tableCards);
        tableCombo.calculateValue();
        for (auto &combination : combinations)
        {
            // If table special case
            if (abs(tableCombo.getValue() - MAX_VAL_STRAIGHT_FLUSH) < 0.001)
            {
                if (combination == tableCards)
                    continue;
                Combo combinationValue = Combo(combination);
                combinationValue.calculateValueSpecial();
                combos.push_back(combinationValue);
            }
            else
            {
                Combo combinationValue = Combo(combination);
                combinationValue.calculateValue();
                combos.push_back(combinationValue);
            }
        }
        return combos;
    }

    void displayCombi()
    {
        cout << combinations.size() << endl;
        for (auto &elem : combinations)
        {
            cout << "Kombinasi kartu: " << endl;
            for (auto &elem2 : elem)
            {
                elem2.printInfo();
            }
            cout << endl;
        }
    }

    void generateCombinations(int n)
    {
        vector<vector<PermenCard>> result;
        int size = totalCards.size();

        // Create a vector of indices
        vector<int> indices(n);
        for (int i = 0; i < n; i++)
        {
            indices[i] = i;
        }
        // Loop through the indices and generate combinations
        while (true)
        {
            vector<PermenCard> combination;
            for (int i = 0; i < n; i++)
            {
                combination.push_back(totalCards[indices[i]]);
            }
            result.push_back(combination);

            // Find the rightmost index that can be incremented
            int i = n - 1;
            while (i >= 0 && indices[i] == size - n + i)
            {
                i--;
            }

            // If there is no such index, we have generated all combinations
            if (i < 0)
            {
                break;
            }

            // Increment the rightmost index that can be incremented
            indices[i]++;
            for (int j = i + 1; j < n; j++)
            {
                indices[j] = indices[j - 1] + 1;
            }
        }

        combinations = result;
    }
};

#endif