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
        throw ExceptionFile(0, filename);
    }
    if (file.is_open())
    {
        while (getline(file, line))
        {
            try
            {
                vector<string> words = splitByWhiteSpace(line);
                int value = stoi(words[0]);
                int color = PermenCard::stringToColorInt(words[1]);
                if (color == -1)
                {
                    throw invalid_argument("Invalid color");
                }
                permenCards.push_back(PermenCard(value, color));
                numOfLines++;
            }
            catch (invalid_argument &err)
            {
                throw ExceptionFile(1, filename);
            }
        }
    }
    // !TODO: card not enough exception
    file.close();
    return MainDeck(permenCards);
}
