#include "ExceptionIO.hpp"

ExceptionIO::ExceptionIO(string input) : Exception(0), input(input) {}

void ExceptionIO::print() const
{
    cout << input << " bukan masukan yang valid." << endl;
}