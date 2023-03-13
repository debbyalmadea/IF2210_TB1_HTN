#ifndef _kombo_
#define _kombo_

#include <vector>
#include <algorithm>
#include <set>
#include <string>

#include "../Card/PermenCard.hpp"
#include "../Card/Valuable.hpp"
#include "./Combo.hpp"
#include "../Player/Player.hpp"
#include "../Table/Table.hpp"

#include <iostream>
#include <array>
#include <string>
using namespace std;

class ComboTable : public Combo
{
protected:
    Player player;
    vector<PermenCard> tableCards;
    vector<PermenCard> handCards;
    vector<PermenCard> totalCards;
    vector<vector<PermenCard>> combinations;
    vector<Combo> possibleCombos;
    int MAX_COMBI = 21;

public:
    ComboTable(vector<PermenCard> _tableCard, vector<PermenCard> _handCard, Player _player)
    {
        player = _player;
        tableCards = _tableCard;
        handCards = _handCard;
        totalCards.reserve(_tableCard.size() + _handCard.size());
        totalCards.insert(totalCards.end(), _tableCard.begin(), _tableCard.end());
        totalCards.insert(totalCards.end(), _handCard.begin(), _handCard.end());
        generateCombinations(5);
    };

    ComboTable(Player _player, Table _table)
    {
        player = _player;
        tableCards = _table.getInventory();
        handCards = _player.getInventory();
        totalCards.reserve(tableCards.size() + handCards.size());
        totalCards.insert(totalCards.end(), tableCards.begin(), tableCards.end());
        totalCards.insert(totalCards.end(), handCards.begin(), handCards.end());
        generateCombinations(5);
    };

    Player getPlayer()
    {
        return player;
    }

    vector<Combo> getPossibleCombos()
    {
        return possibleCombos;
    }
    void calculatePossibleCombos()
    {
        for (auto &combination : combinations)
        {
            Combo combinationCalc = Combo(combination);
            combinationCalc.calculateValue();
            possibleCombos.push_back(combinationCalc);
        }
        sort(possibleCombos.begin(), possibleCombos.end());
    }

    void displayCombos()
    {
        cout << "These are the TOP combinations possible for player " << player.getName() << " " << player.getID() << endl;

        int count = 0;
        float prev_val = 0;
        for (auto it = possibleCombos.end() - 1; it != possibleCombos.begin() - 1 && count != 5; it--)
        {
            if (abs(prev_val - it->getValue()) < 0.001)
                continue;
            it->display();
            cout << "Value: " << it->getValue() << " [" << it->getDescription() << "]" << endl
                 << endl;
            count += 1;
            prev_val = it->getValue();
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

    bool operator>(const ComboTable &other) const
    {
        for (int i = MAX_COMBI - 1; i >= 0; i--)
        {
            if (this->possibleCombos[i] == other.possibleCombos[i])
            {
                continue;
            }
            return this->possibleCombos[i] > other.possibleCombos[i];
        }
    };
    bool operator<(const ComboTable &other) const
    {
        for (int i = MAX_COMBI - 1; i >= 0; i--)
        {
            if (this->possibleCombos[i] == other.possibleCombos[i])
            {
                continue;
            }
            return this->possibleCombos[i] < other.possibleCombos[i];
        }
    };
};

#endif