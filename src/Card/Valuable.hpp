#ifndef _VALUEABLE_
#define _VALUEABLE_

class Valuable
{
protected:
    int value;

public:
    Valuable(int _value) : value(_value){};
    int virtual getValue() const = 0;
};

#endif