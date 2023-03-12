#include "FileReader.hpp"
#include <iostream>

using namespace std;
int main()
{
    FileReader a;
    try
    {
        MainDeck d = a.readBasicCard("tes.txt");
        for (int i = 0; i < d.getSize(); i++)
        {
            d[i].printInfo();
            cout << endl;
        }
    }
    catch (...)
    {
        cout << "err" << endl;
    }
    return 0;
}