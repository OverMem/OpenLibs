#include "NumTheoric.h"

bool MillerRabin(Int n, Int k)
{
    Int a;
    std::vector<Int> uses;
    std::vector<Int>::iterator it;
    boost::random::mt19937 mt;
    boost::random::uniform_int_distribution<Int> randr(2, n - 2);

    auto T = [](Int n, Int a) -> bool {
        Int x, s, d = n - 1;

        while((d % 2) == 0)
        {
            s += 1;
            d /= 2;
        }

        x = Pow(a, d, n);
        if(x == 1 || x == n - 1) return false;

        for(Int i = 1; i < s; i += 1)
        {
            x = Pow(x, 2, n);

            if(x == n - 1) return false;
        }

        return true;
    };

    for(Int i = 0; i < k; i += 1)
    {
        do
        {
            a = randr(mt);

            it = std::find(uses.begin(), uses.end(), a);
        }while(it != uses.end());

        uses.push_back(a);

        if(T(n, a)) return false;
    }

    return true;
}

bool isPrime(Int n)
{
    if(n == 1)           return false;
    if(n == 2 || n == 3) return true;
    if((n % 2) == 0)     return false;

    return MillerRabin(n, q_err);
}


Int NextPrime(Int m)
{
    Int nbr = m;

    if((nbr % 2) == 0)
    {
        if(nbr != 2) nbr += 1;
    }

    while(isPrime(nbr) == false) nbr += 2;

    return nbr;
}

