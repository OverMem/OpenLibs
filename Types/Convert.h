#ifndef CONVERT_H
#define CONVERT_H

#include <sstream>
#include "Defines.h"

template<typename T>
T toNbr(std::string Str);
template<typename T>
std::string toStr(T Nbr);


template<typename T>
T ToNbr(std::string Str)
{
    T Nbr;
    std::istringstream i_str;

    i_str.str(Str);
    i_str >> Nbr;

    return Nbr;
}

template<typename T>
std::string toStr(T Nbr)
{
    std::string Str;
    std::ostringstream o_str;

    o_str << Nbr;
    Str = o_str.str();

    return Str;
}

#endif // CONVERT_H

