#ifndef CONVERT_H
#define CONVERT_H

#include "Defines.h"

int nval(const char c);

template<typename T>
T toNbr(std::string Str, BYTE base = 10);
template<typename T>
std::string toStr(T Nbr, BYTE base = 10);

template<typename T>
T toNbr(std::string Str, BYTE base)
{
    int Len = Str.length();
    T Power = 1;
    T Nbr   = 0;

    for(int i = Len - 1; i >= 0; i--)
    {
        Nbr   += nval(temp_s[i]) * Power;
        Power *= base;
    }

    return Nbr;
}

template<typename T>
std::string toStr(T Nbr, BYTE base)
{
    std::string Str;
    int digit;

    do
    {
        digit = Nbr % base;
        Str   = std::to_string(digit) + Str;
        Nbr   = (Nbr - digit) / base;
    }while(Nbr != 0);

    return Str;
}

#endif // CONVERT_H

