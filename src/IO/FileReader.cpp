#include "FileReader.hpp"

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
    int numOfLines = 0;

    if (!file.is_open())
    {
        throw ExceptionFile(0, filename);
    }
    if (file.is_open())
    {
        try
        {
            while (getline(file, line))
            {
                vector<string> words = splitByWhiteSpace(line);
                if (words.size() != 2)
                {
                    throw invalid_argument("Words on line do not match");
                }
                int value = stoi(words[0]);
                int color = PermenCard::stringToColorInt(words[1]);
                if (color == -1)
                {
                    throw invalid_argument("Invalid color");
                }
                permenCards.push_back(PermenCard(value, color));
                numOfLines++;
            }
        }
        catch (invalid_argument &err)
        {
            throw ExceptionFile(1, filename);
        }

        if (numOfLines != 52)
        {
            throw ExceptionFile(2, filename);
        }
    }
    file.close();
    return MainDeck(permenCards);
}
