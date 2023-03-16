#ifndef _KOMBO_
#define _KOMBO_

#include <vector>
#include <algorithm>
#include <set>
#include <math.h>

#include "../Card/PermenCard.hpp"
#include "../Card/Valuable.hpp"
#include <iostream>
#include <array>
#include <string>
using namespace std;

class Combo : public Valuable
{
protected:
    vector<PermenCard> comboCards;
    array<vector<PermenCard>, 15> cardsByValue;
    string description;

    void calcHigh()
    {
        description = "HIGH CARD";
        value = comboCards[4].getValue() * 0.1 + comboCards[4].getColor() * 0.03;
    }
    void calcPair()
    {
        int CONST = 5;
        int pair_ind = -1;
        int color = -1;
        for (int i = 0; i < cardsByValue.size(); i++)
        {
            if (cardsByValue[i].size() == 2)
            {
                pair_ind = i;
                color = cardsByValue[i].back().getColor();
            }
        }

        if (pair_ind != -1)
        {
            description = "PAIR";
            value = pair_ind * 0.1 + color * 0.03 + CONST;
        }
    }
    void calcTwoPair()
    {
        int CONST = 10;
        int color = -1;
        int pair_count = 0;
        int pair_ind = -1;

        for (int i = 0; i < cardsByValue.size(); i++)
        {
            if (cardsByValue[i].size() == 2)
            {
                pair_count += 1;
                pair_ind = i;
                color = cardsByValue[i].back().getColor();
            }
        }

        if (pair_count == 2)
        {
            description = "TWO PAIR";
            value = pair_ind * 0.1 + color * 0.03 + CONST;
        }
    }
    void calcThreeOfAKind()
    {
        int CONST = 15;
        int color = -1;
        int pair_ind = -1;

        for (int i = 0; i < cardsByValue.size(); i++)
        {
            if (cardsByValue[i].size() == 3)
            {
                pair_ind = i;
                color = cardsByValue[i].back().getColor();
            }
        }

        if (pair_ind != -1)
        {
            description = "THREE OF A KIND";
            value = pair_ind * 0.1 + color * 0.03 + CONST;
        }
    }
    void calcStraight()
    {
        int CONST = 20;
        int streakCount = 0;
        int streak_ind = -1;
        int color = 0;

        for (int i = 0; i < comboCards.size() - 1; i++)
        {
            if (comboCards[i].getValue() == comboCards[i + 1].getValue() - 1)
            {
                streakCount += 1;
            }
            if (i + 1 == comboCards.size() - 1)
            {
                streak_ind = comboCards[i + 1].getValue();
                color = comboCards[i + 1].getColor();
            }
        }

        if (streakCount == 4)
        {
            description = "STRAIGHT";
            value = streak_ind * 0.1 + color * 0.03 + CONST;
        }
    }
    void calcFlush()
    {
        int CONST = 25;
        int streak = 0;
        int sum = 0;
        for (int i = 0; i < comboCards.size() - 1; i++)
        {
            if (comboCards[i].getColor() == comboCards[i + 1].getColor())
            {
                streak += 1;
                sum += comboCards[i].getValue() * pow(10, i + 1);
            }
            if (i + 1 == comboCards.size() - 1)
            {
                sum += comboCards[i + 1].getValue() * pow(10, i + 2);
            }
        }

        if (streak == 4)
        {
            description = "FLUSH";
            value = sum * 0.000001 + CONST;
        }
    }
    void calcFullHouse()
    {
        int CONST = 30;
        int color = 0;
        int pair = -1;
        int triple = -1;

        for (int i = 0; i < cardsByValue.size(); i++)
        {
            if (cardsByValue[i].size() == 3)
            {
                triple = i;
                for (auto &card : cardsByValue[i])
                {
                    color += card.getColor();
                }
            }
            if (cardsByValue[i].size() == 2)
            {
                pair = i;
            }
        }

        if (pair != -1 && triple != -1)
        {
            description = "FULL HOUSE";
            value = triple * 0.2 + color * 0.01 + CONST;
        }
    }

    void calcFourOfAKind()
    {
        int CONST = 40;
        int index = -1;

        for (int i = 0; i < cardsByValue.size(); i++)
        {
            if (cardsByValue[i].size() == 4)
            {
                index = i;
            }
        }

        if (index != -1)
        {
            description = "FOUR OF A KIND";
            value = index * 0.1 + CONST;
        }
    }

    void calcStraightFlush()
    {
        int CONST = 50;
        int streak = 0;
        int sum = 0;

        for (int i = 0; i < comboCards.size() - 1; i++)
        {
            if (comboCards[i].getColor() == comboCards[i + 1].getColor() && comboCards[i].getValue() == comboCards[i + 1].getValue() - 1)
            {
                streak += 1;
            }
            if (i + 1 == comboCards.size() - 1)
            {
                sum = comboCards[i + 1].getValue();
            }
        }

        if (streak == 4)
        {
            description = "STRAIGHT FLUSH";
            value = sum * 0.1 + CONST;
        }
    }

public:
    Combo()
    {
    }
    Combo(vector<PermenCard> _fiveCards)
    {
        comboCards = _fiveCards;
    };

    void display()
    {
        for (auto &elem : comboCards)
        {
            elem.printInfo();
        }
    }

    float getValue() const
    {
        return value;
    }

    void calculateValue()
    {
        sort(comboCards.begin(), comboCards.end());
        // Masukin keranjang
        for (auto &card : comboCards)
        {
            cardsByValue[card.getValue()].push_back(card);
        }
        calcHigh();
        calcPair();
        calcTwoPair();
        calcThreeOfAKind();
        calcStraight();
        calcFlush();
        calcFullHouse();
        calcFourOfAKind();
        calcStraightFlush();
    }
    void calculateValueSpecial()
    {
        sort(comboCards.begin(), comboCards.end());
        // Masukin keranjang
        for (auto &card : comboCards)
        {
            cardsByValue[card.getValue()].push_back(card);
        }
        calcHigh();
        calcPair();
        calcTwoPair();
        calcThreeOfAKind();
    }
    string getDescription()
    {
        return description;
    }

    bool operator<(const Combo &other) const
    {
        return this->getValue() < other.getValue();
    };
    bool operator>(const Combo &other) const
    {
        return this->getValue() > other.getValue();
    };
    bool operator==(const Combo &other) const
    {
        return abs(this->getValue() - other.getValue()) < 0.001;
    };
};

#endif