#ifndef _kombo_
#define _kombo_

#include <vector>
#include <algorithm>
#include "../Card/PermenCard.hpp"
#include "../Card/Valuable.hpp"
#include <iostream>
using namespace std;

class Combo
{
protected:
    vector<PermenCard> comboCards;

public:
    Combo(vector<PermenCard> _tableCard, vector<PermenCard> _handCard)
    {
        comboCards.reserve(_tableCard.size() + _handCard.size());
        comboCards.insert(comboCards.end(), _tableCard.begin(), _tableCard.end());
        comboCards.insert(comboCards.end(), _handCard.begin(), _handCard.end());
    };

    void display()
    {
        sort(comboCards.begin(), comboCards.end());
        for (auto &elem : comboCards)
        {
            elem.printInfo();
        }
    }

    void evaluate()
    {
        sort(comboCards.begin(), comboCards.end());
    }
};

#endif