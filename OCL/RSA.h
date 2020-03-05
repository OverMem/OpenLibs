#ifndef RSA_H
#define RSA_h

#include "MP/gmp.h"
#include "MP/gmpxx.h"
#include "Random.h"

typedef mpz_class Int;

typedef struct
{
    Int N;
    Int E;
    Int U;

    WORD S;
}KeyRSA;

class MakeRSA
{
public:
    MakeRSA(WORD size = 8192);

    void Gen();
    void GetGen(KeyRSA& key);

private:
    KeyRSA Key;
};

class RSA
{
public:
    RSA(KeyRSA key);

    void Encrypt(Int plain,  Int& cipher);
    void Decrypt(Int cipher, Int& plain);

private:
    KeyRSA Key;
};

#endif // RSA_H

