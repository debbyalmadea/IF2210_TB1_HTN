#ifndef EXCEPTIONCARD_HPP
#define EXCEPTIONCARD_HPP

#include "exception.hpp"
using namespace std;

class ExceptionCard : public Exception
{
    private:
        string cardName;
        static string message[];


    public:
        ExceptionCard(int id, string cardName);
        ExceptionCard (const ExceptionCard& other);
        void print() const;

        string getCardName() const;
        
};


#endif