#include "FileReader.hpp"

string FileReader::configPath = "../../config/";

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
    int numOfLines = 0;

    if (!file.is_open())
    {
        // !TODO: file not found exception
        throw filename + " not found\n";
    }
    if (file.is_open())
    {
        while (getline(file, line))
        {
            vector<string> words = splitByWhiteSpace(line);
            // !TODO: non int exception
            int value = stoi(words[0]);
            // !TODO: color not found exception
            int color = PermenCard::stringToColorInt(words[1]);
            permenCards.push_back(PermenCard(value, color));
            numOfLines++;
        }
    }
    // !TODO: card not enough exception
    file.close();
    return MainDeck(permenCards);
}
