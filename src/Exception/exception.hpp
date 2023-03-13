#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
#include <string> 
#include <exception>

using namespace std;

class Exception
{
    protected:
        const int ID;

    public:
        Exception(int id) : ID(id) {};
        Exception (const Exception& other) : ID(other.ID) {};
        virtual void print() const = 0;

        int getID() const { return ID; }

};

#endif