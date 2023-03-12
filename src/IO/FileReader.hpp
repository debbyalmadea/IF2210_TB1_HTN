#ifndef FILEREADER_HPP
#define FILEREADER_HPP
#include <iostream>
#include <fstream>
#include "../Card/PermenCard.hpp"
#include "../Deck/MainDeck.hpp"

using namespace std;

// FILEREADER class
class FileReader
{
private:
    /* data */
    static string configPath;
    vector<string> splitByWhiteSpace(string line);

public:
    MainDeck readBasicCard(string filename);
};

string FileReader::configPath = "config/";

vector<string> FileReader::splitByWhiteSpace(string line)
{
    vector<string> words;
    string word = "";
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == ' ')
        {
            if (word != "")
            {
                words.push_back(word);
                word = "";
            }
        }
        else
        {
            word += line[i];
        }
    }

    if (word != "")
    {
        words.push_back(word);
    }

    return words;
}

MainDeck FileReader::readBasicCard(string filename)
{
    string line;
    vector<PermenCard> permenCards;
    ifstream file(configPath + filename);
    int numOfLines;

    if (!file.is_open())
    {
        throw filename + " not found\n";
    }
    if (file.is_open())
    {
        while (getline(file, line))
        {
            vector<string> words = splitByWhiteSpace(line);
            int value = stoi(words[0]);
            int color = PermenCard::stringToColorInt(words[1]);
            permenCards.push_back(PermenCard(value, color));
            numOfLines++;
        }
    }

    return MainDeck(permenCards);
}

#endif