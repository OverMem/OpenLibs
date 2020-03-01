#include "Algorithm.h"

Int Pow(Int b, Int e)
{
    Int ret, B = b, E = e;

    if(E == 0)      ret = 1;
    else if(E == 1) ret = B;
    else if((E % 2) == 0)
    {
        B *= b;
        E /= 2;

        ret = Pow(B, E);
    }
    else
    {
        B *= b;
        E = (E - 1) / 2;

        ret = b * Pow(B, E);
    }

    return ret;
}

Int Pow(Int b, Int e, Int m)
{
    Int B = b, E = e, M = m;
    Int ret;

    while(E > 0)
    {
        if((E & 1) > 0) ret = (ret * B) % M;
        E >>= 1;
        B = (B * B) % M;
    }

    return ret;
}


Int Euclide(Int a, Int b)
{
    Int r, A = a, B = b;

    while(b != 0)
    {
        r = B;
        B = A % B;
        A = r;
    }

    return A;
}

Int Euclide(Int a, Int b, Int& u, Int& v)
{
    Int r = a, rr = b, U = 1, V = 0, UU = 0, VV = 1;
    Int q, rs, us, vs;

    while(rr != 0)
    {
        q = r / rr;

        rs = r;
        us = U;
        vs = V;

        r = rr;
        U = UU;
        V = VV;

        rr = rs - (q * rr);
        UU = us - (q * UU);
        VV = vs - (q * VV);
    }

    u = U;
    v = V;

    return r;
}

Int Euclide(Int a, Int b, Int& u, Int Min, Int Max)
{
    Int v, U, pgcd, k;

    pgcd = Euclide(a, b, U, v);

    if(U < Min)
    {
        k = ((Min - U) / (-b)) - 1;

        U = U - (k * b);
    }

    if(U > Max)
    {
        k = ((Min - U) / (-b)) + 1;

        U = U - (k * b);
    }

    u = U;

    return pgcd;
}

