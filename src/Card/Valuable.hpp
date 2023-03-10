#ifndef _VALUEABLE_
#define _VALUEABLE_

class Valuable
{
protected:
    float value;

public:
    Valuable() : value(0){};
    Valuable(int _value) : value(_value){};
    float virtual getValue() const = 0;
};

#endif