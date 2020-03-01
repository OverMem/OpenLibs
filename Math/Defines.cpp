#include "Defines.h"

Int operator<<(const Int& a, const Int& b)
{
    int nbr;
    Int ret;

    if(b > 4294967295) ret = 0;
    else
    {
        nbr = static_cast<int>(b);
        ret = a << nbr;
    }

    return ret;
}

Int operator>>(const Int& a, const Int& b)
{
    int nbr;
    Int ret;

    if(b > 4294967295) ret = 0;
    else
    {
        nbr = static_cast<int>(b);
        ret = a >> nbr;
    }

    return ret;
}


Int& operator<<=(Int& a, const Int& b)
{
    a = a << b;

    return a;
}

Int& operator>>=(Int& a, const Int& b)
{
    a = a >> b;

    return a;
}

