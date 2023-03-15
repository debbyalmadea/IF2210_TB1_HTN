#ifndef CONSOLEINPUT_HPP
#define CONSOLEINPUT_HPP

#include <iostream>
#include "../Exception/ExceptionIO.hpp"
#include <vector>

using namespace std;

class ConsoleInput
{
private:
    string input;

public:
    string getInput()
    {
        return input;
    }
    string getInputCLI()
    {
        cout << ">> ";
        cin >> input;
        return input;
    }
    int getInputInt(int min, int max)
    {
        while (input == "")
        {
            getInputCLI();
            try
            {
                if (stoi(input) < min || stoi(input) > max)
                {
                    throw ExceptionIO(input);
                }
            }
            catch (Exception &err)
            {
                err.print();
                clearInput();
            }
            catch (invalid_argument &err)
            {
                cout << input << " bukan masukan yang valid." << endl;
                clearInput();
            }
        }
        return stoi(input);
    }

    int getInputInt(int min, int max, vector<int> except)
    {
        while (input == "")
        {
            getInputCLI();
            try
            {
                if (stoi(input) < min || stoi(input) > max)
                {
                    throw ExceptionIO(input);
                }

                if (find(except.begin(), except.end(), stoi(input)) != except.end())
                {
                    throw ExceptionIO(input);
                }
            }
            catch (Exception &err)
            {
                err.print();
                clearInput();
            }
            catch (invalid_argument &err)
            {
                cout << input << " bukan masukan yang valid." << endl;
                clearInput();
            }
        }
        return stoi(input);
    }
    void clearInput()
    {
        input = "";
    }
};

#endif