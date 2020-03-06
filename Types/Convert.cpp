#include "Convert.h"

/*!
 * @brief Get num value of char
 *
 * Function for get the number value of a character represented in any base format.
 *
 * @param[in] c : character to decode
 * @return number value
 */
int nval(const char c)
{
    if(c >= '0' && c <= '9') return c - '0';
    else                     return c - 'A' + 10;
}

