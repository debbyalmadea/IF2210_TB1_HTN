#ifndef EXCEPTIONFILE_HPP
#define EXCEPTIONFILE_HPP

#include "exception.hpp"
using namespace std;

class ExceptionFile : public Exception
{
private:
    string fileName;
    static string message[];

public:
    ExceptionFile(int id, string fileName);
    ExceptionFile(const ExceptionFile &other);
    void print() const;

    string getFileName() const;
};

#endif