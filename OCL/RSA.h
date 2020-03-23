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

