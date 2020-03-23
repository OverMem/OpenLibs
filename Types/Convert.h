/*
Copyright © 2020 Nicolle Rémi

This file is part of OpenLibs.

OpenLibs is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

OpenLibs is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with OpenLibs.  If not, see <https://www.gnu.org/licenses/>.
*/

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
    const char* temp_s = Str.c_str();

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

