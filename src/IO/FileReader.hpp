#ifndef FILEREADER_HPP
#define FILEREADER_HPP
#include <iostream>
#include <fstream>
#include "../Card/PermenCard.hpp"
#include "../Deck/MainDeck.hpp"
#include "../Exception/exceptionFile.hpp"

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

#endif