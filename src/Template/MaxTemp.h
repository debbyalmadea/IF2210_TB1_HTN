#ifndef _template_
#define _template_

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
T max(vector<T> arr)
{
    T maks = arr[0];
    for (T &elem : arr)
    {
        if (elem > maks)
            maks = elem;
    }
    return maks;
}

#endif