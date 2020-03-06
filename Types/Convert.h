#ifndef CONVERT_H
#define CONVERT_H

/*!
 * @file Convert.h
 * @brief Convert functions (string => types)
 * @author RemsPrgm
 * @version 1.0
 */
#include "Defines.h"

int nval(const char c);

template<typename T>
T toNbr(std::string Str, BYTE base = 10);
template<typename T>
std::string toStr(T Nbr, BYTE base = 10);

/*!
 * @fn T toNbr(std::string Str, BYTE base)
 * @brief Convert string to number
 *
 * Function for convert a string in any base format to number.
 *
 * @param[in] Str  : string to convert
 * @param[in] base : base repr of string
 * @return number converted
 */
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

/*!
 * @fn std::string toStr(T Nbr, BYTE base)
 * @brief Convert number to string
 *
 * Function for convert a number to string in any base format.
 *
 * @param[in] Nbr  : nbr to convert
 * @param[in] base : base repr of string
 * @return string converted
 */
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

