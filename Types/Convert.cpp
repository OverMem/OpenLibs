#include "Convert.h"

int nval(const char c)
{
    if(c >= '0' && c <= '9') return c - '0';
    else                     return c - 'A' + 10;
}

