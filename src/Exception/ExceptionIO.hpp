#ifndef EXCEPTIONIO_HPP
#define EXCEPTIONIO_HPP

#include "exception.hpp"

class ExceptionIO : public Exception
{
private:
    string input;

public:
    ExceptionIO(string input);
    void print() const;
};

#endif